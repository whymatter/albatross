//
// Created by whymatter on 28.10.18.
//

#ifndef PROJECT_POINT_CONVERTER_H
#define PROJECT_POINT_CONVERTER_H

#include <geometry_msgs/Point.h>
#include "alb_msgs/point.h"

namespace alb {
 namespace alb_ros_msgs {
  class PointConverter {
  public:
      template<class M>
      ::alb::alb_msgs::Point Convert(M ros) const {
          return ::alb::alb_msgs::Point{ros->x, ros->y, ros->z};
      }

      ::alb::alb_msgs::Point Convert(const ::geometry_msgs::Point &ros) const;

      ::alb::alb_msgs::Point Convert(const ::geometry_msgs::PointPtr &ros) const;

      ::alb::alb_msgs::Point Convert(const ::geometry_msgs::PointConstPtr &ros) const;

      ::geometry_msgs::Point Convert(const ::alb::alb_msgs::Point &alb) const;
  };
 }
}

#endif //PROJECT_POINT_CONVERTER_H
