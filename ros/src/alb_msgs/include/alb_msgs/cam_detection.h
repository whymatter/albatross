//
// Created by whymatter on 28.10.18.
//

#ifndef PROJECT_CAM_DETECTION_H
#define PROJECT_CAM_DETECTION_H

#include <cstdint>

#include "bounding_box.h"

namespace alb {
 namespace alb_msgs {
  struct CamDetection {
      BoundingBox boundingBox;
      float propability;
      uint32_t objectId;
  };
 }
}

#endif //PROJECT_CAM_DETECTION_H
