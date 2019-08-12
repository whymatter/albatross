//
// Created by whymatter on 28.10.18.
//

#pragma once

#include <cstdint>
#include <vector>

#include "pose.h"

namespace alb {
 namespace alb_msgs {
  struct PoseWithCovariance {
      Pose pose;
      std::vector<float> covariance {6};

      PoseWithCovariance() = default;

      PoseWithCovariance(Pose pose_)
              : pose(pose_), covariance(6) {}

      PoseWithCovariance(Pose pose_, std::vector<float> covariance_)
              : pose(pose_), covariance(covariance_) {}
  };
 }
}
