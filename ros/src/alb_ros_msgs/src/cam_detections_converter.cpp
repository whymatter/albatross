//
// Created by whymatter on 30.10.18.
//

#include "cam_detections_converter.h"

namespace alb {
 namespace alb_ros_msgs {

  ::alb::alb_msgs::CamDetections CamDetectionsConverter::Convert(const ::alb_ros_msgs::CamDetections &ros) const {
      auto detections = ::alb::alb_msgs::CamDetections{};
      std::transform(ros.detections.begin(), ros.detections.end(),
                     std::back_inserter(detections.detections),
                     [this](const ::alb_ros_msgs::CamDetection &detection) -> ::alb::alb_msgs::CamDetection {
                         this->camDetectionConverter_.Convert(detection);
                     });
      return detections;
  }

  ::alb::alb_msgs::CamDetections CamDetectionsConverter::Convert(const ::alb_ros_msgs::CamDetectionsPtr &ros) const {
      auto detections = ::alb::alb_msgs::CamDetections{};
      std::transform(ros->detections.begin(), ros->detections.end(),
                     std::back_inserter(detections.detections),
                     [this](const ::alb_ros_msgs::CamDetection &detection) -> ::alb::alb_msgs::CamDetection {
                         this->camDetectionConverter_.Convert(detection);
                     });
      return detections;
  }

  ::alb::alb_msgs::CamDetections
  CamDetectionsConverter::Convert(const ::alb_ros_msgs::CamDetectionsConstPtr &ros) const {
      auto detections = ::alb::alb_msgs::CamDetections{};
      std::transform(ros->detections.begin(), ros->detections.end(),
                     std::back_inserter(detections.detections),
                     [this](const ::alb_ros_msgs::CamDetection &detection) -> ::alb::alb_msgs::CamDetection {
                         return this->camDetectionConverter_.Convert(detection);
                     });
      return detections;
  }

  ::alb_ros_msgs::CamDetections CamDetectionsConverter::Convert(const ::alb::alb_msgs::CamDetections &alb) const {
      auto detections = ::alb_ros_msgs::CamDetections{};
      std::transform(alb.detections.begin(), alb.detections.end(),
                     std::back_inserter(detections.detections),
                     [this](const ::alb::alb_msgs::CamDetection &detection) -> ::alb_ros_msgs::CamDetection {
                         return this->camDetectionConverter_.Convert(detection);
                     });
      return detections;
  }
 }
}