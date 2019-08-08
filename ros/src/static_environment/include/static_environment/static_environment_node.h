//
// Created by whymatter on 28.10.18.
//

#ifndef PROJECT_STATIC_ENVIRONMENT_NODE_H
#define PROJECT_STATIC_ENVIRONMENT_NODE_H

#include <boost/bind.hpp>

#include "alb_base/alb_node.h"

#include "alb_msgs/cam_detections.h"
#include "alb_msgs/static_environment.h"
#include "alb_ros_msgs/StaticEnvironment.h"
#include "alb_ros_msgs/CamDetections.h"
#include "alb_ros_msgs/cam_detections_converter.h"
#include "alb_ros_msgs/converter.h"

#include "environment_core.h"

#include "cam_transform/cam_transform_service.h"

namespace alb {
 namespace static_environment {
  template<class TNode>
  class StaticEnvironmentNode : public alb::base::AlbNode<TNode> {
  public:
      explicit StaticEnvironmentNode(TNode &nodeHandle)
              : environmentCore_(::alb::cam_transform::CamTransformService(nodeHandle.nodeHandle_)),
                alb::base::AlbNode<TNode>(nodeHandle) {
          ::boost::function<void(const ::alb_ros_msgs::CamDetectionsConstPtr &)> boundCallback = ::boost::bind(
                  &StaticEnvironmentNode::DetectorCallback, this, _1);
          this->template Subscribe<::alb_ros_msgs::CamDetections>("/detector/detections", boundCallback);
          this->staticEnvironmentPublisher_ = this->template Advertise<::alb_ros_msgs::StaticEnvironment>(
                  "/static_environment/cups");
      }

      void DetectorCallback(const ::alb_ros_msgs::CamDetectionsConstPtr &ros) {
          auto cups = this->environmentCore_.CalculateEnvironment(this->camDetectionsConverter_.Convert(ros));
          ::alb::alb_msgs::StaticEnvironment response(cups);
          auto rosResponse = ::alb::alb_ros_msgs::Convert<::alb::alb_msgs::StaticEnvironment, ::alb_ros_msgs::StaticEnvironment>(response);
          this->staticEnvironmentPublisher_.Publish(rosResponse);
      }

      void Initialize() override {}

      void CyclicStep() override {}

  private:
      ::alb::alb_ros_msgs::CamDetectionsConverter camDetectionsConverter_{};
      EnvironmentCore environmentCore_;
      typename TNode::template Publisher<::alb_ros_msgs::StaticEnvironment> staticEnvironmentPublisher_;
  };
 }
}

#endif //PROJECT_STATIC_ENVIRONMENT_NODE_H
