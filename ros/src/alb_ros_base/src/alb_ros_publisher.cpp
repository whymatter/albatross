//
// Created by whymatter on 21.10.18.
//

#include <alb_ros_publisher.h>

namespace alb {
    namespace base {
        namespace ros {
            AlbRosPublisher::AlbRosPublisher(::ros::Publisher publisher)
                    : publisher_(publisher) {

            }

            AlbRosPublisher::~AlbRosPublisher() {
                this->publisher_.shutdown();
            }
        }
    }
}