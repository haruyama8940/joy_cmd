#!/usr/bin/env python3
from asyncore import write
from time import time

import rospy
import yaml
import time
import random
import roslib
from sensor_msgs.msg import NavSatFix,Joy

class record_Node:
    def __init__(self):
        self.joy_sub = rospy.Subscriber("/joy",Joy, self.joy_callback)
        self.nav_sat =rospy.Subscriber("/ublox/fix",NavSatFix,self.navsatfix_callback)
        self.write_flag = False
        self.write_dir = roslib.packages.get_pkg_dir('joy_cmd')

    def coordinate2yaml(self,file_name, status, longitude, latitude):
        with open(file_name, "a") as YAML:
            yaml.dump({
                "data": {
                    "status": status,
                    "longitude": longitude,
                    "latitude": latitude
                },
            }, YAML, default_flow_style=False)

    def joy_callback(self,joy_data):
        if joy_data.buttons[0] == 1:
            self.write_flag = True
        else :
            self.write_flag = False

    def navsatfix_callback(self,data):
        self.nav_status = data.status
        self.nav_latitude = data.latitude
        self.nav_longitude = data.longitude

    def record_msg_for_yaml(self):
        if self.write_flag == True:
            print("write")
            self.coordinate2yaml(self.write_dir + '/Navsat_tsudanuma.yaml',self.nav_status,self.nav_latitude,self.nav_longitude)
        else :
            pass

if __name__ == "__main__":
    rospy.init_node('record_gnss_node')

    time.sleep(0.1)
    rec_node = record_Node()
    print("ready")
    while not rospy.is_shutdown():
        rec_node.record_msg_for_yaml()       
        rospy.sleep(2.0)
