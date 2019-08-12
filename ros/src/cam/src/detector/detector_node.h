//
// Created by whymatter on 07.10.18.
//

#pragma once

#include "ros/ros.h"


class DetectorNode {
public:
    explicit DetectorNode(ros::NodeHandle n) : n_(n) {}

    void loop();

private:
    ros::NodeHandle n_;
};
