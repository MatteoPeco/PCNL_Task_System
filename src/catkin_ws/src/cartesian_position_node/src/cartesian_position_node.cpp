#include "ros/ros.h"
#include "../include/forward_kinematics.h"
#include "../include/cartesian_position_node.h"



int main(int argc, char* argv[])
{
	ros::init(argc, argv, "cartesian_position_node");
	ros::NodeHandle n;
	CartesianPositionNode CP(n, argv[1]);
	ros::spin();
	return 0;





}
