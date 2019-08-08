//
// Created by whymatter on 17.12.18.
//

#ifndef PROJECT_CONVERTER_H
#define PROJECT_CONVERTER_H

#include <stdexcept>
#include <boost/shared_ptr.hpp>

#include "alb_ros_msgs/StaticEnvironment.h"
#include <geometry_msgs/Point.h>
#include "alb_msgs/point.h"
#include "alb_msgs/static_environment.h"
//#include "../../../../devel/include/alb_ros_msgs/StaticEnvironment.h"

namespace alb {
 namespace alb_ros_msgs {
  template<class M, class R>
  R Convert(M const *msg) {
      throw std::runtime_error("no Convert implementation provided");
  }

  template<class M, class R>
  R Convert(const M &msg) {
      return Convert<M, R>(&msg);
  }

  template<class M, class R>
  R Convert(const boost::shared_ptr<M> &msg) {
      return Convert<M, R>(msg.get());
  }

  template<class M, class R>
  R Convert(const boost::shared_ptr<M const> &msg) {
      return Convert<M, R>(msg.get());
  }

  // Point
  template<>
  ::alb::alb_msgs::Point Convert(const ::geometry_msgs::Point *ros);

  template<>
  ::geometry_msgs::Point Convert(const ::alb::alb_msgs::Point *alb);

  // Static Environment
  template<>
  ::alb::alb_msgs::StaticEnvironment Convert(const ::alb_ros_msgs::StaticEnvironment *ros);

  template<>
  ::alb_ros_msgs::StaticEnvironment Convert(const ::alb::alb_msgs::StaticEnvironment *alb);
 }
}

#endif //PROJECT_CONVERTER_H
