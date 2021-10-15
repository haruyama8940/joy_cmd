#include <ros/ros.h>          
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/JoyFeedbackArray.h>
#include <joy_cmd/dir_cmd_msg.h>
#include<array>
#include <vector>
#include <std_msgs/Int32.h>
#include <std_msgs/Int8MultiArray.h>
#include <std_msgs/String.h>
#include <random>
#include <iostream>

ros::Subscriber joy_sub;
// ros::Publisher joy_pub;
ros::Publisher cmd_data_pub;
//boost::array<int,10>joy_b;
std::vector<int> joy_b;
sensor_msgs::Joy cmd_topic;
std_msgs::Int8MultiArray cmd_data;
std::vector<std::string> cmd_list = {"go_stright","turn_right","turn_left"};
//std::array<int,3> data{0,0,0};
int list[3][3]={
                {1,0,0},
                {0,1,0},
                {0,0,1},
                };
             
void Joy_Callback(const sensor_msgs::Joy& joy_msg)
{
  //std::vector<int> joy_b(joy_msg.buttons);
  //cmd_topic = joy_msg;
  ROS_INFO("Joy_callback");
  //std_msgs::String msg;
  // joy_cmd::dir_cmd_msg cmd_data;
  /*cmd_data.cmd_word="go";
  //cmd_data.cmd_array[0]=1;
  //joy_pub.publish(cmd_data);
  cmd_data.cmd_array[0]=1;
  cmd_data.cmd_array[1]=0;
  cmd_data.cmd_array[2]=0;
  joy_pub.publish(cmd_data);
  */
  int i=0;
  if (joy_msg.buttons[1]==1)
    {
      //msg.data="turn_right";
      // cmd_data.cmd_word=cmd_list[1];
      for ( i = 0; i < 3; i++)
      {
      cmd_data.data[i]=list[1][i];
      }
      // joy_pub.publish(cmd_data);
      cmd_data_pub.publish(cmd_data);
      ROS_INFO("right");
    }

  if (joy_msg.buttons[2]==1)
    {
    //msg.data="turn_left";
    //msg.data=cmd_list[2];
      // cmd_data.cmd_word=cmd_list[2];
      for ( i = 0; i < 3; i++)
      {
      cmd_data.data[i]=list[2][i];
      }
      // joy_pub.publish(cmd_data);
      cmd_data_pub.publish(cmd_data);

      ROS_INFO("left");
      }
  if (joy_msg.buttons[3]==1)
    {
    //msg.data="go_straight";
    //msg.data=cmd_list[0];
    // cmd_data.cmd_word=cmd_list[0];
    for ( i = 0; i < 3; i++)
    {
    cmd_data.data[i]=list[0][i];
    }
    // joy_pub.publish(cmd_data);
    cmd_data_pub.publish(cmd_data);
    ROS_INFO("go");
    }
}

uint64_t get_rand_range( uint64_t min_vel, uint64_t max_vel ){
  static std::mt19937_64 mt64(0);
  std::uniform_int_distribution<uint64_t> get_rand_uni_int( min_vel, max_vel );
  return get_rand_uni_int(mt64);
}

int main(int argc, char **argv) {

  ros::init(argc, argv, "joy_cmd");        // ノードの初期化（ノード名を"srv_test"に設定）
  ros::NodeHandle nh;                       // ノードハンドルの生成
  //joy_pub = nh.advertise<std_msgs::String>("joy_cmd", 10);
  //joy_sub = nh.subscribe("joy", 10, Joy_Callback);
  ROS_INFO("muripo");                
  //joy_pub = nh.advertise<std_msgs::String>("joy_cmd", 10);
  // joy_pub = nh.advertise<joy_cmd::dir_cmd_msg>("cmd_data", 10);
  cmd_data_pub =nh.advertise<std_msgs::Int8MultiArray>("cmd_data",10);
  joy_sub = nh.subscribe("joy", 10, Joy_Callback);
  ROS_INFO("muripo");
  ros::spin();                              

  return 0;
}
