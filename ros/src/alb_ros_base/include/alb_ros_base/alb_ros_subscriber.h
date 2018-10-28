//
// Created by whymatter on 21.10.18.
//

#ifndef CAM_DIRECT_CAPTURE_ALB_ROS_SUBSCRIBER_H
#define CAM_DIRECT_CAPTURE_ALB_ROS_SUBSCRIBER_H

#include <ros/ros.h>

#include "alb_base/alb_subscriber.h"

namespace alb {
    namespace base {
        namespace ros {
            class AlbRosSubscriber : public ::alb::base::AlbSubscriber {
            public:
                explicit AlbRosSubscriber(::ros::Subscriber &subscriber)
                        : subscriber_{subscriber} {

                }

                explicit AlbRosSubscriber(::ros::Subscriber &&subscriber);

                AlbRosSubscriber(const AlbRosSubscriber &other)
                        : subscriber_{other.subscriber_} {

                }

                ~AlbRosSubscriber() {
                    // do not destroy publisher
                }

            private:
                ::ros::Subscriber subscriber_;
            };
        }
    }
}

#endif //CAM_DIRECT_CAPTURE_ALB_ROS_SUBSCRIBER_H
