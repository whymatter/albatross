//
// Created by whymatter on 28.10.18.
//

#pragma once

#include "alb_ros_msgs/BoundingBox.h"
#include "alb_msgs/bounding_box.h"

namespace alb {
 namespace alb_ros_msgs {
  class BoundingBoxConverter {
  public:
      ::alb::alb_msgs::BoundingBox Convert(::alb_ros_msgs::BoundingBox ros) const;

      ::alb::alb_msgs::BoundingBox Convert(const ::alb_ros_msgs::BoundingBoxPtr &ros) const;

      ::alb::alb_msgs::BoundingBox Convert(const ::alb_ros_msgs::BoundingBoxConstPtr &ros) const;
  };
 }
}