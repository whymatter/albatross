//
// Created by whymatter on 28.10.18.
//

#ifndef PROJECT_CUP_OBJECT_CONVERTER_H
#define PROJECT_CUP_OBJECT_CONVERTER_H

#include "alb_msgs/cup_object.h"
#include "alb_ros_msgs/CupObject.h"
#include "point_converter.h"

namespace alb {
 namespace alb_ros_msgs {
  class CupObjectConverter {
  public:
      ::alb::alb_msgs::CupObject Convert(const ::alb_ros_msgs::CupObject &ros) const;

      ::alb::alb_msgs::CupObject Convert(const ::alb_ros_msgs::CupObjectPtr &ros) const;

      ::alb::alb_msgs::CupObject Convert(const ::alb_ros_msgs::CupObjectConstPtr &ros) const;

      ::alb_ros_msgs::CupObject Convert(const ::alb::alb_msgs::CupObject &alb) const;

  private:
      PointConverter pointConverter_;
  };
 }
}

#endif //PROJECT_CUP_OBJECT_CONVERTER_H
