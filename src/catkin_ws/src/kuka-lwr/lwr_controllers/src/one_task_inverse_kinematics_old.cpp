#include <iostream>
#include <lwr_controllers/one_task_inverse_kinematics.h>
#include <utils/pseudo_inversion.h>
#include <utils/skew_symmetric.h>

#include <pluginlib/class_list_macros.h>
#include <kdl_parser/kdl_parser.hpp>
#include <Eigen/LU>

#include <math.h>
#include <ros/ros.h>

int des_flag=1;

namespace lwr_controllers 
{
    OneTaskInverseKinematics::OneTaskInverseKinematics() {}
    OneTaskInverseKinematics::~OneTaskInverseKinematics() {}
 
    bool OneTaskInverseKinematics::init(hardware_interface::PositionJointInterface *robot, ros::NodeHandle &n)
    {
        if( !(KinematicChainControllerBase<hardware_interface::PositionJointInterface>::init(robot, n)) )
        {
            ROS_ERROR("Couldn't initilize OneTaskInverseKinematics controller.");
            return false;
        }

        jnt_to_jac_solver_.reset(new KDL::ChainJntToJacSolver(kdl_chain_));
        fk_pos_solver_.reset(new KDL::ChainFkSolverPos_recursive(kdl_chain_));
        ik_vel_solver_.reset(new KDL::ChainIkSolverVel_pinv(kdl_chain_));
        ik_pos_solver_.reset(new KDL::ChainIkSolverPos_NR_JL(kdl_chain_,joint_limits_.min,joint_limits_.max,*fk_pos_solver_,*ik_vel_solver_));

        q_cmd_.resize(kdl_chain_.getNrOfJoints());
        J_.resize(kdl_chain_.getNrOfJoints());

        // get joint positions
        for(int i=0; i < joint_handles_.size(); i++)
        {
            joint_msr_states_.q(i) = joint_handles_[i].getPosition();
            joint_msr_states_.qdot(i) = joint_handles_[i].getVelocity();
            joint_des_states_.q(i) = joint_msr_states_.q(i);
        }

        // computing forward kinematics
        fk_pos_solver_->JntToCart(joint_msr_states_.q, x_);

        //Desired posture is the current one
        x_des_ = x_;
        float tool_length;
        tool_length=0.22;
        float init_tip[]={};
        init_tip[0]=x_des_.M(0,2)*tool_length+x_des_.p[0];
        init_tip[1]=x_des_.M(1,2)*tool_length+x_des_.p[1];
        init_tip[2]=x_des_.M(2,2)*tool_length+x_des_.p[2];
        ROS_INFO("Init position: %lf,%lf,%lf", x_des_.p[0],x_des_.p[1],x_des_.p[2]);
        ROS_INFO("Init X_axis: %lf,%lf,%lf", x_des_.M(0,0),x_des_.M(1,0),x_des_.M(2,0));
        ROS_INFO("Init Y_axis: %lf,%lf,%lf", x_des_.M(0,1),x_des_.M(1,1),x_des_.M(2,1));
        ROS_INFO("Init Z_axis: %lf,%lf,%lf", x_des_.M(0,2),x_des_.M(1,2),x_des_.M(2,2));

        cmd_flag_ = 0;

        
        sub_command_ = nh_.subscribe("command", 1, &OneTaskInverseKinematics::command, this);

        return true;
    }

    void OneTaskInverseKinematics::starting(const ros::Time& time)
    {

    }

