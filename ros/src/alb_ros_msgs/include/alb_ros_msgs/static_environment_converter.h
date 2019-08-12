//
// Created by whymatter on 12.08.19.
//

#ifndef STATIC_ENVIRONMENT_CONVERTER_H
#define STATIC_ENVIRONMENT_CONVERTER_H

#include <cstdint>

#include "alb_ros_msgs/StaticEnvironment.h"
#include "alb_ros_msgs/CupObject.h"
#include "alb_msgs/static_environment.h"
#include "alb_msgs/cup_object.h"
#include "cup_object_converter.h"

namespace alb {
 namespace alb_ros_msgs {
  class StaticEnvironmentConverter {
  public:
      ::alb::alb_msgs::StaticEnvironment Convert(const ::alb_ros_msgs::StaticEnvironment &ros) const;

      ::alb::alb_msgs::StaticEnvironment Convert(const ::alb_ros_msgs::StaticEnvironmentPtr &ros) const;

      ::alb::alb_msgs::StaticEnvironment Convert(const ::alb_ros_msgs::StaticEnvironmentConstPtr &ros) const;

      ::alb_ros_msgs::StaticEnvironment Convert(const ::alb::alb_msgs::StaticEnvironment &alb) const;

  private:
      // converter dependencies
      CupObjectConverter cupObjectConverter_;
  };
 }
}

#endif //STATIC_ENVIRONMENT_CONVERTER_H
