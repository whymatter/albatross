//
// Created by whymatter on 21.10.18.
//

#ifndef CAM_DIRECT_CAPTURE_ALB_ROS_PUBLISHER_H
#define CAM_DIRECT_CAPTURE_ALB_ROS_PUBLISHER_H

#include <ros/ros.h>
#include <boost/shared_ptr.hpp>

#include "alb_base/alb_publisher.h"

namespace alb {
    namespace base {
        namespace ros {
            template<class M>
            class AlbRosPublisher : public alb::base::AlbPublisher<M> {
            public:
                explicit AlbRosPublisher() = default;

                explicit AlbRosPublisher(::ros::Publisher &publisher)
                        : publisher_{publisher} {

                }

                explicit AlbRosPublisher(::ros::Publisher &&publisher)
                        : publisher_{publisher} {

                }

                AlbRosPublisher(const AlbRosPublisher &other)
                        : publisher_{other.publisher_} {

                }

                ~AlbRosPublisher() {
                    // do not destroy publisher
                }

                void Publish(const M &message) override {
                    this->publisher_.publish(message);
                }

                void Publish(const ::boost::shared_ptr<M> &message) override {
                    this->publisher_.publish(message);
                }

            private:
                ::ros::Publisher publisher_;
            };
        }
    }
}

#endif //CAM_DIRECT_CAPTURE_ALB_ROS_PUBLISHER_H
