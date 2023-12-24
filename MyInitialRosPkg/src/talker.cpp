#include<iostream>
#include"ros/ros.h"
#include "MyInitialRosPkg/Person.h"


int main(int argc,char**argv){
    ros::init(argc,argv,"person_publisher");

    ros::NodeHandle n;

    ros::Publisher person_info_pub = n.advertise<MyInitialRosPkg::Person>("/person_info",10);

    ros::Rate loop_rate(1);

    int count=0;

    while(ros::ok())
    {
        MyInitialRosPkg::Person person_msg;
        person_msg.name = "Tom";
        person_msg.age = 18;
        person_msg.sex = MyInitialRosPkg::Person::male;

        person_info_pub.publish(person_msg);

        ROS_INFO("Publish Person Info :name:%s age%d sex %d",person_msg.name.c_str(),person_msg.age,person_msg.sex);

        loop_rate.sleep();

    }
}
