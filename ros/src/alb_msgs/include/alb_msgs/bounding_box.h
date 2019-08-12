//
// Created by whymatter on 28.10.18.
//

#pragma once

#include <cstdint>

namespace alb {
 namespace alb_msgs {
  struct BoundingBox {
      uint32_t x, y, w, h;

      BoundingBox() {}

      BoundingBox(uint32_t x_, uint32_t y_, uint32_t w_, uint32_t h_)
              : x(x_), y(y_), w(w_), h(h_) {}
  };
 }
}
