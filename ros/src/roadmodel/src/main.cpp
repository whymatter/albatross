//
// Created by whymatter on 10.08.19.
//

#include <ros/ros.h>

#include "alb_ros_base/alb_ros_node_handle.h"
#include "roadmodel_node.h"

int main(int argc, char **argv) {
    ::ros::init(argc, argv, "static_environment");

    MatrixX2d knots(12, 2);
    knots << 106.74156951904297,180.18386840820312,432.1756896972656,169.15219116210938,239.12155151367188,299.6935729980469,402.7579040527344,374.1573181152344,228.0898895263672,510.2145080566406,532.3800048828125,583.7589111328125,378.8559875488281,746.4760131835938,92.03268432617188,605.822265625,147.19100952148438,296.016357421875,49.74463653564453,249.1317596435547,64.45352172851562,83.65679168701172,582.0224609375,133.29928588867188;

    ::alb::base::ros::AlbRosNodehandle nodeHandle("/static_environment", 25.0);
    ::alb::roadmodel::RoadmodelNode<::alb::base::ros::AlbRosNodehandle> roadmodelNode{
            nodeHandle, knots};
    roadmodelNode.Initialize();
    roadmodelNode.RunCyclic();
}