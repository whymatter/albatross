//
// Created by whymatter on 28.10.18.
//

#include <ros/ros.h>

#include "alb_ros_base/alb_ros_node_handle.h"
#include "static_environment_node.h"

int main(int argc, char **argv) {
    ::ros::init(argc, argv, "static_environment");

    ::alb::base::ros::AlbRosNodehandle nodeHandle("/static_environment", 25.0);
    ::alb::static_environment::StaticEnvironmentNode<::alb::base::ros::AlbRosNodehandle> staticEnvironmentNode{
            nodeHandle};
    staticEnvironmentNode.Initialize();
    staticEnvironmentNode.RunCyclic();
}