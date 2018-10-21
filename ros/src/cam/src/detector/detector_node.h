//
// Created by whymatter on 07.10.18.
//

#ifndef NN_TESTER_MAIN_H
#define NN_TESTER_MAIN_H

#include "ros/ros.h"


class DetectorNode {
public:
    explicit DetectorNode(ros::NodeHandle n) : n_(n) {}

    void loop();

private:
    ros::NodeHandle n_;
};


#endif //NN_TESTER_MAIN_H
