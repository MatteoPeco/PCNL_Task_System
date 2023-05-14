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

def get_ee_position(data):
    global ee_position, ee_orientation
    ee_position = data.position
    ee_orientation = data.orientation

def get_quaternion_from_euler(roll, pitch, yaw):
  
  qx = np.sin(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) - np.cos(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)
  qy = np.cos(roll/2) * np.sin(pitch/2) * np.cos(yaw/2) + np.sin(roll/2) * np.cos(pitch/2) * np.sin(yaw/2)
  qz = np.cos(roll/2) * np.cos(pitch/2) * np.sin(yaw/2) - np.sin(roll/2) * np.sin(pitch/2) * np.cos(yaw/2)
  qw = np.cos(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) + np.sin(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)
 
  return [qx, qy, qz, qw]

def main():
   global ee_position
   global ee_orientation
   # --------------Initialization, subscribers and publisher, rate -------------------------------------------
   # Init the node      
   rospy.init_node('Cartesian_trajectory')
   # Subscriber: reads the current pose of the robot
   sub1= rospy.Subscriber('/cartesian_position/pose/end_effector', PoseRPY, get_ee_position)


   # Publisher for the reference      
   pub = rospy.Publisher('/lwr/cartesian_impedance_controller/command', CartesianImpedancePoint, queue_size = 10)
   time.sleep(1)

   # Define the node execution frequency         
   rate = rospy.Rate(10) 

   pose = Pose()
   stiffness = Stiffness()
   damping = Stiffness()
   wrench = Wrench()
   reference = CartesianImpedancePoint()

   # Standard values for k and d
   #k = [800, 800, 800, 100, 100, 100]
   stiffness.x = 0
   stiffness.y = 0
   stiffness.z = 0
   stiffness.rx = 50
   stiffness.ry = 50
   stiffness.rz = 50

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
