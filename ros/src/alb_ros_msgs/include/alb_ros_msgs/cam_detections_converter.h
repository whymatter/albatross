//
// Created by whymatter on 28.10.18.
//

#pragma once

#include <cstdint>

#include "cam_detection_converter.h"

#include "alb_ros_msgs/CamDetections.h"
#include "alb_msgs/cam_detections.h"

namespace alb {
 namespace alb_ros_msgs {
  class CamDetectionsConverter {
  public:
      ::alb::alb_msgs::CamDetections Convert(const ::alb_ros_msgs::CamDetections &ros) const;

      ::alb::alb_msgs::CamDetections Convert(const ::alb_ros_msgs::CamDetectionsPtr &ros) const;

      ::alb::alb_msgs::CamDetections Convert(const ::alb_ros_msgs::CamDetectionsConstPtr &ros) const;

      ::alb_ros_msgs::CamDetections Convert(const ::alb::alb_msgs::CamDetections &alb) const;

  private:
      CamDetectionConverter camDetectionConverter_;
  };
 }
}
