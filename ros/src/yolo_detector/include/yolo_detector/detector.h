//
// Created by whymatter on 27.10.18.
//

#pragma once

#include <vector>
#include <string>

#include <opencv2/opencv.hpp>

#define OPENCV

#include <yolo_v2_class.hpp>

namespace alb {
    namespace yolo_detector {
        class Detector {
        public:
            Detector(const std::string &configPath, const std::string &weightsPath);

            std::vector<::bbox_t> Detect(const ::cv::Mat &frame);

        private:
            ::Detector detector_;
        };
    }
}

