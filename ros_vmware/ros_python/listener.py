#!/usr/bin/env python

import rospy
from std_msgs.msg import Int16

rospy.init_node('diffe', anonymous=True)

output = 0


rate = rospy.Rate(10)


# def talker():

pub = rospy.Publisher('servo', Int16, queue_size=10)


def callback(data):
    output = data.data
    pub.publish(output)
    # rospy.loginfo(output)
    rate.sleep()
    # rospy.loginfo(data.data)
    print output

def listener():

    # rospy.init_node('listener', anonymous=True)

    rospy.Subscriber('arduino1', Int16, callback)
    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()



#
# def talker():
#     pub = rospy.Publisher('chatter_test', Int32, queue_size=10)
#     rate = rospy.Rate(10) # 10hz
#     while not rospy.is_shutdown():
#         #hello_str = "hello world %s" % rospy.get_time()
#         #output = 341
# 	hello_str = 132
# 	rospy.loginfo(hello_str)
#         pub.publish(hello_str)
#         rate.sleep()



if __name__ == '__main__':
    listener()




# if __name__ == '__main__':
#     try:
#         talker()
#     except rospy.ROSInterruptException:
#         pass
#
#
#
#
