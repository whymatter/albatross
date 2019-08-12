//
// Created by whymatter on 30.10.18.
//

#include "cam_detection_converter.h"

namespace alb {
 namespace alb_ros_msgs {

  ::alb::alb_msgs::CamDetection CamDetectionConverter::Convert(const ::alb_ros_msgs::CamDetection &ros) const {
      return ::alb::alb_msgs::CamDetection{this->boundingBoxConverter_.Convert(ros.boundingBox), ros.propability,
                                           ros.objectId, ros.hue};
  }

  ::alb::alb_msgs::CamDetection CamDetectionConverter::Convert(const ::alb_ros_msgs::CamDetectionPtr &ros) const {
      return ::alb::alb_msgs::CamDetection{this->boundingBoxConverter_.Convert(ros->boundingBox), ros->propability,
                                           ros->objectId, ros->hue};
  }

  ::alb::alb_msgs::CamDetection CamDetectionConverter::Convert(const ::alb_ros_msgs::CamDetectionConstPtr &ros) const {
      return ::alb::alb_msgs::CamDetection{this->boundingBoxConverter_.Convert(ros->boundingBox), ros->propability,
                                           ros->objectId, ros->hue};
  }

  ::alb_ros_msgs::CamDetection CamDetectionConverter::Convert(const ::alb::alb_msgs::CamDetection &alb) const {
      ::alb_ros_msgs::BoundingBox boundingBox;
      boundingBox.x = alb.boundingBox.x;
      boundingBox.y = alb.boundingBox.y;
      boundingBox.w = alb.boundingBox.w;
      boundingBox.h = alb.boundingBox.h;

      ::alb_ros_msgs::CamDetection detection;
      detection.objectId = alb.objectId;
      detection.propability = alb.propability;
      detection.boundingBox = boundingBox;
      detection.hue = alb.hue;

      return detection;
  }
 }
}