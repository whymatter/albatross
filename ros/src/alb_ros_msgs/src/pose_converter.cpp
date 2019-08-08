//
// Created by whymatter on 28.10.18.
//

#include "pose_converter.h"
#include "point_converter.h"

namespace alb {
 namespace alb_ros_msgs {
  ::alb::alb_msgs::Pose PoseConverter::Convert(::geometry_msgs::Pose ros) const {
      static PointConverter pointConverter;
      return ::alb::alb_msgs::Pose{pointConverter.Convert(ros.position)};
  }

  ::alb::alb_msgs::Pose PoseConverter::Convert(const ::geometry_msgs::PosePtr &ros) const {
      static PointConverter pointConverter;
      return ::alb::alb_msgs::Pose{pointConverter.Convert(ros->position)};
  }

  ::alb::alb_msgs::Pose PoseConverter::Convert(const ::geometry_msgs::PoseConstPtr &ros) const {
      static PointConverter pointConverter;
      return ::alb::alb_msgs::Pose{pointConverter.Convert(ros->position)};
  }
 }
}