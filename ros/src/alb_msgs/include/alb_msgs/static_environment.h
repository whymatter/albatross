//
// Created by whymatter on 28.10.18.
//

#ifndef PROJECT_STATIC_ENVIRONMENT_H
#define PROJECT_STATIC_ENVIRONMENT_H

#include <cstdint>
#include <vector>

#include "point.h"

namespace alb {
 namespace alb_msgs {
  struct StaticEnvironment {
      std::vector <Point> cups;

      StaticEnvironment() = default;

      explicit StaticEnvironment(std::vector <Point> cups_)
              : cups(cups_) {}
  };
 }
}

#endif //PROJECT_STATIC_ENVIRONMENT_H