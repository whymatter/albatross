//
// Created by whymatter on 28.10.18.
//

#include "bounding_box_converter.h"

namespace alb {
 namespace alb_ros_msgs {

  BoundingBoxConverter::BoundingBoxConverter() = default;

  ::alb::alb_msgs::BoundingBox BoundingBoxConverter::Convert(::alb_ros_msgs::BoundingBox ros) {
      return ::alb::alb_msgs::BoundingBox{ros.x, ros.y, ros.w, ros.h};
  }

  ::alb::alb_msgs::BoundingBox BoundingBoxConverter::Convert(const ::alb_ros_msgs::BoundingBoxPtr &ros) {
      return ::alb::alb_msgs::BoundingBox{ros->x, ros->y, ros->w, ros->h};
  }

  ::alb::alb_msgs::BoundingBox BoundingBoxConverter::Convert(const ::alb_ros_msgs::BoundingBoxConstPtr &ros) {
      return ::alb::alb_msgs::BoundingBox{ros->x, ros->y, ros->w, ros->h};
  }
 }
}