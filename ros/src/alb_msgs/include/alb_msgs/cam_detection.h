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

      explicit CamDetection() {}

      CamDetection(const BoundingBox &boundingBox_, float propability_, uint32_t objectId_)
              : boundingBox(boundingBox_), propability(propability_), objectId(objectId_) {}

      CamDetection(const BoundingBox &&boundingBox_, float propability_, uint32_t objectId_)
              : boundingBox(boundingBox_), propability(propability_), objectId(objectId_) {}
  };
 }
}

#endif //PROJECT_CAM_DETECTION_H
