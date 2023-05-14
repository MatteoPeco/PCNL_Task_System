#ifndef LWR_CONTROLLERS__JOINT_INPEDANCE_CONTROLLER_H
#define LWR_CONTROLLERS__JOINT_INPEDANCE_CONTROLLER_H

#include "KinematicChainControllerBase.h"

#include <visualization_msgs/Marker.h>
#include <std_msgs/Float64MultiArray.h>

#include <boost/scoped_ptr.hpp>

#include <std_msgs/Float32MultiArray.h>	// To publish J_ and M_

// To subscribe external torques from ArmState Controller
#include "lwr_controllers/ArmState.h"
#include <vector>
/*
	tau_cmd_ = K_*(q_des_ - q_msr_) + D_*dotq_msr_ + G(q_msr_)

*/

namespace lwr_controllers
{

	class JointImpedanceController: public controller_interface::KinematicChainControllerBase<hardware_interface::EffortJointInterface>
	{
	public:

		JointImpedanceController();
		~JointImpedanceController();

		bool init(hardware_interface::EffortJointInterface *robot, ros::NodeHandle &n);

		void starting(const ros::Time& time);

		void update(const ros::Time& time, const ros::Duration& period);
		void command(const std_msgs::Float64MultiArray::ConstPtr &msg);
		void setParam(const std_msgs::Float64MultiArray::ConstPtr &msg, KDL::JntArray* array, std::string s);
		
		void extTorque(const lwr_controllers::ArmState::ConstPtr &ft_msg);
        
	private:

		ros::Subscriber sub_stiffness_, sub_damping_, sub_add_torque_;
		ros::Subscriber sub_posture_;

		KDL::JntArray q_des_;
		KDL::JntArray tau_des_;
		KDL::JntArray K_, D_;
		
//		ADDED 10.22
		KDL::JntArray tau_;
		KDL::JntArray tau_N_;	//Null space additional torque
		KDL::JntArray tau_d_;	//desired tau = tau_task + tau_null_space
		KDL::JntArray q_start_;	
		KDL::JntArray G_;	//Gravity
		KDL::JntArray C_;	//Coriolis
		
		KDL::Jacobian J_;	//Jacobian
		KDL::JntSpaceInertiaMatrix M_; //Inertia Matrix
		
		Eigen::MatrixXd N_ =  Eigen::MatrixXd(7,7);
		
		vector<float> tau_ext_;
		//KDL::JntArray tau_ext_;
		
		//	Jacobian Matrix	
		Eigen::MatrixXd J_Eigen_ =  Eigen::MatrixXd(6,7);
		Eigen::MatrixXd J_pinv =  Eigen::MatrixXd(7,6);
		Eigen::MatrixXd J_transpose =  Eigen::MatrixXd(7,6);
		Eigen::MatrixXd J_transpose_pinv =  Eigen::MatrixXd(6,7);


		//	Inertia Matrix
		Eigen::MatrixXd M_Eigen_ =  Eigen::MatrixXd(7,7);
		Eigen::MatrixXd M_pinv =  Eigen::MatrixXd(7,7);
		Eigen::MatrixXd M_transpose =  Eigen::MatrixXd(7,7);
		Eigen::MatrixXd M_transpose_pinv =  Eigen::MatrixXd(7,7);
		
		//	Identity Matrix
		MatrixXd I_ = MatrixXd::Identity(7, 7);
			
		// For cartesian to joint space conversion
		KDL::JntArray CartesianForces;
		KDL::Frame x_des_;  	 //desired cart pose
        	KDL::Frame x_meas_;  	 //measured cart pose (from direct kinematics)
        	KDL::Frame x_meas_old_;  //measured cart pose 

		Eigen::Matrix<double,7,1> q0_;

		KDL::JntArray K_joint, D_joint;
		KDL::JntArray K_cart, D_cart; 
		       
		// Solvers
		boost::scoped_ptr<KDL::ChainJntToJacSolver> jnt_to_jac_solver_;
        	boost::scoped_ptr<KDL::ChainDynParam> id_solver_;
        	boost::scoped_ptr<KDL::ChainFkSolverPos_recursive> fk_pos_solver_;
        	
        	// ROS Subscriber for external torques
		
		ros::Subscriber sub_ft_;
        	
//		ADDED 10.22		

	};

} // namespace

#endif
