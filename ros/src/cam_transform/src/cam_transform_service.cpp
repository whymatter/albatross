//
// Created by whymatter on 17.12.18.
//

#include <cam_transform_service.h>

namespace alb {
 namespace cam_transform {
  CamTransformService::CamTransformService(::ros::NodeHandle &nodeHandle)
          : serviceClient_{nodeHandle.serviceClient<::cam_transform::ProjectToWorld>("/cam/project_to_world")} {}

  ::std::vector<::alb::alb_msgs::Point>
  CamTransformService::ProjectToWorld(const ::std::vector<::alb::alb_msgs::Point> &imagePoints) {
      ::cam_transform::ProjectToWorld projectToWorldService;

      for (auto& imagePoint : imagePoints) {
          ::geometry_msgs::Point p = this->pointConverter_.Convert(imagePoint);
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
                     [this](const ::geometry_msgs::Point &ros) -> ::alb::alb_msgs::Point { return this->pointConverter_.Convert(ros); });

      return objectPoints;
  }
 }
}