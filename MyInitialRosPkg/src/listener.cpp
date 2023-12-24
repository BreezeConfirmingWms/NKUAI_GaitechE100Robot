#include<iostream>
#include"ros/ros.h"
#include "MyInitialRosPkg/Person.h"


void PersonInfoCallBack(const MyInitialRosPkg::Person::ConstPtr &msg)
{
    ROS_INFO("Subscriber Person Info:name:%s age:%d sex:%d",msg->name.c_str(),msg->age,msg->sex);
}
int main(int argc ,char** argv){
    ros::init(argc,argv,"person_subscriber");
    ros::NodeHandle n;
    ros::Subscriber person_info_sub = n.subscribe("/person_info",10,PersonInfoCallBack);


    ros::spin();


    return 0;
}

