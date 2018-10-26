//
// Created by whymatter on 21.10.18.
//

#ifndef CAM_DIRECT_CAPTURE_ALB_ROS_PUBLISHER_H
#define CAM_DIRECT_CAPTURE_ALB_ROS_PUBLISHER_H

#include <ros/ros.h>
#include <boost/shared_ptr.hpp>

namespace alb {
    namespace base {
        namespace ros {
            class AlbRosPublisher {
            public:
                explicit AlbRosPublisher() = default;

                AlbRosPublisher(::ros::Publisher publisher);

                AlbRosPublisher(const AlbRosPublisher &other); // think about it first
                ~AlbRosPublisher();

                template<class M>
                void publish(const M &message) {
                    this->publisher_.publish(message);
                }

                template<class M>
                void publish(const ::boost::shared_ptr<M> &message) {
                    this->publisher_.publish(message);
                }

            private:
                ::ros::Publisher publisher_;
            };
        }
    }
}

#endif //CAM_DIRECT_CAPTURE_ALB_ROS_PUBLISHER_H
