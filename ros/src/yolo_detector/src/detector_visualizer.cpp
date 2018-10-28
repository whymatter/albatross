//
// Created by whymatter on 27.10.18.
//

#include "detector_visualizer.h"

namespace alb {
    namespace yolo_detector {
        DetectorVisualizer::DetectorVisualizer(std::vector<std::string> objectNames) : objectNames_{objectNames} {}

        ::cv::Mat DetectorVisualizer::DrawBoxes(const ::cv::Mat &frame, std::vector<::bbox_t> detections) {
            ::cv::Mat visualizationFrame = frame.clone();

            cv::Scalar color(60, 160, 260);
            for (auto &box : detections) {
                cv::rectangle(visualizationFrame, cv::Rect(box.x, box.y, box.w, box.h), color, 3);

                if (this->objectNames_.size() > box.obj_id) {
                    putText(visualizationFrame, this->objectNames_[box.obj_id], cv::Point2f(box.x, box.y - 10),
                            cv::FONT_HERSHEY_COMPLEX_SMALL, 1,
                            color);
                }

                if (box.track_id > 0) {
                    putText(visualizationFrame, std::to_string(box.track_id), cv::Point2f(box.x + 5, box.y + 15),
                            cv::FONT_HERSHEY_COMPLEX_SMALL,
                            1, color);
                }
            }

            return visualizationFrame;
        }
    }
}