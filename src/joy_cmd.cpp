#include <ros/ros.h>          
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/JoyFeedbackArray.h>
#include<array>
#include <vector>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>

ros::Subscriber joy_sub;
ros::Publisher joy_cmd;
//boost::array<int,10>joy_b;
std::vector<int> joy_b;
/*
void Joy_Callback(sensor_msgs::Joy joy_msg)
{
std::vector<int> joy_b(joy_msg.buttons);
std_msgs::String msg;
  if (joy_b[4]==1)
  {
    msg.data="go_straight";
    joy_cmd.publish(msg.data);
  }
  if (joy_b[3]==1)
  {
    msg.data="turn_right";
    joy_cmd.publish(msg.data);
  }
  if (joy_b[4]==1)
  {
    msg.data="turn_left";
    joy_cmd.publish(msg.data);
  }
  
}
*/
int main(int argc, char **argv) {
  ros::init(argc, argv, "joy_cmd");        // ノードの初期化（ノード名を"srv_test"に設定）
  ros::NodeHandle nh;                       // ノードハンドルの生成
  //joy_sub = nh.subscribe("joy", 10, &Joy_Callback);
  ROS_INFO("muripo");
  ros::spin();                              // リクエストの無限待ち
  return 0;
}
