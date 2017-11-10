#!/usr/bin/env python

import rospy
from std_msgs.msg import String

from std_msgs.msg import Int32

value = 0

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + 'I heard %s', data.data)
    value = data.data

#data = 17
#test = 17

def listener():
    rospy.init_node('listener', anonymous=True)

    #rospy.Subscriber('Arduino/Ultrasonic', String,  callback)
    rospy.Subscriber('chatter_test', Int32,  callback)

    #rospy.spin()
    #return result


def talker():
    pub = rospy.Publisher('chatterArduino', Int32, queue_size=10)
    rospy.init_node('talkArduino', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        listener()
	hello_str = "hello world %s" % rospy.get_time()
	#hol = "test %s" % data	
        rospy.loginfo(value)
        pub.publish(value)
        rate.sleep()


if __name__ == '__main__':
    try:
       #listener()
        talker()
    except rospy.ROSInterruptException:
        pass

