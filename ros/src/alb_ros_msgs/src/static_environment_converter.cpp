//
// Created by whymatter on 12.08.19.
//

#include "static_environment_converter.h"

namespace alb {
 namespace alb_ros_msgs {

  ::alb::alb_msgs::StaticEnvironment
  StaticEnvironmentConverter::Convert(const ::alb_ros_msgs::StaticEnvironment &ros) const {
      auto result = ::alb::alb_msgs::StaticEnvironment{};
//      std::transform(ros.cups.begin(), ros.cups.end(),
//                     std::back_inserter(result.cups),
//                     [this](const ::alb_ros_msgs::CupObject &cup) -> ::alb::alb_msgs::CupObject {
//                         this->cupObjectConverter_.Convert(cup);
//                     });
      return result;
  }

  ::alb::alb_msgs::StaticEnvironment
  StaticEnvironmentConverter::Convert(const ::alb_ros_msgs::StaticEnvironmentPtr &ros) const {
      auto result = ::alb::alb_msgs::StaticEnvironment{};
      std::transform(ros->cups.begin(), ros->cups.end(),
                     std::back_inserter(result.cups),
                     [this](const ::alb_ros_msgs::CupObject &cup) -> ::alb::alb_msgs::CupObject {
                         this->cupObjectConverter_.Convert(cup);
                     });

      return result;
  }

  ::alb::alb_msgs::StaticEnvironment
  StaticEnvironmentConverter::Convert(const ::alb_ros_msgs::StaticEnvironmentConstPtr &ros) const {
      auto result = ::alb::alb_msgs::StaticEnvironment{};
      std::transform(ros->cups.begin(), ros->cups.end(),
                     std::back_inserter(result.cups),
                     [this](const ::alb_ros_msgs::CupObject &cup) -> ::alb::alb_msgs::CupObject {
                         this->cupObjectConverter_.Convert(cup);
                     });

      return result;
  }

  ::alb_ros_msgs::StaticEnvironment
  StaticEnvironmentConverter::Convert(const ::alb::alb_msgs::StaticEnvironment &alb) const {
      ::alb_ros_msgs::StaticEnvironment result;
      std::transform(alb.cups.begin(), alb.cups.end(), std::back_inserter(result.cups),
                     [this](const ::alb::alb_msgs::CupObject &cup) -> ::alb_ros_msgs::CupObject {
                         return this->cupObjectConverter_.Convert(cup);
                     });

      return result;
  }
 }
}