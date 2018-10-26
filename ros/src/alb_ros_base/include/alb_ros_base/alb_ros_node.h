//
// Created by whymatter on 20.10.18.
//

#ifndef PROJECT_ALB_ROS_NODE_H
#define PROJECT_ALB_ROS_NODE_H

#include <ros/ros.h>

#include <functional>
#include <vector>
#include <string>

#include "alb_base/alb_node.h"
#include "alb_ros_subscriber.h"
#include "alb_ros_publisher.h"

namespace alb {
    namespace base {
        namespace ros {
            class AlbRosNode : public ::alb::base::AlbNode {
            public:
                explicit AlbRosNode(std::string nodeName, double loopRate = 10);

                void Initialize() override;

                void RunCyclic() override;

                template<typename T>
                AlbRosSubscriber
                Subscribe(std::string topicName, ::std::function<void(T)> callback, uint32_t queueSize = 1) {
                    AlbRosSubscriber subscriber{this->nodeHandle_.subscribe(topicName, queueSize, callback)};
                    this->subscriber_.push_back(subscriber);
                    return subscriber;
                }

                template<typename T>
                AlbRosPublisher Advertise(std::string topicName, uint32_t queueSize = 1) {
                    AlbRosPublisher publisher{this->nodeHandle_.advertise<T>(topicName, queueSize)};
                    this->publisher_.push_back(publisher);
                    return publisher;
                }

            private:
                ::ros::NodeHandle nodeHandle_;

                ::ros::Rate loopRate_;

                ::std::vector<AlbRosSubscriber> subscriber_;
                ::std::vector<AlbRosPublisher> publisher_;
            };
        }
    }
}

#endif //PROJECT_ALB_ROS_NODE_H
