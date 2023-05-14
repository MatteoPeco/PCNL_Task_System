#!/usr/bin/env python

import random
import rospy
import rosgraph
import time
from unity_robotics_demo_msgs.msg import RotJoints
from sensor_msgs.msg import JointState

NODE_NAME = 'jointFormartTreatmentNode'
IN_TOPIC_NAME = '/lwr/joint_states'
OUT_TOPIC_NAME = 'joints'
KUKAJoints = RotJoints();
# NODE EXPLAINATION
# this node takes a message from ros and sends a message to unity, this node is simple, it takes the joints values from gazebo with the topic joint_states
# then it takes these values, it associate this values to a new topic joints that is sent to unity
# nb this strategy is needed because gazebo computes the inverse kinematics for unity and sends the joints trough tcp connector

#this function is called when the ros script reads the joint_states topic
def subscriber_cb(msg):
    # here the joints message that will be sent to unity is constructed, by simplly associating each joint value to the corresponding value of the joints message
    KUKAJoints.a1_joint = msg.position[0];
    KUKAJoints.a2_joint = msg.position[1];
    KUKAJoints.a3_joint = msg.position[2];
    KUKAJoints.a4_joint = msg.position[3];
    KUKAJoints.a5_joint = msg.position[4];
    KUKAJoints.a6_joint = msg.position[5];
    KUKAJoints.e1_joint = msg.position[6];

def post_joints():
    rospy.init_node(NODE_NAME, anonymous=True)
    sub = rospy.Subscriber(IN_TOPIC_NAME, JointState, subscriber_cb)
    pub = rospy.Publisher(OUT_TOPIC_NAME, RotJoints, queue_size=10)

    rate = rospy.Rate(100) #rate of the next while (hence of the publishing) in Hz
    # here the topic is publised, nb even tho it will be used from unity nothing strage is used here, it simply publises this topic
    while not rospy.is_shutdown():
        wait_for_connections(pub, OUT_TOPIC_NAME)
        pub.publish(KUKAJoints)
        rate.sleep()


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
        post_joints()
    except rospy.ROSInterruptException:
        pass
