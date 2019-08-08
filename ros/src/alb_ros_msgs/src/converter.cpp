//
// Created by whymatter on 18.12.18.
//

#include "converter.h"

namespace alb {
 namespace alb_ros_msgs {
  // Point
  template<>
  ::alb::alb_msgs::Point Convert(const ::geometry_msgs::Point *ros) {
      return ::alb::alb_msgs::Point{ros->x, ros->y, ros->z};
  }

  template<>
  ::geometry_msgs::Point Convert(const ::alb::alb_msgs::Point *alb) {
      ::geometry_msgs::Point ros;
      ros.x = alb->x;
      ros.y = alb->y;
      ros.z = alb->z;
      return ros;
  }

  // StaticEnvironment
  template<>
  ::alb::alb_msgs::StaticEnvironment Convert(const ::alb_ros_msgs::StaticEnvironment *ros) {
      std::vector<::alb::alb_msgs::Point> cups;
      std::transform(ros->cups.begin(), ros->cups.end(), std::back_inserter(cups),
                     [](const ::geometry_msgs::Point &p) -> ::alb::alb_msgs::Point {
                         return Convert<::geometry_msgs::Point, ::alb::alb_msgs::Point>(p);
                     });
      return ::alb::alb_msgs::StaticEnvironment(cups);
  }

  template<>
  ::alb_ros_msgs::StaticEnvironment Convert(const ::alb::alb_msgs::StaticEnvironment *alb) {
      std::vector<::geometry_msgs::Point> cups;
      std::transform(alb->cups.begin(), alb->cups.end(), std::back_inserter(cups),
                     [](const ::alb::alb_msgs::Point &p) -> ::geometry_msgs::Point {
                         return Convert<::alb::alb_msgs::Point, ::geometry_msgs::Point>(p);
                     });

      ::alb_ros_msgs::StaticEnvironment ros;
      ros.cups = cups;
      return ros;
  }
 }
}