//
// Created by whymatter on 28.10.18.
//

#pragma once

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
