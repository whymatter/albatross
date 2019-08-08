//
// Created by whymatter on 26.10.18.
//

#ifndef PROJECT_ALB_ROS_NODE_HANDLE_H
#define PROJECT_ALB_ROS_NODE_HANDLE_H

#include <string>
#include <boost/function.hpp>
#include <ros/ros.h>

#include "alb_ros_subscriber.h"
#include "alb_ros_publisher.h"

namespace alb {
 namespace base {
  namespace ros {
   class AlbRosNodehandle {
   public:
       template<class T>
       using Publisher = ros::AlbRosPublisher<T>;

       using Subscriber = ros::AlbRosSubscriber;

       explicit AlbRosNodehandle(std::string nodeName, double loopRate = 10);

       bool Abort();

       void InternalCyclicStep();

       template<typename T>
       Subscriber
       Subscribe(std::string topicName, const boost::function<void(const boost::shared_ptr<T const> &)> &callback,
                 uint32_t queueSize = 1) {
           AlbRosSubscriber subscriber{this->nodeHandle_.subscribe<T>(topicName, queueSize, callback)};
           this->subscriber_.push_back(subscriber);
           return subscriber;
       }

       template<typename T>
       Publisher<T> Advertise(std::string topicName, uint32_t queueSize = 1) {
           AlbRosPublisher<T> publisher{this->nodeHandle_.advertise<T>(topicName, queueSize)};
           return publisher;
       }

       ::ros::NodeHandle nodeHandle_;
   private:

       ::ros::Rate loopRate_;

       ::std::vector<AlbRosSubscriber> subscriber_;
   };
  }
 }
}

#endif //PROJECT_ALB_ROS_NODE_HANDLE_H
