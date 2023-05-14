#!/usr/bin/env python
# coding=utf-8

#import random
import rospy
import rosgraph
import time
from unity_robotics_demo_msgs.msg import PosRot
from lwr_controllers.msg import PoseRPY

NODE_NAME = 'ToolTipPose_publisher'
OUT_TOPIC_NAME = '/lwr/one_task_inverse_kinematics/command'
IN_TOPIC_NAME = 'PosRotCommand'
ToolTipPose = PoseRPY()
# NODE EXPLAINATION
# this node takes a message from unity and sends a message to ros, on the unity side the user decides the orientation of the ToolTipPose, this orientation is sent
# to ros trough the PosRotCommand; this message is taken from this node and sent to gazebo as a new message: one_task_inverse_kinematics/command,
# afterwards gazebo moves the model in order to obtain the appropriate robot configuration (nb at this point the joints_publisher script sends the new
# joints values to unity so the user sees the robot takin the orientation he wanted)

#this function is called when the ros script receives the message from unity with the pose and oroentation of the tool tip
def subscriber_cb(msg):
    # here the unity message (PosRotCommand) received is associated to the ros message (one_task_inverse_kinematics/command)
    ToolTipPose.position.x = msg.pos_x;
    ToolTipPose.position.y = msg.pos_z;
    ToolTipPose.position.z = msg.pos_y;
    ToolTipPose.orientation.roll = msg.rot_x;
    ToolTipPose.orientation.pitch = msg.rot_y;
    ToolTipPose.orientation.yaw = msg.rot_z;
    #wait_for_connections(pub, OUT_TOPIC_NAME)
    #pub.publish(ToolTipPose)


def post_ToolTipPose():

    rospy.init_node(NODE_NAME, anonymous=True)
    pub = rospy.Publisher(OUT_TOPIC_NAME, PoseRPY, queue_size=10)
    sub = rospy.Subscriber(IN_TOPIC_NAME, PosRot, subscriber_cb)
    #rate = rospy.Rate(10)
    #this code part is executed only once and is the initialization of the node plus the inizialization of the robot postion
    #nb untill the message is not updated from subscriber_cb function the configuration is this imposed one
    ToolTipPose.position.x = 0.582612441944;
    ToolTipPose.position.y = -5.910499903540e-05;
    ToolTipPose.position.z = 0.316182676939;
    ToolTipPose.orientation.roll = -3.14151497629;
    ToolTipPose.orientation.pitch = -1.7217832072e-05;
    ToolTipPose.orientation.yaw = 3.14152168856;
    #wait_for_connections(pub, OUT_TOPIC_NAME)
    #pub.publish(ToolTipPose)

    while not rospy.is_shutdown():
        wait_for_connections(pub, OUT_TOPIC_NAME)
        pub.publish(ToolTipPose)
        #rate.sleep()


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
        post_ToolTipPose()
    except rospy.ROSInterruptException:
        pass
