//
// Created by whymatter on 27.10.18.
//

#pragma once

#include <string>
#include <vector>

#include <opencv2/opencv.hpp>

#define OPENCV

#include <yolo_v2_class.hpp>
#include "bbox_color_t.h"

namespace alb {
 namespace yolo_detector {
  class DetectorVisualizer {
  public:
      explicit DetectorVisualizer(std::vector<std::string> objectNames);

      ::cv::Mat DrawBoxes(const ::cv::Mat &frame, const std::vector<bbox_color_t> &detections);

  private:
      std::vector<std::string> objectNames_;
  };
 }
}
