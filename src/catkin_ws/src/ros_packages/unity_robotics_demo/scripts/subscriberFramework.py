#!/usr/bin/env python

import random
import rospy
import rosgraph
import time
from unity_robotics_demo_msgs.msg import RotJoints
from sensor_msgs.msg import JointState


TOPIC_NAME = '/lwr/joint_states'
NODE_NAME = 'jointsState_subscriber'

def chatter_cb(msg):
    print (msg.position[0])

def main():
    rospy.init_node(NODE_NAME)
    KUKAJoints = RotJoints();

    sub = rospy.Subscriber(TOPIC_NAME, JointState, chatter_cb)
    rospy.spin(); #this line of code waits forever till there is another callback (chatter_cb)


if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
