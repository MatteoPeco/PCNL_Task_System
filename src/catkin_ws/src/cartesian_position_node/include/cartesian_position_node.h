#include "sensor_msgs/JointState.h"
#include "lwr_controllers/PoseRPY.h"
#include "lwr_controllers/RPY.h"
#include "geometry_msgs/Twist.h"
//#include "geometry_msgs/Vector3.h"
#include "ros/ros.h"
#include <ros/node_handle.h>
#include <string>
#include <kdl/tree.hpp>
#include <kdl/kdl.hpp>
#include <kdl/chain.hpp>
#include <kdl/frames.hpp>
#include "forward_kinematics.h"
#include <control_msgs/JointControllerState.h> 
#include <kdl_parser/kdl_parser.hpp>
#include <kdl/jntarray.hpp>
//#include <kdl/jointarrayvel.hpp>
#ifndef CARTESIAN_POSITION_NODE
#define CARTESIAN_POSITION_NODE
#include <vector>
#include <algorithm>
#include <iostream>


void reorder(std::vector<double>& vA, std::vector<size_t>& vI)  
{
size_t i, j, k;
    for(i = 0; i < vA.size(); i++){ 
        while(i != (j = vI[i])){
            k = vI[j];
            std::swap(vA[j], vA[k]);
            std::swap(vI[i], vI[j]);
        }
    }
}


class CartesianPositionNode{


public:
	CartesianPositionNode(ros::NodeHandle& n, std::string subname): fk_(){
		tt_pub_ = n.advertise<lwr_controllers::PoseRPY>("/cartesian_position/pose/tooltip",10);
		ee_pub_ = n.advertise<lwr_controllers::PoseRPY>("/cartesian_position/pose/end_effector",10);	
		tt_vel_pub_ = n.advertise<geometry_msgs::Twist>("/cartesian_position/vel/tooltip",10);
		ee_vel_pub_ = n.advertise<geometry_msgs::Twist>("/cartesian_position/vel/end_effector",10);	
		sub_ = n.subscribe(subname, 10, &CartesianPositionNode::callback, this);

		fk_.init(n);


	}

	void callback(const sensor_msgs::JointState::ConstPtr& msg)
	{
		
		KDL::JntArray q(msg->position.size());
		KDL::JntArray q_dot(msg->velocity.size());
		KDL::Frame x;
		std::vector<double> x_dot(6,1);
		std::vector<double> js;
		std::vector<double> js_dot;
		std::vector<size_t> order{0,1,6,2,3,4,5};
		for (int i=0; i<msg->position.size();i++){
			js.push_back(msg->position[i]);
			js_dot.push_back(msg->velocity[i]);
		}
		reorder(js,order);
		reorder(js_dot,order);
		for (int i=0; i<js.size();i++){
			q(i) = js[i];
			q_dot(i) = js_dot[i];
		}
		float tool_length;
		tool_length=0.275;
		// tool_length=0.33; //0.275

		float d1 = 0.4; 
		float d2 = 0.39; 
		float d3 = tool_length+0.078; 
		float d4 = 0.078;


		fk_.compute(q,x);


//		fk_.computeVel(q,q_dot,x_dot,d1,d2,d4);


		pose_.position.x = x.p.x();
		pose_.position.y = x.p.y();
		pose_.position.z = x.p.z();
		x.M.GetRPY(pose_.orientation.roll,pose_.orientation.pitch, pose_.orientation.yaw);
/*		vel_.linear.x = x_dot.at(0);
		vel_.linear.y = x_dot.at(1);
		vel_.linear.z = x_dot.at(2);
		vel_.angular.x = x_dot.at(3);
		vel_.angular.y = x_dot.at(4);
		vel_.angular.z = x_dot.at(5);
*/
			

		ee_pub_.publish(pose_);
//		ee_vel_pub_.publish(vel_);

		float tip[3];
		tip[0]=x.M(0,2)*tool_length;
		tip[1]=x.M(1,2)*tool_length;
		tip[2]=x.M(2,2)*tool_length;
		std::cout << tip[0]<< " "<<tip[1]<< " "<<tip[2]<<std::endl;
		x.p[0]=x.p[0]+tip[0];
		x.p[1]=x.p[1]+tip[1];
		x.p[2]=x.p[2]+tip[2];
		std::cout << x.p[0]<< " "<<x.p[1]<< " "<<x.p[2]<<std::endl<<std::endl;
		std::cout << tip[0]<< " "<<tip[1]<< " "<<tip[2]<<std::endl<<std::endl;
		pose_.position.x = x.p.x();
		pose_.position.y = x.p.y();
		pose_.position.z = x.p.z();

		fk_.computeVel(q,q_dot,x_dot,d1,d2,d3);



		vel_.linear.x = x_dot.at(0);
		vel_.linear.y = x_dot.at(1);
		vel_.linear.z = x_dot.at(2);	
		vel_.angular.x = x_dot.at(3);
		vel_.angular.y = x_dot.at(4);
		vel_.angular.z = x_dot.at(5);

		double a = 0.7;
		vel_.linear.x = a*vel_.linear.x + (1-a)*vel_previous_.linear.x;
		vel_.linear.y = a*vel_.linear.y + (1-a)*vel_previous_.linear.y;
		vel_.linear.z = a*vel_.linear.z + (1-a)*vel_previous_.linear.z;

		vel_previous_ = vel_;

		//ROS_INFO("Computed forward kinematics: %f %f %f",vel_.linear.x, vel_.linear.y, vel_.linear.z);
		tt_pub_.publish(pose_);
		tt_vel_pub_.publish(vel_);
	}


private:
	

	ros::Subscriber sub_;
	ros::Publisher tt_pub_, ee_pub_, tt_vel_pub_, ee_vel_pub_;
	sensor_msgs::JointState js_;
	lwr_controllers::PoseRPY pose_;
	geometry_msgs::Twist vel_;
	geometry_msgs::Twist vel_previous_;
	ForwardKinematics fk_;

};




#endif
