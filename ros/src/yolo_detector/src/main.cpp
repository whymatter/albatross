//
// Created by whymatter on 27.10.18.
//

#include <ros/ros.h>

#include "alb_ros_base/alb_ros_node_handle.h"
#include "yolo_detector_node.h"

int main(int argc, char **argv) {
    ::ros::init(argc, argv, "yolo_detector");

    ::alb::base::ros::AlbRosNodehandle nodeHandle("/detector", 25.0);
    ::alb::yolo_detector::CupDetectorNode<::alb::base::ros::AlbRosNodehandle> cupDetectorNode{nodeHandle};
    cupDetectorNode.Initialize();
    cupDetectorNode.RunCyclic();
}