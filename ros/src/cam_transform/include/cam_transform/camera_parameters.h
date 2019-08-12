//
// Created by whymatter on 28.09.18.
//

#pragma once

#include "opencv2/opencv.hpp"

#define INTRINSIC_1 1414.25894999856, 0               , 937.625189031865
#define INTRINSIC_2 0               , 1411.75549482935, 552.617728282796
#define INTRINSIC_3 0               , 0               , 1

#define TRANSFORM_1 -105.03213579
#define TRANSFORM_2 55.22556852
#define TRANSFORM_3 495.64449151

#define ROTATION_1 1.91950838
#define ROTATION_2 -0.03099074
#define ROTATION_3 -0.02025576

namespace alb {
 namespace cam_transform {

  cv::Mat intrinsic = (cv::Mat_<double>(
          {INTRINSIC_1,
           INTRINSIC_2,
           INTRINSIC_3})).reshape(1, 3);

  cv::Mat scaleIntrinsic(float scale) {
      cv::Mat scaleMatrix = (cv::Mat_<double>(3, 3) << scale, 0, scale, 0, scale, scale, 0, 0, 1);
      return intrinsic.mul(scaleMatrix);
  }

  cv::Mat transform = (cv::Mat_<double>(
          {TRANSFORM_1,
           TRANSFORM_2,
           TRANSFORM_3}));

  cv::Mat rotation = (cv::Mat_<double>(
          {ROTATION_1,
           ROTATION_2,
           ROTATION_3}));

  cv::Mat distortion = (cv::Mat_<double>({
                                                 /* k1 */  0.029146493259967,
                                                 /* k2 */ -0.221044408671802,
                                                 /* p1 */  0.003460337109318,
                                                 /* p2 */ -3.196073231590876e-04,
                                                 /* k3 */  0.236567290041656}));
 }
}
