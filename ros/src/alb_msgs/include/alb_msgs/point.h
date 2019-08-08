//
// Created by whymatter on 28.10.18.
//

#ifndef PROJECT_POINT_H
#define PROJECT_POINT_H

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

#endif //PROJECT_POINT_H