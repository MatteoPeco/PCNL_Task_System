#include <math.h>
#include <pluginlib/class_list_macros.h>
#include <kdl_conversions/kdl_msg.h>
#include <tf_conversions/tf_kdl.h>
#include "lwr_controllers/cartesian_impedance_controller.h"

#include <kdl_parser/kdl_parser.hpp> //added 5.11
#include <kdl/jntarrayacc.hpp> //added 5.11
//#include <joint_command_interface.h>	//29.9.22

////////	ADDED 5.22 - start
#include <lwr_controllers/computed_torque_controller.h>
#include <vector>
#include <iostream>
#include "std_msgs/Float32MultiArray.h"
#include "std_msgs/Float64MultiArray.h"
using namespace std;
////////	ADDED 5.22 - end

namespace lwr_controllers
{
    CartesianImpedanceController::CartesianImpedanceController() : cur_T_FRI_(12) {}
    CartesianImpedanceController::~CartesianImpedanceController() {}

    bool CartesianImpedanceController::init(hardware_interface::PositionCartesianInterface *robot, ros::NodeHandle &n)
    {
        ROS_INFO("THIS CONTROLLER USES THE TCP INFORMATION SET ON THE FRI SIDE... SO BE SURE YOU KNOW WHAT YOU ARE DOING!");

        if (!ros::param::search(n.getNamespace(),"robot_name", robot_namespace_))
        {
            ROS_WARN_STREAM("CartesianImpedanceController: No robot name found on parameter server ("<<n.getNamespace()<<"/robot_name), using the namespace...");
            robot_namespace_ = n.getNamespace();
            //return false;
        }
        if (!n.getParam("robot_name", robot_namespace_))
        {
            ROS_WARN_STREAM("CartesianImpedanceController: Could not read robot name from parameter server ("<<n.getNamespace()<<"/robot_name), using the namespace...");
            robot_namespace_ = n.getNamespace();
            //return false;
        }
        if (!n.getParam("root_name", root_name_))
        {
            ROS_WARN_STREAM("CartesianImpedanceController: Could not read robot root name from parameter server ("<<n.getNamespace()<<"/root_name). Considering it to be equal to #BASE as defined in the KRC!!!");
            root_name_ = robot_namespace_ + "_base_link";
        }
        else
        {
            tf::TransformListener listener;
            tf::StampedTransform transform;
            listener.waitForTransform(robot_namespace_ + "_base_link", root_name_, ros::Time::now(), ros::Duration(1.0));
            try{
                listener.lookupTransform( robot_namespace_ + "_base_link", root_name_,  ros::Time(0), transform);
            }
            catch (tf::TransformException ex){
                ROS_ERROR_STREAM("CartesianImpedanceController: Could not read transform from "<< robot_namespace_ << "_base_link to " << root_name_ << ": " << ex.what());
                return false;
            }

            tf::poseTFToKDL(tf::Transform(transform.getRotation(), transform.getOrigin()), robotBase_controllerBase_);
        }
        if (n.getParam("tip_name", tip_name_))
        {
            ROS_WARN_STREAM("CartesianImpedanceController: robot tip name is " << tip_name_ << ". In this controller it is ignored. Using tip name defined in #TOOL in the KRC!!!");
        }
        if (n.getParam("publish_cartesian_pose", publish_cartesian_pose_) && publish_cartesian_pose_)
        {
            ROS_WARN_STREAM("Publishing the cartesian position of the robot tip (the #TOOL defined in the KRC!!!)");
        }

        joint_names_.push_back( robot_namespace_ + std::string("_a1_joint") );
        joint_names_.push_back( robot_namespace_ + std::string("_a2_joint") );
        joint_names_.push_back( robot_namespace_ + std::string("_e1_joint") );
        joint_names_.push_back( robot_namespace_ + std::string("_a3_joint") );
        joint_names_.push_back( robot_namespace_ + std::string("_a4_joint") );
        joint_names_.push_back( robot_namespace_ + std::string("_a5_joint") );
        joint_names_.push_back( robot_namespace_ + std::string("_a6_joint") );
        cart_12_names_.push_back( robot_namespace_ + std::string("_rot_xx") );
        cart_12_names_.push_back( robot_namespace_ + std::string("_rot_yx") );
        cart_12_names_.push_back( robot_namespace_ + std::string("_rot_zx") );
        cart_12_names_.push_back( robot_namespace_ + std::string("_pos_x") );
        cart_12_names_.push_back( robot_namespace_ + std::string("_rot_xy") );
        cart_12_names_.push_back( robot_namespace_ + std::string("_rot_yy") );
        cart_12_names_.push_back( robot_namespace_ + std::string("_rot_zy") );
        cart_12_names_.push_back( robot_namespace_ + std::string("_pos_y") );
        cart_12_names_.push_back( robot_namespace_ + std::string("_rot_xz") );
        cart_12_names_.push_back( robot_namespace_ + std::string("_rot_yz") );
        cart_12_names_.push_back( robot_namespace_ + std::string("_rot_zz") );
        cart_12_names_.push_back( robot_namespace_ + std::string("_pos_z") );
        cart_6_names_.push_back( robot_namespace_ + std::string("_X") );
        cart_6_names_.push_back( robot_namespace_ + std::string("_Y") );
        cart_6_names_.push_back( robot_namespace_ + std::string("_Z") );
        cart_6_names_.push_back( robot_namespace_ + std::string("_A") );
        cart_6_names_.push_back( robot_namespace_ + std::string("_B") );
        cart_6_names_.push_back( robot_namespace_ + std::string("_C") );

        // now get all handles, 12 for cart pos, 6 for stiff, 6 for damp, 6 for wrench, 6 for joints
        for(int c = 0; c < 30; ++c)
        {
            if(c < 12)
                cart_handles_.push_back(robot->getHandle(cart_12_names_.at(c)));
            if(c > 11 && c < 18)
                cart_handles_.push_back(robot->getHandle(cart_6_names_.at(c-12) + std::string("_stiffness")));
            if(c > 17 && c < 24)
                cart_handles_.push_back(robot->getHandle(cart_6_names_.at(c-18) + std::string("_damping")));
            if(c > 23 && c < 30)
                cart_handles_.push_back(robot->getHandle(cart_6_names_.at(c-24) + std::string("_wrench")));
        }

        for(int j = 0; j < 7; ++j) //j = 6 modified 2022.05.11
        {
           joint_handles_.push_back(robot->getHandle(joint_names_.at(j)));
        }

////////	ADDED 5.22 - start
        // Get URDF and name of root and tip from the parameter server
        std::string robot_description, root_name, tip_name;

        if (!ros::param::search(n.getNamespace(),"robot_description", robot_description))
        {
            ROS_ERROR_STREAM("KinematicChainControllerBase: No robot description (URDF) found on parameter server ("<<n.getNamespace()<<"/robot_description)");
            return false;
        }

        if (!n.getParam("root_name", root_name))
        {
            ROS_ERROR_STREAM("KinematicChainControllerBase: No root name found on parameter server ("<<n.getNamespace()<<"/root_name)");
            return false;
        }

        if (!n.getParam("tip_name", tip_name))
        {
            ROS_ERROR_STREAM("KinematicChainControllerBase: No tip name found on parameter server ("<<n.getNamespace()<<"/tip_name)");
            return false;
        }
        // Construct an URDF model from the xml string
        std::string xml_string;

        if (n.hasParam(robot_description))
            n.getParam(robot_description.c_str(), xml_string);
        else
        {
            ROS_ERROR("Parameter %s not set, shutting down node...", robot_description.c_str());
            n.shutdown();
            return false;
        }

        if (xml_string.size() == 0)
        {
            ROS_ERROR("Unable to load robot model from parameter %s",robot_description.c_str());
            n.shutdown();
            return false;
        }

        ROS_DEBUG("%s content\n%s", robot_description.c_str(), xml_string.c_str());

        // Get urdf model out of robot_description
        urdf::Model model;
        if (!model.initString(xml_string))
        {
            ROS_ERROR("Failed to parse urdf file");
            n.shutdown();
            return false;
        }
        ROS_INFO("Successfully parsed urdf file");
        KDL::Tree kdl_tree_;
        if (!kdl_parser::treeFromUrdfModel(model, kdl_tree_))
        {
            ROS_ERROR("Failed to construct kdl tree");
            n.shutdown();
            return false;
        }
	// Populate the KDL chain
        if(!kdl_tree_.getChain(root_name, tip_name, kdl_chain_))
        {
            ROS_ERROR_STREAM("Failed to get KDL chain from tree: ");
            ROS_ERROR_STREAM("  "<<root_name<<" --> "<<tip_name);
            ROS_ERROR_STREAM("  Tree has "<<kdl_tree_.getNrOfJoints()<<" joints");
            ROS_ERROR_STREAM("  Tree has "<<kdl_tree_.getNrOfSegments()<<" segments");
            ROS_ERROR_STREAM("  The segments are:");

            KDL::SegmentMap segment_map = kdl_tree_.getSegments();
            KDL::SegmentMap::iterator it;

            for( it=segment_map.begin(); it != segment_map.end(); it++ )
              ROS_ERROR_STREAM( "    "<<(*it).first);

            return false;
        }

	gravity_ = KDL::Vector::Zero();
        gravity_(2) = -9.81;

	// Resize joint states, inertia matrix, jacobian, solvers and joints torque
	joint_msr_states_.resize(kdl_chain_.getNrOfJoints()); // kdl_chain_.getNrOfJoints() = 7
	joint_des_states_.resize(kdl_chain_.getNrOfJoints());
	M_.resize(kdl_chain_.getNrOfJoints());
	id_solver_.reset( new KDL::ChainDynParam( kdl_chain_, gravity_) );
	J_.resize(kdl_chain_.getNrOfJoints());
	jac_solver_.reset(new KDL::ChainJntToJacSolver(kdl_chain_));

	tau_des_.resize(kdl_chain_.getNrOfJoints());

	for (size_t i = 0; i < joint_handles_.size(); i++){
		tau_des_(i) = joint_handles_[i].getPosition();

		ROS_INFO("tau_des_[%zu]:%f", i, tau_des_(i));
	}

	// ROS publishers and subscribers
	pub_M_ = n.advertise<std_msgs::Float32MultiArray>("/inertia_matrix", 10);
	pub_J_ = n.advertise<std_msgs::Float32MultiArray>("/jacobian_matrix", 10);

//	sub_add_torque_ = n.subscribe(n.resolveName("add_torque"), 1, &CartesianImpedanceController::add_torque, this);
	typedef  const std_msgs::Float64MultiArray::ConstPtr& msg_type;
	sub_add_torque_ = n.subscribe<CartesianImpedanceController, msg_type>("additional_torque", 1, boost::bind(&CartesianImpedanceController::setParam, this, _1, &tau_des_, "AddTorque")); // EDIT 29.9

////////	ADDED 5.22 - end

        sub_command_ = n.subscribe(n.resolveName("command"), 1, &CartesianImpedanceController::command, this);
        srv_command_ = n.advertiseService("set_command", &CartesianImpedanceController::command_cb, this);
        sub_ft_measures_ = n.subscribe(n.resolveName("ft_measures"), 1, &CartesianImpedanceController::updateFT, this);
        pub_goal_ = n.advertise<geometry_msgs::PoseStamped>(n.resolveName("goal"),0);
        if (publish_cartesian_pose_)
        {
            realtime_pose_pub_.reset(new realtime_tools::RealtimePublisher<geometry_msgs::PoseStamped>(n, "cartesian_pose", 4));
        }

        // // may be needed, to set initial commands asap
        // starting(ros::Time::now());

        return true;
    }

