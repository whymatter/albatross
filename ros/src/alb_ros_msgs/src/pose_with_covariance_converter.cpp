//
// Created by whymatter on 28.10.18.
//

#include "pose_with_covariance_converter.h"
#include "pose_converter.h"

namespace alb {
 namespace alb_ros_msgs {
  ::alb::alb_msgs::PoseWithCovariance PoseWithCovarianceConverter::Convert(::geometry_msgs::PoseWithCovariance ros) const {
      static PoseConverter poseConverter;
      return ::alb::alb_msgs::PoseWithCovariance{poseConverter.Convert(ros.pose)};
  }

  ::alb::alb_msgs::PoseWithCovariance PoseWithCovarianceConverter::Convert(const ::geometry_msgs::PoseWithCovariancePtr &ros) const {
      static PoseConverter poseConverter;
      return ::alb::alb_msgs::PoseWithCovariance{poseConverter.Convert(ros->pose)};
  }

  ::alb::alb_msgs::PoseWithCovariance PoseWithCovarianceConverter::Convert(const ::geometry_msgs::PoseWithCovarianceConstPtr &ros) const {
      static PoseConverter poseConverter;
      return ::alb::alb_msgs::PoseWithCovariance{poseConverter.Convert(ros->pose)};
  }
 }
}