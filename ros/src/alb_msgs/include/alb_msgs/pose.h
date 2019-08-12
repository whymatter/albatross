//
// Created by whymatter on 28.10.18.
//

#pragma once

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
