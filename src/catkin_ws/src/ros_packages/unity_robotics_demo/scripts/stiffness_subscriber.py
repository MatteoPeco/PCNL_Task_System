#!/usr/bin/env python
import rospy
import tf
import math
import time
import geometry_msgs.msg 
from rospy.names import global_name
from geometry_msgs.msg import Vector3, PointStamped, Point, Twist
from std_msgs.msg import Float32, Bool

import numpy as np
from scipy.interpolate import interp1d
from scipy import interpolate
import matplotlib.pyplot as plt

from lwr_controllers.msg import PoseRPY
from lwr_controllers.msg import RPY
from lwr_controllers.msg import CartesianImpedancePoint
from lwr_controllers.msg import Stiffness
from geometry_msgs.msg import Pose
from geometry_msgs.msg import Wrench
from unity_robotics_demo_msgs.msg import PosRot


stiffness = Stiffness() # definition of the stiffness as a global variable 
alligned = 0

def get_ee_position(data): # definition of the callback function of the ee_position subscriber (run every time the topic is read)
    global ee_position, ee_orientation, alligned
    if alligned == 1: # enetering the if when the robot is alligned and the position must update only along z of the ee_rf
	R_b2ee = get_rotm_from_euler(ee_orientation.roll, ee_orientation.pitch, ee_orientation.yaw) # computing the transformation matrix between base and ee
	Tran = np.array([[ee_position.x],[ee_position.y],[ee_position.z]]) # computing the translation of the ee RF in the base RF
	current_position_b = np.array([[data.position.x],[data.position.y],[data.position.z]]) # current position to be updated

	R_ee2b = np.linalg.inv(R_b2ee) #inverse rotation matrix definition
	current_position_ee = np.dot(R_ee2b,current_position_b)-np.dot(R_ee2b,Tran) # computing the position of the current position in the ee RF

	ee_position_ee = np.array([[0],[0],current_position_ee[2]]) # updating only along the z axis of the ee RF

	ee_position_b = np.dot(R_b2ee,ee_position_ee)+Tran # converting the new position back to the b_rf
	#updating the ee_postion
	ee_position.x = ee_position_b[0,0] 
	ee_position.y = ee_position_b[1,0] 
	ee_position.z = ee_position_b[2,0] 
	print(ee_position)
    else: # all the other times that must be updated along all axis
        ee_position = data.position
    	ee_orientation = data.orientation
	

def stiffness_update(data):
    global alligned
    stiffness.x = data.pos_x
    stiffness.y = data.pos_y
    stiffness.z = data.pos_z
    stiffness.rx = data.rot_x
    stiffness.ry = data.rot_y
    stiffness.rz = data.rot_z
    alligned = data.rot_w

def get_rotm_from_euler(roll, pitch, yaw):
 	yawMatrix = np.array([
	[math.cos(yaw), -math.sin(yaw), 0],
	[math.sin(yaw), math.cos(yaw), 0],
	[0, 0, 1]
	])

	pitchMatrix = np.array([
	[math.cos(pitch), 0, math.sin(pitch)],
	[0, 1, 0],
	[-math.sin(pitch), 0, math.cos(pitch)]
	])
	
	rollMatrix = np.array([
	[1, 0, 0],
	[0, math.cos(roll), -math.sin(roll)],
	[0, math.sin(roll), math.cos(roll)]
	])

	R = np.dot(yawMatrix, pitchMatrix, rollMatrix)
	return R

def get_quaternion_from_euler(roll, pitch, yaw):
  
  qx = np.sin(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) - np.cos(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)
  qy = np.cos(roll/2) * np.sin(pitch/2) * np.cos(yaw/2) + np.sin(roll/2) * np.cos(pitch/2) * np.sin(yaw/2)
  qz = np.cos(roll/2) * np.cos(pitch/2) * np.sin(yaw/2) - np.sin(roll/2) * np.sin(pitch/2) * np.cos(yaw/2)
  qw = np.cos(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) + np.sin(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)
 
  return [qx, qy, qz, qw]

def main():
   global ee_position #definition of the ee position for updating it 
   global ee_orientation #definition of the ee position for updating it 
   # --------------Initialization, subscribers and publisher, rate -------------------------------------------
   # Init the node      
   rospy.init_node('Cartesian_trajectory')
   # Subscriber: reads the current pose of the robot
   sub1= rospy.Subscriber('/cartesian_position/pose/end_effector', PoseRPY, get_ee_position)
   # Subscriber: reads the stiffness sent from the robot
   sub2= rospy.Subscriber('/Stiffness', PosRot, stiffness_update)

   # Publisher for the reference      
   pub = rospy.Publisher('/lwr/cartesian_impedance_controller/command', CartesianImpedancePoint, queue_size = 10)
   time.sleep(1)

   # Define the node execution frequency         
   rate = rospy.Rate(10) 

   pose = Pose()
   #stiffness = Stiffness()
   damping = Stiffness()
   wrench = Wrench()
   reference = CartesianImpedancePoint()

   # Standard values for k and d
   #k = [800, 800, 800, 100, 100, 100]
   #stiffness.x = 50
   #stiffness.y = 50
   #stiffness.z = 50
   #stiffness.rx = 50
   #stiffness.ry = 50
   #stiffness.rz = 50


   #d = [0.8, 0.8, 0.8, 0.8, 0.8, 0.8]
   damping.x = 0.8
   damping.y = 0.8
   damping.z = 0.8
   damping.rx = 0.8
   damping.ry = 0.8
   damping.rz = 0.8

      # wrench 
   wrench.force.x = 0
   wrench.force.y = 0
   wrench.force.z = 0
   wrench.torque.x = 0
   wrench.torque.y = 0
   wrench.torque.z = 0


   while not rospy.is_shutdown():
    pose.position = ee_position
    quaternion = tf.transformations.quaternion_from_euler(ee_orientation.roll,ee_orientation.pitch, ee_orientation.yaw)
    pose.orientation.x = quaternion[0]
    pose.orientation.y = quaternion[1]
    pose.orientation.z = quaternion[2]
    pose.orientation.w = quaternion[3]
    reference.x_FRI = pose
    reference.k_FRI = stiffness
    reference.d_FRI = damping
    reference.f_FRI = wrench 
    pub.publish(reference)
    rate.sleep()


if __name__ == '__main__':
    main()
