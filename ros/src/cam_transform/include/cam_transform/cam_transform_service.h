//
// Created by whymatter on 17.12.18.
//

#ifndef PROJECT_CAM_TRANSFORM_SERVICE_H
#define PROJECT_CAM_TRANSFORM_SERVICE_H

#include <vector>

#include <ros/ros.h>
#include "cam_transform/ProjectToWorld.h"
#include "alb_msgs/point.h"
#include "alb_ros_msgs/point_converter.h"

namespace alb {
 namespace cam_transform {
  class CamTransformService {
  public:
      explicit CamTransformService(::ros::NodeHandle &nodeHandle);

      ::std::vector<::alb::alb_msgs::Point> ProjectToWorld(const ::std::vector<::alb::alb_msgs::Point> &imagePoints);

  private:
      ::ros::ServiceClient serviceClient_;
      ::alb::alb_ros_msgs::PointConverter pointConverter_{};
  };
 }
}

#endif //PROJECT_CAM_TRANSFORM_SERVICE_H
