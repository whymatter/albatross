//
// Created by whymatter on 28.10.18.
//

#ifndef PROJECT_STATIC_ENVIRONMENT_H
#define PROJECT_STATIC_ENVIRONMENT_H

#include <cstdint>
#include <utility>
#include <vector>

#include "point.h"
#include "cup_object.h"

namespace alb {
 namespace alb_msgs {
  struct StaticEnvironment {
      std::vector<CupObject> cups;

      StaticEnvironment() = default;

      explicit StaticEnvironment(std::vector<CupObject> cups_)
              : cups(std::move(cups_)) {}
  };
 }
}

#endif //PROJECT_STATIC_ENVIRONMENT_H