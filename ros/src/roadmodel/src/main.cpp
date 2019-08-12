//
// Created by whymatter on 10.08.19.
//

#include <ros/ros.h>

#include "alb_ros_base/alb_ros_node_handle.h"
#include "roadmodel_node.h"

int main(int argc, char **argv) {
    ::ros::init(argc, argv, "static_environment");

    ::alb::base::ros::AlbRosNodehandle nodeHandle("/static_environment", 25.0);
    ::alb::roadmodel::RoadmodelNode<::alb::base::ros::AlbRosNodehandle> roadmodelNode{
            nodeHandle};
    roadmodelNode.Initialize();
    roadmodelNode.RunCyclic();
}