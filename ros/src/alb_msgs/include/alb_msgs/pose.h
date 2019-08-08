//
// Created by whymatter on 28.10.18.
//

#ifndef PROJECT_POSE_H
#define PROJECT_POSE_H

#include <cstdint>
#include <vector>

#include "point.h"

namespace alb {
 namespace alb_msgs {
  struct Pose {
      Point point;

      Pose() = default;

      explicit Pose(Point point_)
              : point(point_) {}
  };
 }
}

#endif //PROJECT_POSE_H