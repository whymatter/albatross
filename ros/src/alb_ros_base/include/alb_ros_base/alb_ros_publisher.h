//
// Created by whymatter on 21.10.18.
//

#ifndef CAM_DIRECT_CAPTURE_ALB_ROS_PUBLISHER_H
#define CAM_DIRECT_CAPTURE_ALB_ROS_PUBLISHER_H

#include <ros/ros.h>

namespace alb {
    namespace base {
        namespace ros {
            class AlbRosPublisher {
            public:
                explicit AlbRosPublisher(::ros::Publisher publisher);

                ~AlbRosPublisher();

            private:
                ::ros::Publisher publisher_;
            };
        }
    }
}

#endif //CAM_DIRECT_CAPTURE_ALB_ROS_PUBLISHER_H
