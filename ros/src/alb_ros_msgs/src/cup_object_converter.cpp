//
// Created by whymatter on 30.10.18.
//

#include "cup_object_converter.h"

namespace alb {
 namespace alb_ros_msgs {

  ::alb::alb_msgs::CupObject CupObjectConverter::Convert(const ::alb_ros_msgs::CupObject &ros) const {
      return ::alb::alb_msgs::CupObject{this->pointConverter_.Convert(ros.coord), ros.propability, ros.hue};
  }

  ::alb::alb_msgs::CupObject CupObjectConverter::Convert(const ::alb_ros_msgs::CupObjectPtr &ros) const {
      return ::alb::alb_msgs::CupObject{this->pointConverter_.Convert(ros->coord), ros->propability, ros->hue};
  }

  ::alb::alb_msgs::CupObject CupObjectConverter::Convert(const ::alb_ros_msgs::CupObjectConstPtr &ros) const {
      return ::alb::alb_msgs::CupObject{this->pointConverter_.Convert(ros->coord), ros->propability, ros->hue};
  }

  ::alb_ros_msgs::CupObject CupObjectConverter::Convert(const ::alb::alb_msgs::CupObject &alb) const {
      ::geometry_msgs::Point coord;
      coord.x = alb.coord.x;
      coord.y = alb.coord.y;
      coord.z = alb.coord.z;

      ::alb_ros_msgs::CupObject cupObject;
      cupObject.coord = coord;
      cupObject.hue = alb.hue;
      cupObject.propability = alb.propability;

      return cupObject;
  }
 }
}