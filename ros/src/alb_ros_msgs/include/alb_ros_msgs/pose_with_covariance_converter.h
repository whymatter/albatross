//
// Created by whymatter on 28.10.18.
//

#ifndef PROJECT_POSE_WITH_COVARIANCE_CONVERTER_H
#define PROJECT_POSE_WITH_COVARIANCE_CONVERTER_H

#include <geometry_msgs/PoseWithCovariance.h>
#include "alb_msgs/pose_with_covariance.h"

namespace alb {
 namespace alb_ros_msgs {
  class PoseWithCovarianceConverter {
  public:
      ::alb::alb_msgs::PoseWithCovariance Convert(::geometry_msgs::PoseWithCovariance ros) const;

      ::alb::alb_msgs::PoseWithCovariance Convert(const ::geometry_msgs::PoseWithCovariancePtr &ros) const;

      ::alb::alb_msgs::PoseWithCovariance Convert(const ::geometry_msgs::PoseWithCovarianceConstPtr &ros) const;
  };
 }
}

#endif //PROJECT_POSE_WITH_COVARIANCE_CONVERTER_H
