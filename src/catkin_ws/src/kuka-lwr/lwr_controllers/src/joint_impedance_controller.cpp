#include <angles/angles.h>
#include <pluginlib/class_list_macros.h>
#include <algorithm>
#include <kdl/tree.hpp>
#include <kdl/chainfksolvervel_recursive.hpp>
#include <kdl_parser/kdl_parser.hpp>
#include <urdf/model.h>

//	include null space projector header files
#include <utils/pseudo_inverse.h>
#include <utils/matrix_multiplication.h>
#include <utils/null_space_projector.h>

//	for debug
#include <ros/console.h>

#include <lwr_controllers/joint_impedance_controller.h>

namespace lwr_controllers {

JointImpedanceController::JointImpedanceController() {}

JointImpedanceController::~JointImpedanceController() {}

bool JointImpedanceController::init(hardware_interface::EffortJointInterface *robot, ros::NodeHandle &n)
{
    KinematicChainControllerBase<hardware_interface::EffortJointInterface>::init(robot, n);
    K_.resize(kdl_chain_.getNrOfJoints());
    D_.resize(kdl_chain_.getNrOfJoints());   
    q_des_.resize(kdl_chain_.getNrOfJoints());
    tau_des_.resize(kdl_chain_.getNrOfJoints());
//	ADDED 10.22 -->
    K_joint.resize(kdl_chain_.getNrOfJoints());
    D_joint.resize(kdl_chain_.getNrOfJoints());
	q_start_.resize(kdl_chain_.getNrOfJoints());
	tau_.resize(kdl_chain_.getNrOfJoints());
    tau_N_.resize(kdl_chain_.getNrOfJoints());
    tau_d_.resize(kdl_chain_.getNrOfJoints());
    
    tau_ext_.resize(kdl_chain_.getNrOfJoints());

//	Set joint stiffness, damping (put to zero to delete null space additional torque)   
    K_joint(0) = 20.0;
    K_joint(1) = 20.0;
    K_joint(2) = 20.0;
    K_joint(3) = 20.0;
    K_joint(4) = 20.0;
    K_joint(5) = 20.0;
    K_joint(6) = 20.0;
    
    D_joint(0) = 10.0;
    D_joint(1) = 10.0;
    D_joint(2) = 10.0;
    D_joint(3) = 10.0;
    D_joint(4) = 10.0;
    D_joint(5) = 10.0;
    D_joint(6) = 10.0;
    
//	Set  cartesian stiffness
    K_cart.resize(6);
    K_cart(0) = 3000.0;
    K_cart(1) = 3000.0;
    K_cart(2) = 3000.0;
    K_cart(3) = 200.0;
    K_cart(4) = 200.0;
    K_cart(5) = 200.0;
    
//	Set cartesian damping
    D_cart.resize(6);
    D_cart(0) = 150.0;
    D_cart(1) = 150.0;
    D_cart(2) = 150.0;
    D_cart(3) = 30.0;
    D_cart(4) = 30.0;
    D_cart(5) = 30.0;
//	ADDED 10.22 <--
    
	for (size_t i = 0; i < joint_handles_.size(); i++){	
        K_(i) = joint_stiffness_handles_[i].getPosition();
        D_(i) = joint_damping_handles_[i].getPosition();
        q_des_(i) = joint_set_point_handles_[i].getPosition();
        tau_des_(i) = joint_handles_[i].getPosition();
//	ADDED 10.22 -->    
        q_start_(i) = joint_handles_[i].getPosition();
        tau_(i) = joint_handles_[i].getEffort();
        
        CartesianForces.resize(6);
        
        J_.resize(kdl_chain_.getNrOfJoints());
		M_.resize(kdl_chain_.getNrOfJoints());
		
		id_solver_.reset(new KDL::ChainDynParam(kdl_chain_,gravity_));
		fk_pos_solver_.reset(new KDL::ChainFkSolverPos_recursive(kdl_chain_));
		jnt_to_jac_solver_.reset(new KDL::ChainJntToJacSolver(kdl_chain_));
	
//	ADDED 10.22 <--
	}

    ROS_DEBUG(" Number of joints in handle = %lu", joint_handles_.size() );

    for (int i = 0; i < joint_handles_.size(); ++i) {
        if ( !nh_.getParam("stiffness_gains", K_(i) ) ) {
            ROS_WARN("Stiffness gain not set in yaml file, Using %f", K_(i));
        }
    }
    for (int i = 0; i < joint_handles_.size(); ++i) {
        if ( !nh_.getParam("damping_gains", D_(i)) ) {
            ROS_WARN("Damping gain not set in yaml file, Using %f", D_(i));
        }
    }

    typedef  const std_msgs::Float64MultiArray::ConstPtr& msg_type;
    sub_stiffness_ = nh_.subscribe<JointImpedanceController, msg_type>("stiffness", 1, boost::bind(&JointImpedanceController::setParam, this, _1, &K_, "K"));
    sub_damping_ = nh_.subscribe<JointImpedanceController, msg_type>("damping", 1, boost::bind(&JointImpedanceController::setParam, this, _1, &D_, "D"));
    sub_add_torque_ = nh_.subscribe<JointImpedanceController, msg_type>("additional_torque", 1, boost::bind(&JointImpedanceController::setParam, this, _1, &tau_des_, "AddTorque"));    
    sub_posture_ = nh_.subscribe("command", 1, &JointImpedanceController::command, this);  
    
//	Subscribe to arm_state_controller for estimated external torque (ADDED 10.22)
    sub_ft_ = nh_.subscribe("/lwr/arm_state_controller/arm_state", 1, &JointImpedanceController::extTorque, this);   

    return true;

}

void JointImpedanceController::starting(const ros::Time& time)
{
//	Initializing stiffness, damping, ext_torque and set point values
    for (size_t i = 0; i < joint_handles_.size(); i++) {
    	q_des_(i) = joint_handles_[i].getPosition();
        tau_des_(i) = 0.0;
        
//	This is joint torque to get the robot to desired position
        tau_(i) = joint_handles_[i].getEffort();	//	ADDED 4.10.22
        tau_N_(i) = 0.0;
        tau_d_(i) = 0.0;
        tau_ext_[i] = 0.0;
    }
    
//	ADDED 10.22 -->  
    for (size_t i = 0; i < joint_handles_.size(); i++){
    	joint_msr_states_.q(i) = joint_handles_[i].getPosition();
    	joint_msr_states_.qdot(i) = joint_handles_[i].getVelocity();
    }
    
//	Joints initial positions 
    q0_ = q_start_.data;
    
//	Forward kinematics from x to q 
    fk_pos_solver_->JntToCart(joint_msr_states_.q,x_des_);
    fk_pos_solver_->JntToCart(joint_msr_states_.q,x_meas_);
    fk_pos_solver_->JntToCart(joint_msr_states_.q,x_meas_old_);
    
//	ADDED 10.22 <--
	
}

//	ADDED 10.22 -->
	void JointImpedanceController::extTorque(const lwr_controllers::ArmState::ConstPtr& ft_msg) {
		tau_ext_ = ft_msg->est_ext_torques;	
		
		for(size_t i = 0; i < joint_handles_.size(); i++) {
//			ROS_INFO_STREAM(" tau_ext_(" << i << ") = " << tau_ext_[i]);
			
		}
		
	}
//	ADDED 10.22 <--

void JointImpedanceController::update(const ros::Time& time, const ros::Duration& period)
{

//	JOINT ORDER of joint_msr_states: [lwr_a1_joint, lwr_a2_joint, lwr_e1_joint, lwr_a3_joint, lwr_a4_joint, lwr_a5_joint, lwr_a6_joint]

//	ADDED 10.22 -->   
    for (int i = 0; i < joint_handles_.size(); i++){
    	joint_msr_states_.q(i) = joint_handles_[i].getPosition();
    	joint_msr_states_.qdot(i) = joint_handles_[i].getVelocity();
    	//ROS_INFO("q start(%d): %f", i, q_start_(i));
    }
    
//	Compute Jacobian and Inertia matrix from KDL
    jnt_to_jac_solver_->JntToJac(joint_msr_states_.q,J_);
    id_solver_->JntToMass(joint_msr_states_.q, M_);
  
//	Compute current cartesian position
	fk_pos_solver_->JntToCart(joint_msr_states_.q,x_meas_);

//	Compute cartesian forces to convert the main task from cartesian to the joint space
	for(int i = 0; i < 6; i++) {
		if(i<3){
			CartesianForces(i) = K_cart(i)*(x_des_.p(i) - x_meas_.p(i)) - D_cart(i)*(x_meas_.p(i) - x_meas_old_.p(i))/period.toSec();
//			ROS_INFO_STREAM(" x_des_(" << i << ") = " << x_des_.p(i));
//			ROS_INFO_STREAM(" x_meas_(" << i << ") = " << x_meas_.p(i));
//			ROS_INFO_STREAM("Update Cartesian error: " << (x_des_.p(i) - x_meas_.p(i)) << " x_des_.p(i) " << x_des_.p(i) << " x_meas_.p(i) " <<  x_meas_.p(i));
        }
        else{
			CartesianForces(i) = 0.0;	//	position only.
        }
	}

//	Convert J_ and M_ to Eigen::Matrix to apply transposition and pseudo inversion
	for (int k=0; k<6; ++k){
		for (int l=0; l<7; ++l){
			J_Eigen_(k,l) = J_.operator() (k, l);
		}
	}

	for (int k=0; k<7; ++k){
		for (int l=0; l<7; ++l){
			M_Eigen_(k,l) = M_.operator() (k, l);
		}
	}

//	Old implementation of null space projector 
/*
//	J transpose 
	J_transpose = J_Eigen_.transpose();
//	M pseudo-inverse (SVD)
	PseudoInverse(M_Eigen_, M_pinv, true);

	N_ = NullSpaceProjector(J_Eigen_, J_transpose, M_pinv);
*/

	//	Null Space Projector using Eigen functions
	N_ = I_ - J_Eigen_.transpose() * (M_Eigen_.inverse() * J_Eigen_.transpose() * (J_Eigen_ * M_Eigen_.inverse() * J_Eigen_.transpose()).inverse()).transpose();

/*	
	for (int k=0; k<7; k++){
		for (int l=0; l<7; l++){
			cout << N_.coeff(k,l) << "|";
		}
		cout<<"\n";
	}
*/

	
//	Task (desired position) torque
	for(size_t i = 0; i < joint_handles_.size(); i++) {
		tau_(i) = 0.0;
		for(size_t j = 0; j < 6; j++) {
			tau_(i) += J_(j,i)*CartesianForces(j);                                       
		}
		//ROS_INFO_STREAM(" tau_(" << i << ") = " << tau_(i));
	}
	

//	Null-space torque	
	for(size_t i = 0; i < joint_handles_.size(); i++) {
		tau_N_(i) = 0.0;
		for(size_t j = 0; j < joint_handles_.size(); j++) {
			tau_N_(i) += N_.coeff(i,j)*(K_joint(j)*(q_start_(j)-joint_msr_states_.q(j)) - D_joint(j)*joint_msr_states_.qdot(j));
		}
		//ROS_INFO_STREAM(" tau_N_(" << i << ") = " << tau_N_(i));
	}
	
	
//	Total desired torque = task torque + null-space torque - estimated external torque
	for(size_t i = 0; i < joint_handles_.size(); i++) {
		//tau_d_(i) = tau_(i) + tau_N_(i) - tau_ext_[i];
		tau_d_(i) = tau_(i) + tau_N_(i);
		ROS_INFO_STREAM(" joint_effort_(" << i << ") = " << joint_handles_[i].getEffort());
		ROS_INFO_STREAM(" tau_d_(" << i << ") = " << tau_d_(i));
	}
    
//	ADDED 10.22 <--

//	Compute control law. This controller sets all variables for the JointImpedance Interface from kuka
    for (size_t i = 0; i < joint_handles_.size(); i++)
    {
//		joint_handles_[i].setCommand(tau_des_(i));
		joint_handles_[i].setCommand(tau_d_(i));
        joint_stiffness_handles_[i].setCommand(K_(i));
        joint_damping_handles_[i].setCommand(D_(i));
		joint_set_point_handles_[i].setCommand(q_des_(i));
//		joint_set_point_handles_[i].setCommand(q_start_(i));	//???
    }
    
    x_meas_old_ = x_meas_;

}

void JointImpedanceController::command(const std_msgs::Float64MultiArray::ConstPtr &msg) {
/*
//	THIS IS THE ORIGINAL JOINT IMPEDANCE CONTROLLER 
    if (msg->data.size() == 0) {
        ROS_INFO("Desired configuration must be: %lu dimension", joint_handles_.size());
    }
    else if ((int)msg->data.size() != joint_handles_.size()) {
        ROS_ERROR("Posture message had the wrong size: %d", (int)msg->data.size());
        return;
    }
    else
    {
        for (unsigned int j = 0; j < joint_handles_.size(); ++j)
            q_des_(j) = msg->data[j];
    }
*/ 
//	THIS IS MODIFIED (10.22)
    if (msg->data.size() == 0) {
        ROS_INFO("Desired configuration must be: %lu or 6 dimension ", joint_handles_.size());
        }
    else if ( (int)msg->data.size() != joint_handles_.size() && (int)msg->data.size() != 6 ){
        ROS_ERROR("Posture message had the wrong size: %d", (int)msg->data.size());
        return;
        }
//	If the message published on joint_impedance_controller/command is in joint space (data_size is 7: joint angles) >> put the message inside q_des_ (joint desired configuration)
    else if ( (int)msg->data.size() == joint_handles_.size() ){
            for (unsigned int j = 0; j < joint_handles_.size(); j++)
                q_des_(j) = msg->data[j];
                ROS_INFO("Getting joint angles");
        }
//	If the message published on joint_impedance_controller/command is in cartesian space (data_size is 6: XYZRPY) >> put the message inside x_des_ (cartesian desired configuration)            
    else if  ( (int)msg->data.size() == 6 ){
            for (unsigned int j = 0; j < 3; j++)
                x_des_.p(j) = msg->data[j];
                ROS_INFO("Getting cartesian position");
    }

}

void JointImpedanceController::setParam(const std_msgs::Float64MultiArray_< std::allocator< void > >::ConstPtr& msg, KDL::JntArray* array, std::string s)
{
    if (msg->data.size() == joint_handles_.size())
    {
        for (unsigned int i = 0; i < joint_handles_.size(); ++i)
        {
            (*array)(i) = msg->data[i];
        }
    }
    else
    {
        ROS_INFO("Num of Joint handles = %lu", joint_handles_.size());
    }

    ROS_INFO("Num of Joint handles = %lu, dimension of message = %lu", joint_handles_.size(), msg->data.size());

    ROS_INFO("New param %s: %.2lf, %.2lf, %.2lf %.2lf, %.2lf, %.2lf, %.2lf", s.c_str(),
             (*array)(0), (*array)(1), (*array)(2), (*array)(3), (*array)(4), (*array)(5), (*array)(6));
}

} // namespace

PLUGINLIB_EXPORT_CLASS( lwr_controllers::JointImpedanceController, controller_interface::ControllerBase)
