//
// Created by whymatter on 28.09.18.
//

#pragma once

#include "opencv2/opencv.hpp"

cv::Mat intrinsic = (cv::Mat_<double>(
        {1414.25894999856, 0               , 937.625189031865,
         0               , 1411.75549482935, 552.617728282796,
         0               , 0               , 1               })).reshape(3);

cv::Mat distortion = (cv::Mat_<double>({
    /* k1 */  0.029146493259967,
    /* k2 */ -0.221044408671802,
    /* p1 */  0.003460337109318,
    /* p2 */ -3.196073231590876e-04,
    /* k3 */  0.236567290041656}));