    void OneTaskInverseKinematics::update(const ros::Time& time, const ros::Duration& period)
    {

        // get joint positions
        for(int i=0; i < joint_handles_.size(); i++)
        {
            joint_msr_states_.q(i) = joint_handles_[i].getPosition();
        }

        if (cmd_flag_)
        {
            // computing Jacobian
            jnt_to_jac_solver_->JntToJac(joint_msr_states_.q, J_);

            // computing J_pinv_
            pseudo_inverse(J_.data, J_pinv_);

            // computing forward kinematics
            fk_pos_solver_->JntToCart(joint_msr_states_.q, x_);


            
            KDL::Frame x_des_new;
            x_des_new=x_des_;
            float tool_length;
            tool_length=0.22;
            float des_tip[]={};
            des_tip[0]=x_des_.M(0,2)*tool_length;
            des_tip[1]=x_des_.M(1,2)*tool_length;
            des_tip[2]=x_des_.M(2,2)*tool_length;
            x_des_new.p[0]=x_des_.p[0]-des_tip[0];
            x_des_new.p[1]=x_des_.p[1]-des_tip[1];
            x_des_new.p[2]=x_des_.p[2]-des_tip[2];
            
            x_des_new.M.GetRPY(goal_orientation(0),goal_orientation(1),goal_orientation(2));
            
            //ROS_INFO("Goal position: %lf,%lf,%lf,%lf", x_des_new.p[0]+des_tip[0],x_des_new.p[1]+des_tip[1],x_des_new.p[2]+des_tip[2],period.toSec());
            //ROS_INFO("Goal Orientation: %lf,%lf,%lf", goal_orientation[0],goal_orientation[1],goal_orientation[2]);
            
            // end-effector position error
            x_err_.vel = x_des_new.p - x_.p;

            // getting quaternion from rotation matrix
            x_.M.GetQuaternion(quat_curr_.v(0),quat_curr_.v(1),quat_curr_.v(2),quat_curr_.a);
            x_des_new.M.GetQuaternion(quat_des_.v(0),quat_des_.v(1),quat_des_.v(2),quat_des_.a);

            skew_symmetric(quat_des_.v, skew_);

            for (int i = 0; i < skew_.rows(); i++)
            {
                v_temp_(i) = 0.0;
                for (int k = 0; k < skew_.cols(); k++)
                    v_temp_(i) += skew_(i,k)*(quat_curr_.v(k));
            }

            // end-effector orientation error
            x_err_.rot = quat_curr_.a*quat_des_.v - quat_des_.a*quat_curr_.v - v_temp_;

            // computing q_dot
            for (int i = 0; i < J_pinv_.rows(); i++)
            {
                joint_des_states_.qdot(i) = 0.0;
                for (int k = 0; k < J_pinv_.cols(); k++)
                    joint_des_states_.qdot(i) += J_pinv_(i,k)*x_err_(k); //removed scaling factor of .7
          
            }

            // integrating q_dot -> getting q (Euler method)
            for (int i = 0; i < joint_handles_.size(); i++)
                //joint_des_states_.q(i) += period.toSec()*joint_des_states_.qdot(i);
                joint_des_states_.q(i) += 0.01*joint_des_states_.qdot(i);

            // joint limits saturation
            for (int i =0;  i < joint_handles_.size(); i++)
            {
                if (joint_des_states_.q(i) < joint_limits_.min(i))
                    joint_des_states_.q(i) = joint_limits_.min(i);
                if (joint_des_states_.q(i) > joint_limits_.max(i))
                    joint_des_states_.q(i) = joint_limits_.max(i);
            }
            x_.M.GetRPY(end_orientation(0),end_orientation(1),end_orientation(2));
            //ROS_INFO("END position: %lf,%lf,%lf", x_.p[0]+x_.M(0,2)*tool_length,x_.p[1]+x_.M(1,2)*tool_length,x_.p[2]+x_.M(2,2)*tool_length);
            //ROS_INFO("END orientation: %lf,%lf,%lf", end_orientation(0),end_orientation(1),end_orientation(2));                            
            if (Equal(x_, x_des_new, 0.05))
            {
                x_.M.GetRPY(end_orientation(0),end_orientation(1),end_orientation(2));
                ROS_INFO("On target");
                ROS_INFO("END position: %lf,%lf,%lf", x_.p[0]+x_.M(0,2)*tool_length,x_.p[1]+x_.M(1,2)*tool_length,x_.p[2]+x_.M(2,2)*tool_length);
                ROS_INFO("END orientation: %lf,%lf,%lf", end_orientation(0),end_orientation(1),end_orientation(2));               
                cmd_flag_ = 0;
            }
        }

        // set controls for joints
        for (int i = 0; i < joint_handles_.size(); i++)
        {
            joint_handles_[i].setCommand(joint_des_states_.q(i));
        }
    }

    void OneTaskInverseKinematics::command(const lwr_controllers::PoseRPY::ConstPtr &msg)
    {
        KDL::Frame frame_des_;

        switch(msg->id)
        {
            case 0:
            frame_des_ = KDL::Frame(
                    KDL::Rotation::RPY(msg->orientation.roll,
                                      msg->orientation.pitch,
                                      msg->orientation.yaw),
                    KDL::Vector(msg->position.x,
                                msg->position.y,
                                msg->position.z));
            break;

            case 1: // position only
            frame_des_ = KDL::Frame(
                KDL::Vector(msg->position.x,
                            msg->position.y,
                            msg->position.z));
            break;

            case 2: // orientation only
            frame_des_ = KDL::Frame(
                KDL::Rotation::RPY(msg->orientation.roll,
                                   msg->orientation.pitch,
                                   msg->orientation.yaw));
            break;

            default:
            ROS_INFO("Wrong message ID");
            return;
        }

        x_des_ = frame_des_;
        cmd_flag_ = 1;
    }
}

PLUGINLIB_EXPORT_CLASS(lwr_controllers::OneTaskInverseKinematics, controller_interface::ControllerBase)
