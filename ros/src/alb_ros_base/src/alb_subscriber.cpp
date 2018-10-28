//
// Created by whymatter on 21.10.18.
//

#include <alb_ros_subscriber.h>

namespace alb {
    namespace base {
        namespace ros {
            AlbRosSubscriber::AlbRosSubscriber(::ros::Subscriber &&subscriber)
                    : subscriber_(subscriber) {

            }
        }
    }
}