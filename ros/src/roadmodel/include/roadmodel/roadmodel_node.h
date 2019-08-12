//
// Created by whymatter on 10.08.19.
//

#pragma once

#include <boost/bind.hpp>
#include <alb_ros_msgs/CamDetections.h>
#include <alb_ros_msgs/StaticEnvironment.h>

#include "alb_base/alb_node.h"

namespace alb {
 namespace roadmodel {
  template<class TNode>
  class RoadmodelNode : public alb::base::AlbNode<TNode> {
  public:
      explicit RoadmodelNode(TNode &nodeHandle)
              : alb::base::AlbNode<TNode>(nodeHandle) {
          ::boost::function<void(const ::alb_ros_msgs::StaticEnvironmentConstPtr &)> boundCallback = ::boost::bind(
                  &RoadmodelNode::EnvironmentCallback, this, _1);
          this->template Subscribe<::alb_ros_msgs::StaticEnvironment>("/static_environment/cups", boundCallback);
      }

      void EnvironmentCallback(const ::alb_ros_msgs::StaticEnvironmentConstPtr &ros) {

      }

      void Initialize() override {}

      void CyclicStep() override {}

  private:
  };
 }
}
