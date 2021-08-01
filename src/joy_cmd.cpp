#include <ros/ros.h>          
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/JoyFeedbackArray.h>
#include<array>
#include <vector>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>

ros::Subscriber joy_sub;
ros::Publisher joy_pub;
//boost::array<int,10>joy_b;
std::vector<int> joy_b;
sensor_msgs::Joy cmd_topic;
void Joy_Callback(const sensor_msgs::Joy& joy_msg)
{
//std::vector<int> joy_b(joy_msg.buttons);
//cmd_topic = joy_msg;
ROS_INFO("Joy_callback");
std_msgs::String msg;

  if (joy_msg.buttons[1]==1)
  {
    msg.data="turn_right";
    joy_pub.publish(msg);
    ROS_INFO("right");
  }

  if (joy_msg.buttons[2]==1)
  {
    msg.data="turn_left";
    joy_pub.publish(msg);
    ROS_INFO("left");
  }
  if (joy_msg.buttons[3]==1)
  {
    msg.data="go_straight";
    joy_pub.publish(msg);
    ROS_INFO("go");
  }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "joy_cmd");        
  ros::NodeHandle nh;                       
  joy_pub = nh.advertise<std_msgs::String>("joy_cmd", 10);
  joy_sub = nh.subscribe("joy", 10, Joy_Callback);
  ROS_INFO("muripo");
  ros::spin();                              
  return 0;
}
