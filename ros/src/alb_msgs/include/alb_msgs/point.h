//
// Created by whymatter on 28.10.18.
//

#pragma once

#include <cstdint>

namespace alb {
 namespace alb_msgs {
  struct Point {
      double x, y, z;

      Point() = default;

      Point(double x_, double y_, double z_)
              : x(x_), y(y_), z(z_) {}
  };
 }
}
