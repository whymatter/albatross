//
// Created by whymatter on 20.10.18.
//

#include <ros/ros.h>

#include "cam_direct_capture_node.h"

int main(int argc, char **argv) {
    ::ros::init(argc, argv, "cam_direct_capture");

    ::alb::cam::direct_capture::DirectCaptureNode directCaptureNode;
    directCaptureNode.Initialize();
    directCaptureNode.RunCyclic();

}