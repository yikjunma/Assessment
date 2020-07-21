#include <ros/ros.h>
#include <geometry_msgs/Twist.h> 
#include <stdlib.h> 

void callback(const ros::TimerEvent&)
{
  ROS_INFO("Callback triggered");
}
int main(int argc, char **argv) {
    ros::init(argc, argv,"clockwise");
    ros::NodeHandle nh;

    ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("cmd_vel", 100);
     
	 
	 //Rate set to 1hz so the node publishes at one per second and count is set to max 10 for ten total publishes
    ros::Rate rate(1);
    int count = 0;
     while(ros::ok() && count <= 10) {
         geometry_msgs::Twist msg;

		//clockwise rotation.
         msg.angular.z= -160;
         pub.publish(msg);
         rate.sleep();
		 count++;
    }
}
