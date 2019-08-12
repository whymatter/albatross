//
// Created by whymatter on 28.10.18.
//

#ifndef PROJECT_CUP_OBJECT_H
#define PROJECT_CUP_OBJECT_H

#include <cstdint>

#include "point.h"

namespace alb {
 namespace alb_msgs {
  struct CupObject {
      Point coord;
      float propability;
      float hue;

      explicit CupObject() {}

      CupObject(const Point &coord_, float propability_, float hue_)
              : coord(coord_), propability(propability_), hue(hue_) {}

      CupObject(const Point &&coord_, float propability_, float hue_)
              : coord(coord_), propability(propability_), hue(hue_) {}
  };
 }
}

#endif //PROJECT_CUP_OBJECT_H
