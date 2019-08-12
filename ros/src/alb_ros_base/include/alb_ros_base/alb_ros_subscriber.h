//
// Created by whymatter on 21.10.18.
//

#pragma once

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
