//
// Created by whymatter on 28.10.18.
//

#ifndef PROJECT_BOUNDING_BOX_H
#define PROJECT_BOUNDING_BOX_H

#include <cstdint>

namespace alb {
 namespace alb_msgs {
  struct BoundingBox {
      uint32_t x, y, w, h;

      BoundingBox(uint32_t x_, uint32_t y_, uint32_t w_, uint32_t h_)
              : x(x_), y(y_), w(w_), h(h_) {}
  };
 }
}

#endif //PROJECT_BOUNDING_BOX_H