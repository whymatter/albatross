//
// Created by whymatter on 28.10.18.
//

#pragma once

#include <geometry_msgs/Pose.h>
#include "alb_msgs/pose.h"

namespace alb {
 namespace alb_ros_msgs {
  class PoseConverter {
  public:
      ::alb::alb_msgs::Pose Convert(::geometry_msgs::Pose ros) const;

      ::alb::alb_msgs::Pose Convert(const ::geometry_msgs::PosePtr &ros) const;

      ::alb::alb_msgs::Pose Convert(const ::geometry_msgs::PoseConstPtr &ros) const;
  };
 }
}