    void CartesianImpedanceController::starting(const ros::Time& time)
    {
        getCurrentPose(x_ref_);
        x_des_ = x_ref_;

        // Initial Cartesian stiffness
        KDL::Stiffness k( 2000.0, 2000.0, 50.0, 50.0, 50.0, 50.0 ); // 800,50
        k_des_ = k;

        // Initial Cartesian damping
        KDL::Stiffness d( 0.8, 0.8, 0.8, 0.8, 0.8, 0.8 );
        d_des_ = d;

        // Initial force/torque measure
        KDL::Wrench w(KDL::Vector(0.0, 0.0, 0.0), KDL::Vector(0.0, 0.0, 0.0));
        f_des_ = w;

        // forward initial commands to hwi
        forwardCmdFRI(x_des_);

////////	ADDED 5.22 - start
        // get joint positions
  	for(size_t i=0; i<joint_handles_.size(); i++){
//  		ROS_INFO("%lu",joint_handles_.size());
		joint_msr_states_.q(i) = joint_handles_[i].getPosition();
   		joint_msr_states_.qdot(i) = joint_handles_[i].getVelocity();
    		joint_msr_states_.qdotdot(i) = 0.0;

    		//	Inizializing ext torque
    		tau_des_(i) = 0.0;
    	}
    	lambda = 0.1;	// lower values: flatter
    	cmd_flag_ = 0;
    	step_ = 0;
////////	ADDED 5.22 - end

    }

