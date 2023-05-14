#!/usr/bin/env python

import random
import rospy
import rosgraph
import time
from unity_robotics_demo_msgs.msg import PosRot
from lwr_controllers.msg import PoseRPY

NODE_NAME = 'poseFormartTreatmentNode'
IN_TOPIC_NAME = '/cartesian_position/pose/tooltip'
OUT_TOPIC_NAME = 'ToolTipPose'
ToolTipPose = PosRot();
# NODE EXPLAINATION
# this node takes a message from ros and sends a message to unity, the aim of it is to let the unity side know the position and orienation of the ToolTip
# in order to let the sliders setup on the correct position and to make cross validation wiht the parameters set on the unityside

#this function is called when the ros script reads the pose/tooltip topic
def subscriberPose_cb(msg):
    # here the ToolTipPose message that will be sent to unity is constructed, by simplly associating each coordinate value to the corresponding value of the pose/tootltip message
    ToolTipPose.pos_x = msg.position.x;
    ToolTipPose.pos_y = msg.position.y;
    ToolTipPose.pos_z = msg.position.z;
    ToolTipPose.rot_x = msg.orientation.roll;
    ToolTipPose.rot_y = msg.orientation.pitch;
    ToolTipPose.rot_z = msg.orientation.yaw;

def post_pose():
    rospy.init_node(NODE_NAME, anonymous=True)
    sub = rospy.Subscriber(IN_TOPIC_NAME, PoseRPY, subscriberPose_cb)
    pub = rospy.Publisher(OUT_TOPIC_NAME, PosRot, queue_size=10)

    rate = rospy.Rate(10) #rate of the next while (hence of the publishing) in Hz
    # here the topic is publised, nb even tho it will be used from unity nothing strage is used here, it simply publises this topic
    while not rospy.is_shutdown():
        wait_for_connections(pub, OUT_TOPIC_NAME)
        pub.publish(ToolTipPose)
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
        post_pose()
    except rospy.ROSInterruptException:
        pass
