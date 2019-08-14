//
// Created by whymatter on 10.08.19.
//

#include <ros/ros.h>

#include "alb_ros_base/alb_ros_node_handle.h"
#include "roadmodel_node.h"
#include "spline.h"

int main(int argc, char **argv) {
    ::ros::init(argc, argv, "static_environment");

    MatrixX2d knots(4, 2);
    knots << 1, 1,
            4, 3,
            7, 8,
            2, 15;

    auto result = spline(knots);

    return 0;

    ::alb::base::ros::AlbRosNodehandle nodeHandle("/static_environment", 25.0);
    ::alb::roadmodel::RoadmodelNode<::alb::base::ros::AlbRosNodehandle> roadmodelNode{
            nodeHandle};
    roadmodelNode.Initialize();
    roadmodelNode.RunCyclic();
}