    void CartesianImpedanceController::command(const lwr_controllers::CartesianImpedancePoint::ConstPtr &msg)
    {

        // Validate command, for now, only check non-zero of stiffness, damping, and orientation


        // Compute a KDL frame out of the message
        tf::poseMsgToKDL( msg->x_FRI, x_des_ );
        // Pre-multiply the pose to make sure it is expressed in the correct frame
        x_des_ = robotBase_controllerBase_ * x_des_;

        // Convert Wrench msg to KDL wrench
        tf::wrenchMsgToKDL( msg->f_FRI, f_des_ );

        // Convert from Stiffness msg array to KDL stiffness
        //if(!(msg->k_FRI.x + msg->k_FRI.y + msg->k_FRI.z + msg->k_FRI.rx + msg->k_FRI.ry + msg->k_FRI.rz == 0.0))
        //{
            ROS_INFO("Updating Stiffness command");
            KDL::Stiffness k( msg->k_FRI.x, msg->k_FRI.y, msg->k_FRI.z, msg->k_FRI.rx, msg->k_FRI.ry, msg->k_FRI.rz );
            k_des_ = k;

            ROS_INFO("Updating Damping command");
            KDL::Stiffness d( msg->d_FRI.x, msg->d_FRI.y, msg->d_FRI.z, msg->d_FRI.rx, msg->d_FRI.ry, msg->d_FRI.rz );
            d_des_ = d;
        //}

        // publish goal
        geometry_msgs::PoseStamped goal;
        goal.header = msg->header;
        goal.pose = msg->x_FRI;
        pub_goal_.publish(goal);

    }

////////	ADDED 5.22: retrieve the tau_msg_ from null_space_controller
/*   void CartesianImpedanceController::add_torque(const std_msgs::Float64MultiArray::ConstPtr &tau_msg_){
   	for (size_t i = 0; i < joint_handles_.size(); i++) {
		tau_des_(i) = tau_msg_->data[i];
//		tau_des_(i) = 0.5;
//		ROS_INFO("tau_des_[%zu]:%f", i, tau_des_(i));
//		ROS_INFO("tau_msg_[%zu]:%f", i, tau_msg_->data[i]);
	}
    } */
////////	ADDED 5.22

