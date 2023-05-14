#!/usr/bin/env python
# coding=utf-8

#import random
import rospy
import rosgraph
import time
from unity_robotics_demo_msgs.msg import PosRot
#from unity_robotics_demo_msgs.msg import UnityColor


TOPIC_NAME = 'cubePose'
NODE_NAME = 'cubePose_publisher'


def post_cubePose():
    cubePose = PosRot()
    pub = rospy.Publisher(TOPIC_NAME, PosRot, queue_size=10)
    rospy.init_node(NODE_NAME, anonymous=True)

    rate = rospy.Rate(10)
    cnt = 0
    stato = 0
    while not rospy.is_shutdown():
        if stato == 0:
            cubePose.pos_x = 1.0
            if cnt >= 10: # cambia dopo 1s
                cnt = 0
                stato = 1
        if stato == 1:
            cubePose.pos_x = -1.0
            if cnt >= 10: # cambia dopo 1s
                cnt = 0
                stato = 0
                
        wait_for_connections(pub, TOPIC_NAME)
        pub.publish(cubePose)
        cnt+=1
        rate.sleep()


    # time.sleep(0.1) penso non serva perchè ho messo il rate


def wait_for_connections(pub, topic):
    ros_master = rosgraph.Master('/rostopic')
    topic = rosgraph.names.script_resolve_name('rostopic', topic)
    num_subs = 0
    for sub in ros_master.getSystemState()[1]:
        if sub[0] == topic:
            num_subs+=1

    for i in range(10):
        if pub.get_num_connections() == num_subs:
            return
        time.sleep(0.1)
    raise RuntimeError("failed to get publisher")


if __name__ == '__main__':
    try:
        post_cubePose()
    except rospy.ROSInterruptException:
        pass
