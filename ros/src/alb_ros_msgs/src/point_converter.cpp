//
// Created by whymatter on 28.10.18.
//

#include "point_converter.h"

namespace alb {
 namespace alb_ros_msgs {
  ::alb::alb_msgs::Point PointConverter::Convert(const ::geometry_msgs::Point &ros) const {
      return this->Convert<const ::geometry_msgs::Point *>(&ros);
  }

  ::alb::alb_msgs::Point PointConverter::Convert(const ::geometry_msgs::PointPtr &ros) const {
      return this->Convert<const ::geometry_msgs::PointPtr &>(ros);
  }

  ::alb::alb_msgs::Point PointConverter::Convert(const ::geometry_msgs::PointConstPtr &ros) const {
      return this->Convert<const ::geometry_msgs::PointConstPtr &>(ros);
  }

  ::geometry_msgs::Point PointConverter::Convert(const ::alb::alb_msgs::Point &alb) const {
      ::geometry_msgs::Point result;
      result.x = alb.x;
      result.y = alb.y;
      result.z = alb.z;

      return result;
  }
 }
}