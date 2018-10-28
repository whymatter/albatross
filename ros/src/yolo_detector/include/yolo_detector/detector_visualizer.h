//
// Created by whymatter on 27.10.18.
//

#ifndef PROJECT_DETECTOR_VISUALIZER_H
#define PROJECT_DETECTOR_VISUALIZER_H

#include <string>
#include <vector>

#include <opencv2/opencv.hpp>

#define OPENCV

#include <yolo_v2_class.hpp>

namespace alb {
    namespace yolo_detector {
        class DetectorVisualizer {
        public:
            explicit DetectorVisualizer(std::vector<std::string> objectNames);

            ::cv::Mat DrawBoxes(const ::cv::Mat &frame, std::vector<::bbox_t> detections);

        private:
            std::vector<std::string> objectNames_;
        };
    }
}

#endif //PROJECT_DETECTOR_VISUALIZER_H
