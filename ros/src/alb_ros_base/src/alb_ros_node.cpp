#include <utility>

//
// Created by whymatter on 20.10.18.
//

#include "alb_ros_node.h"

namespace alb {
    namespace base {
        namespace ros {
            AlbRosNode::AlbRosNode(std::string nodeName, double loopRate)
                    : nodeHandle_(nodeName), loopRate_{loopRate} {
                ROS_INFO_STREAM("Started " << nodeName);
                ROS_DEBUG_STREAM("LoopRate" << loopRate);
            };

            void AlbRosNode::Initialize() {
            }

            void AlbRosNode::RunCyclic() {
                while (::ros::ok()) {
                    this->CyclicStep();

                    ::ros::spinOnce();
                    this->loopRate_.sleep();
                }
            }
        }
    }
}