#!/usr/bin/env python

import rospy
from std_msgs.msg import String
#rospy.init_node("One_node_to_rule_them_all")
pub = rospy.Publisher("echo", String, queue_size=10)
rospy.init_node("One_node_to_rule_them_all", anonymous=True)


def callback(input):
        pub.publish(input.data)
        # The message has 2 parts, a header and the data. We only want to use the actual data

sub = rospy.Subscriber("chatter", String, callback)

pub2 = rospy.Publisher("chatter", String, queue_size=10)
pub2.publish("'Stop repeating everything I say")



