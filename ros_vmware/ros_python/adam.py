#!/usr/bin/env python


import rospy

from std_msgs.msg import Int32


value = 0


def update_value(msg):
    value = msg.data


# rospy.init_node("my_node", anonymous=True)
# rate = rospy.Rate(10)

rospy.init_node('echoer', anonymous=True)

pub = rospy.Publisher('/out_value', Int32, queue_size=10)

v = 0
rospy.Subscriber('chatter_test', Int32, v)


# my_publisher = rospy.Publisher('my_data', Int32, queue_size=10)

def run():
    r = rospy.Rate(10)
    while not rospy.is_shutdown():
        pub.publish(value)
        r.sleep()


run()


# def callback_func(data):
#     rospy.loginfo(data.data)
#
# def publish_data(x):
#     my_publisher.publish(x)
#
# rospy.Subscriber('arduino_data', Int32, callback_func)
#
# while not rospy.is_shutdown():
#     x = 3
#     publish_data(x)
#     rate.sleep()
