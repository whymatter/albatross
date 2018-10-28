//
// Created by whymatter on 27.10.18.
//

#include "detector.h"

namespace alb {
    namespace yolo_detector {
        Detector::Detector(const std::string &configPath, const std::string &weightsPath)
                : detector_{configPath, weightsPath} {

        }

        std::vector<::bbox_t> Detector::Detect(const ::cv::Mat &frame) {
            cv::Mat resized_frame;
            cv::resize(frame, resized_frame, cv::Size(640, 360));
            return this->detector_.detect(resized_frame, 0.2, false);
        }
    }
}