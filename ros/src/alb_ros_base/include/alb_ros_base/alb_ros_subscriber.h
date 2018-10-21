//
// Created by whymatter on 21.10.18.
//

#ifndef CAM_DIRECT_CAPTURE_ALB_ROS_SUBSCRIBER_H
#define CAM_DIRECT_CAPTURE_ALB_ROS_SUBSCRIBER_H

#include <ros/ros.h>

namespace alb {
    namespace base {
        namespace ros {
            class AlbRosSubscriber {
            public:
                explicit AlbRosSubscriber(::ros::Subscriber subscriber);

                ~AlbRosSubscriber();

            private:
                ::ros::Subscriber subscriber_;
            };
        }
    }
}

#endif //CAM_DIRECT_CAPTURE_ALB_ROS_SUBSCRIBER_H