    bool CartesianImpedanceController::command_cb(SetCartesianImpedanceCommand::Request &req, SetCartesianImpedanceCommand::Response &res)
    {
        return true;
    }

    void CartesianImpedanceController::updateFT(const geometry_msgs::WrenchStamped::ConstPtr &msg)
    {
        // Convert Wrench msg to KDL wrench
        geometry_msgs::Wrench f_meas = msg->wrench;
        tf::wrenchMsgToKDL( f_meas, f_cur_);
    }

    void CartesianImpedanceController::update(const ros::Time& time, const ros::Duration& period)
    {

////////	ADDED May, 2022 - start
//TODO: * JOINT ORDER; a1, a2, e1, a3, a4, a5, a6; > OK
//	* remove the 2 double arrays

	id_solver_->JntToMass(joint_msr_states_.q, M_);
//	jac_solver_->JntToJac(joint_msr_states_.q, J_, -1);
	jac_solver_->JntToJac(joint_msr_states_.q, J_);

	//Fill a double array with Inertia Matrix (to be published)
    	for (int a=0; a<7; a++){
    		for (int b=0; b<7; b++){
    			InertiaMatrix[a][b] = M_.operator() (a, b);
    		}
    	}

    	//Fill a double array with Jacobian (to be published)
    	for (int a=0; a<6; a++){
    		for (int b=0; b<7; b++){
    			JacobianMatrix[a][b] = J_.operator() (a, b);
    		}
    	}

    	for (int k=0; k<6; k++){
		for (int l=0; l<7; l++){
			cout << JacobianMatrix[k][l] << "|";
	}
	cout<<"\n";
	}

    	// Fill the Intertia Matrix msg
	msg_M_.layout.dim.push_back(std_msgs::MultiArrayDimension());
	msg_M_.layout.dim.push_back(std_msgs::MultiArrayDimension());
	msg_M_.layout.dim[0].label = "height";
	msg_M_.layout.dim[0].size = 7;
	msg_M_.layout.dim[0].stride = 7*7;
	msg_M_.layout.dim[1].label = "width";
	msg_M_.layout.dim[1].size = 7;
	msg_M_.layout.dim[1].stride = 7;
	msg_M_.layout.data_offset = 0;
	std::vector<float> vec_M_(7*7, 0);
	for (int a=0; a<7; a++)
		for (int b=0; b<7; b++)
			vec_M_[a*7 + b] = InertiaMatrix[a][b];
		msg_M_.data = vec_M_;

	// Fill the Jacobian Matrix msg
	msg_J_.layout.dim.push_back(std_msgs::MultiArrayDimension());
	msg_J_.layout.dim.push_back(std_msgs::MultiArrayDimension());
	msg_J_.layout.dim[0].label = "height";
	msg_J_.layout.dim[0].size = 6; //H
	msg_J_.layout.dim[0].stride = 6*7; //H*W
	msg_J_.layout.dim[1].label = "width";
	msg_J_.layout.dim[1].size = 7; //W
	msg_J_.layout.dim[1].stride = 7; //W
	msg_J_.layout.data_offset = 0;
	std::vector<float> vec_J_(7*6, 0); //vec(W*H, 0)
	for (int a=0; a<6; a++)
		for (int b=0; b<7; b++)
			vec_J_[a*7 + b] = JacobianMatrix[a][b]; //vec[i*W + j]
		msg_J_.data = vec_J_;

	// Publish Inertia and Jacobian Matrices
	pub_M_.publish(msg_M_);
	pub_J_.publish(msg_J_);

	// Check dimensions of Inertia and Jacobian matrices
/*
	ROS_INFO("n. of rows Inertia Mat: %u", M_.rows());
	ROS_INFO("n. of columns Inertia Mat: %u", M_.columns());
	ROS_INFO("n. of rows Jac: %u", J_.rows());
  	ROS_INFO("n. of columns Jac: %u", J_.columns());
*/

////////	SET COMMAND for additional torque on joints
	for (size_t i = 0; i < joint_handles_.size(); i++){
		//tau_des_(i)=10.0;
		//joint_handles_[i].setCommand(tau_des_(i));	// to be verified if this works
		//ROS_INFO("getCommand: %s", joint_handles_[i].getName().c_str());
		//ROS_INFO("stateHandle: %f %f %f", joint_handles_[i].JointStateHandle());
//		ROS_INFO("tau_des_[%zu]:%f", i, tau_des_(i));	// VERIFIED 28.9.22
//		ROS_INFO("joint msr states velocity: %f", joint_msr_states_.qdot(i));	//EDIT 7.9.22
	}


////////	ADDED May, 2022 - end

        // get current values
        // std::cout << "Update current values" << std::endl;
        getCurrentPose(x_cur_);

        if (publish_cartesian_pose_)
        {
            publishCurrentPose(x_cur_);
        }

        // forward commands to hwi
        // std::cout << "Before forwarding the command" << std::endl;
        forwardCmdFRI(x_des_);
    }

//	ADDED 29.9
	void CartesianImpedanceController::setParam(const std_msgs::Float64MultiArray_< std::allocator< void > >::ConstPtr& msg, KDL::JntArray* array, std::string s){
    	if (msg->data.size() == joint_handles_.size()){
        	for (unsigned int i = 0; i < joint_handles_.size(); ++i){
            		(*array)(i) = msg->data[i];
        	}
    	}
    	else{
        	ROS_INFO("Num of Joint handles = %lu", joint_handles_.size());
    	}

    	ROS_INFO("Num of Joint handles = %lu, dimension of message = %lu", joint_handles_.size(), msg->data.size());

    	ROS_INFO("New param %s: %.2lf, %.2lf, %.2lf %.2lf, %.2lf, %.2lf, %.2lf", s.c_str(),
             	(*array)(0), (*array)(1), (*array)(2), (*array)(3), (*array)(4), (*array)(5), (*array)(6));
	}
//	ADDED 29.9

