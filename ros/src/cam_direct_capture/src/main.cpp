//
// Created by whymatter on 20.10.18.
//

#include <ros/ros.h>

#include "alb_ros_base/alb_ros_node_handle.h"
#include "cam_direct_capture_node.h"

int main(int argc, char **argv) {
    ::ros::init(argc, argv, "cam_direct_capture");

    ::alb::base::ros::AlbRosNodehandle nodeHandle("/cam/direct", 25.0);
    ::alb::cam::direct_capture::DirectCaptureNode<::alb::base::ros::AlbRosNodehandle> directCaptureNode{nodeHandle};
    directCaptureNode.Initialize();
    directCaptureNode.RunCyclic();

}