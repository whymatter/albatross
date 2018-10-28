//
// Created by whymatter on 28.10.18.
//

#ifndef PROJECT_BOUNDING_BOX_CONVERTER_H
#define PROJECT_BOUNDING_BOX_CONVERTER_H

#include "BoundingBox.h"
#include "alb_msgs/bounding_box.h"

namespace alb {
 namespace alb_ros_msgs {
  class BoundingBoxConverter {
  public:
      BoundingBoxConverter();

      ::alb::alb_msgs::BoundingBox Convert(::alb_ros_msgs::BoundingBox ros);

      ::alb::alb_msgs::BoundingBox Convert(const ::alb_ros_msgs::BoundingBoxPtr &ros);

      ::alb::alb_msgs::BoundingBox Convert(const ::alb_ros_msgs::BoundingBoxConstPtr &ros);
  };
 }
}

#endif //PROJECT_BOUNDING_BOX_CONVERTER_H