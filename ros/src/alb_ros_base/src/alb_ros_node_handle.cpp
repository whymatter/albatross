//
// Created by whymatter on 26.10.18.
//

#include "alb_ros_node_handle.h"

namespace alb {
    namespace base {
        namespace ros {
            AlbRosNodehandle::AlbRosNodehandle(std::string nodeName, double loopRate)
                    : nodeHandle_{nodeName}, loopRate_{loopRate} {
                ROS_INFO_STREAM("Started " << nodeName);
                ROS_DEBUG_STREAM("LoopRate" << loopRate);
            };

            void AlbRosNodehandle::InternalCyclicStep() {
                ::ros::spinOnce();
                this->loopRate_.sleep();
            }

            bool AlbRosNodehandle::Abort() {
                return ::ros::ok() == false;
            }
        }
    }
}