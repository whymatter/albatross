//
// Created by whymatter on 07.10.18.
//

#include "ros/ros.h"

#include "detector_node.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "cam-detector");

    ros::NodeHandle n;
    ros::Rate loop_rate(10);

    DetectorNode dn(n);

    while (ros::ok()) {
        dn.loop();

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}