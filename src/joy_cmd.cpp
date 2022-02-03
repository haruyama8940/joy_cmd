#include <ros/ros.h>      
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/JoyFeedbackArray.h>
#include<array>
#include <vector>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>
#include <std_msgs/Int8MultiArray.h>
ros::Subscriber joy_sub;
ros::Publisher joy_pub,cmd_data_pub;
//boost::array<int,10>joy_b;
std::vector<int> joy_b;
std_msgs::Int8MultiArray cmd_data;
std::vector<std::vector<int>> list_data={{100,0,0,0},{0,100,0,0},{0,0,100,0},{0,0,0,100}};
sensor_msgs::Joy cmd_topic;
std::vector<int> list_data_continue={100,0,0,0};
std::vector<int> list_data_go={0,100,0,0};
std::vector<int> list_data_left={0,0,100,0};
std::vector<int> list_data_right={0,0,0,100};

void Joy_Callback(const sensor_msgs::Joy& joy_msg)
{
//std::vector<int> joy_b(joy_msg.buttons);
//cmd_topic = joy_msg;
ROS_INFO("Joy_callback");
//std_msgs::String msg;
std_msgs::Int8MultiArray cmd_data;
  if (joy_msg.buttons[1]==1)
  {
    //"turn_right"
    cmd_data.data={0,0,0,100};
    cmd_data_pub.publish(cmd_data);
    ROS_INFO("right");
  }

  if (joy_msg.buttons[2]==1)
  {
    //"turn_left"
     cmd_data.data={0,0,100,0};
    cmd_data_pub.publish(cmd_data);
    ROS_INFO("left");
  }
  if (joy_msg.buttons[3]==1)
  {
    //"go_straight"
     cmd_data.data={0,100,0,0};
    cmd_data_pub.publish(cmd_data);
    ROS_INFO("go");
  }
  if (joy_msg.buttons[4]==1)
  {
    //"go_straight"
     cmd_data.data={100,0,0,0};
    cmd_data_pub.publish(cmd_data);
    ROS_INFO("continue");
  }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "joy_cmd");        
  ros::NodeHandle nh;                       
  // joy_pub = nh.advertise<std_msgs::String>("joy_cmd", 10);
  cmd_data_pub = nh.advertise<std_msgs::Int8MultiArray >("cmd_data", 1);
  joy_sub = nh.subscribe("joy", 10, Joy_Callback);
  ROS_INFO("muripo");
  ros::spin();                              
  return 0;
}
