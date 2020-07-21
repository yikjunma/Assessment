#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist

def rotate():
    rospy.init_node('husky_anti_clockwise', anonymous=True)
    velocity_publisher = rospy.Publisher('/cmd_vel', Twist, queue_size=100)
    vel_msg = Twist()

    vel_msg.angular.z = abs(160)

    rate = rospy.Rate(1)

    count = 0
    while not (rospy.is_shutdown()):
	if(count == 10):
		break
        velocity_publisher.publish(vel_msg)
	rate.sleep()
        count += 1

if __name__ == '__main__':
    try:
        # Testing our function
        rotate()
    except rospy.ROSInterruptException:
        pass
