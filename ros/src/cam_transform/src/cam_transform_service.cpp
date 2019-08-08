//
// Created by whymatter on 17.12.18.
//

#include <cam_transform_service.h>
#include "alb_ros_msgs/converter.h"

namespace alb {
 namespace cam_transform {
  CamTransformService::CamTransformService(::ros::NodeHandle &nodeHandle)
          : serviceClient_{nodeHandle.serviceClient<::cam_transform::ProjectToWorld>("/cam/project_to_world")} {}

  ::std::vector<::alb::alb_msgs::Point>
  CamTransformService::ProjectToWorld(const ::std::vector<::alb::alb_msgs::Point> &imagePoints) {
      ::cam_transform::ProjectToWorld projectToWorldService;

      for (auto& imagePoint : imagePoints) {
          ::geometry_msgs::Point p = ::alb::alb_ros_msgs::Convert<::alb::alb_msgs::Point, ::geometry_msgs::Point>(imagePoint);
          projectToWorldService.request.imagePoints.push_back(p);
      }

      bool result = this->serviceClient_.call(projectToWorldService);

      if (!result) {
          throw std::runtime_error("projectToWorld service call failed");
      }

      ::std::vector<::alb::alb_msgs::Point> objectPoints;
      std::transform(projectToWorldService.response.worldPoints.begin(),
                     projectToWorldService.response.worldPoints.end(),
                     ::std::back_inserter(objectPoints),
                     [](const ::geometry_msgs::Point &ros) -> ::alb::alb_msgs::Point { return ::alb::alb_ros_msgs::Convert<::geometry_msgs::Point, ::alb::alb_msgs::Point>(ros); });

      return objectPoints;
  }
 }
}