    void CartesianImpedanceController::stopping(const ros::Time& time)
    {

    }

    void CartesianImpedanceController::multiplyJacobian(const KDL::Jacobian& jac, const KDL::Wrench& src, KDL::JntArray& dest)
    {
        Eigen::Matrix<double,6,1> w;
        w(0) = src.force(0);
        w(1) = src.force(1);
        w(2) = src.force(2);
        w(3) = src.torque(0);
        w(4) = src.torque(1);
        w(5) = src.torque(2);

        Eigen::MatrixXd j(jac.rows(), jac.columns());
        j = jac.data;
        j.transposeInPlace();

        ROS_INFO("Jac"); //added
        Eigen::VectorXd t(jac.columns());
        t = j*w;

        dest.resize(jac.columns());
        for (unsigned i=0; i<jac.columns(); i++)
        dest(i) = t(i);
    }

    void CartesianImpedanceController::fromKDLtoFRI(const KDL::Frame& in, std::vector<double>& out)
    {
        assert(out.size() == 12);
        out[0] = in.M.UnitX().x();
        out[1] = in.M.UnitY().x();
        out[2] = in.M.UnitZ().x();
        out[3] = in.p.x();
        out[4] = in.M.UnitX().y();
        out[5] = in.M.UnitY().y();
        out[6] = in.M.UnitZ().y();
        out[7] = in.p.y();
        out[8] = in.M.UnitX().z();
        out[9] = in.M.UnitY().z();
        out[10] = in.M.UnitZ().z();
        out[11] = in.p.z();

    }

