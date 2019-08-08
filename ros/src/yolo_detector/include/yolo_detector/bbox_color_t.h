//
// Created by whymatter on 08.08.19.
//

#ifndef CAM_BBOX_COLOR_T_H
#define CAM_BBOX_COLOR_T_H

#include <yolo_v2_class.hpp>

struct bbox_color_t {
    bbox_t box;
    float dominantColor;
};

#endif //CAM_BBOX_COLOR_T_H
