//
// Created by whymatter on 28.10.18.
//

#ifndef PROJECT_CAM_DETECTIONS_H
#define PROJECT_CAM_DETECTIONS_H

#include <cstdint>
#include <vector>

#include "cam_detection.h"

namespace alb {
 namespace alb_msgs {
  struct CamDetections {
      std::vector<CamDetection> detections;

      CamDetections() = default;

      CamDetections(const std::vector<CamDetection> &detections_)
              : detections(detections_) {}

      CamDetections(const std::vector<CamDetection> &&detections_)
              : detections(detections_) {}
  };
 }
}

#endif //PROJECT_CAM_DETECTIONS_H
