//
// Created by whymatter on 31.10.18.
//

#ifndef PROJECT_ENVIRONMENT_CORE_H
#define PROJECT_ENVIRONMENT_CORE_H

#include "alb_msgs/cam_detections.h"
#include "alb_msgs/cup_object.h"
#include "cam_transform/cam_transform_service.h"

#include <rviz_visual_tools/rviz_visual_tools.h> // has to be moved out later

namespace alb {
 namespace static_environment {
  class EnvironmentCore {
  public:
      explicit EnvironmentCore(::alb::cam_transform::CamTransformService camTransformService);

      std::vector<::alb::alb_msgs::CupObject> CalculateEnvironment(const ::alb::alb_msgs::CamDetections &detections);

  private:
      ::alb::cam_transform::CamTransformService camTransformService_;
      rviz_visual_tools::RvizVisualToolsPtr visual_tools_; // has to be moved out later
  };
 }
}

#endif //PROJECT_ENVIRONMENT_CORE_H