    void CartesianImpedanceController::fromKDLtoFRI(const KDL::Stiffness& in, std::vector<double>& out)
    {
        assert(out.size() == 6);
        for( int d = 0; d < 6; ++d)
        {
            out[d] = in[d];
        }
    }

    void CartesianImpedanceController::fromKDLtoFRI(const KDL::Wrench& in, std::vector<double>& out)
    {
        assert(out.size() == 6);
        out[0] = in.force.x();
        out[1] = in.force.y();
        out[2] = in.force.z();
        out[3] = in.torque.x();
        out[4] = in.torque.y();
        out[5] = in.torque.z();
    }

    void CartesianImpedanceController::fromFRItoKDL(const std::vector<double>& in, KDL::Frame& out)
    {
        assert(in.size() == 12);
        KDL::Rotation R(in[0], in[1], in[2], in[4], in[5], in[6], in[8], in[9], in[10]);
        KDL::Vector p(in[3], in[7], in[11]);
        KDL::Frame T(R, p);
        out = T;
    }

    void CartesianImpedanceController::fromFRItoKDL(const std::vector<double>& in, KDL::Stiffness& out)
    {
        assert(in.size() == 6);
        KDL::Stiffness s(in[0], in[1], in[2], in[3], in[4], in[5]);
        out = s;
    }

    void CartesianImpedanceController::fromFRItoKDL(const std::vector<double>& in, KDL::Wrench& out)
    {
        assert(in.size() == 6);
        KDL::Wrench w(KDL::Vector(in[0], in[1], in[2]), KDL::Vector(in[3], in[4], in[5]));
        out = w;
    }

    void CartesianImpedanceController::forwardCmdFRI(const KDL::Frame& f)
    {
        fromKDLtoFRI(f, cur_T_FRI_);
        for(int c = 0; c < 30; ++c)
        {
            if(c < 12)
                cart_handles_.at(c).setCommand(cur_T_FRI_[c]);
            else if(c < 18)
                cart_handles_.at(c).setCommand(k_des_[c-12]);
            else if(c < 24)
                cart_handles_.at(c).setCommand(d_des_[c-18]);
            else if(c < 30)
                cart_handles_.at(c).setCommand(f_des_[c-24]);
        }

    }

    void CartesianImpedanceController::getCurrentPose(KDL::Frame& f)
    {
        KDL::Rotation cur_R(cart_handles_.at(0).getPosition(),
                            cart_handles_.at(1).getPosition(),
                            cart_handles_.at(2).getPosition(),
                            cart_handles_.at(4).getPosition(),
                            cart_handles_.at(5).getPosition(),
                            cart_handles_.at(6).getPosition(),
                            cart_handles_.at(8).getPosition(),
                            cart_handles_.at(9).getPosition(),
                            cart_handles_.at(10).getPosition());
        KDL::Vector cur_p(cart_handles_.at(3).getPosition(),
                          cart_handles_.at(7).getPosition(),
                          cart_handles_.at(11).getPosition());
        f = KDL::Frame( cur_R, cur_p );
    }

    void CartesianImpedanceController::publishCurrentPose(const KDL::Frame& f)
    {
        if (realtime_pose_pub_->trylock()) {
            realtime_pose_pub_->msg_.header.stamp = ros::Time::now();
            tf::poseKDLToMsg(f, realtime_pose_pub_->msg_.pose);
            realtime_pose_pub_->unlockAndPublish();
        }
    }

}

PLUGINLIB_EXPORT_CLASS(lwr_controllers::CartesianImpedanceController, controller_interface::ControllerBase)
