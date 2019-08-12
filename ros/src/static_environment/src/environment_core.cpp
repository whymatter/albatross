#include <utility>

//
// Created by whymatter on 31.10.18.
//

#include <iostream>
#include <algorithm>
#include <boost/make_shared.hpp>

#include "environment_core.h"
#include "alb_msgs/point.h"

namespace alb {
 namespace static_environment {
  EnvironmentCore::EnvironmentCore(::alb::cam_transform::CamTransformService camTransformService)
          : camTransformService_{std::move(camTransformService)} {
      this->visual_tools_.reset(new rviz_visual_tools::RvizVisualTools("camera", "/static_environment/marker"));
  }

  std::vector<::alb::alb_msgs::CupObject>
  EnvironmentCore::CalculateEnvironment(const ::alb::alb_msgs::CamDetections &detections) {
      ROS_INFO_STREAM("Received " << detections.detections.size() << " detections");

      std::vector<::alb::alb_msgs::Point> imagePoints;
      std::vector<::alb::alb_msgs::CamDetection> filteredDetections;
      std::vector<::alb::alb_msgs::CupObject> result;

      for (auto &detection : detections.detections) {
          if (detection.propability > 0.5 && detection.propability <= 1.0) {
              auto x = detection.boundingBox.x + detection.boundingBox.w / 2.0;
              auto y = detection.boundingBox.y + detection.boundingBox.h;
              imagePoints.push_back(::alb::alb_msgs::Point(x, y, 0.0));
              filteredDetections.push_back(detection);
//              ROS_INFO_STREAM("image: " << detection.boundingBox.x << "," << detection.boundingBox.y << "," << detection.propability);
          }
      }

      auto objectPoints = this->camTransformService_.ProjectToWorld(imagePoints);


      ROS_INFO_STREAM(objectPoints.size() << " object points");
      this->visual_tools_->deleteAllMarkers();

      int i = 0;
      for (auto &objectPoint : objectPoints) {
          ::geometry_msgs::Pose p;
          p.position.x = objectPoint.x / 100.0;
          p.position.y = objectPoint.y / 100.0;
          p.position.z = objectPoint.z;

          alb_msgs::CamDetection &detection = filteredDetections[i];
          ::alb::alb_msgs::CupObject cup(objectPoint, detection.propability, detection.hue);
          result.push_back(cup);

          this->visual_tools_->publishCylinder(p, rviz_visual_tools::BLUE, .85, .35);
      }

      // Don't forget to trigger the publisher!
      this->visual_tools_->trigger();

      return result;
  }
 }
}