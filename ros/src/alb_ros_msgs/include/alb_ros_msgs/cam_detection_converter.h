//
// Created by whymatter on 28.10.18.
//

#ifndef PROJECT_CAM_DETECTION_CONVERTER_H
#define PROJECT_CAM_DETECTION_CONVERTER_H

#include <cstdint>

#include "bounding_box_converter.h"

#include "alb_ros_msgs/CamDetection.h"
#include "alb_msgs/cam_detection.h"

namespace alb {
 namespace alb_ros_msgs {
  class CamDetectionConverter {
  public:
      ::alb::alb_msgs::CamDetection Convert(const ::alb_ros_msgs::CamDetection &ros) const;

      ::alb::alb_msgs::CamDetection Convert(const ::alb_ros_msgs::CamDetectionPtr &ros) const;

      ::alb::alb_msgs::CamDetection Convert(const ::alb_ros_msgs::CamDetectionConstPtr &ros) const;

      ::alb_ros_msgs::CamDetection Convert(const ::alb::alb_msgs::CamDetection &alb) const;

  private:
      BoundingBoxConverter boundingBoxConverter_;
  };
 }
}

#endif //PROJECT_CAM_DETECTION_CONVERTER_H
