//
// Created by whymatter on 21.10.18.
//

#pragma once

#include <boost/optional.hpp>
#include <opencv2/opencv.hpp>

namespace alb {
    namespace cam {
        namespace direct_capture {
            class OpenCVVideoCapturer {
            public:
                explicit OpenCVVideoCapturer(int32_t camera_index);

                OpenCVVideoCapturer(const OpenCVVideoCapturer &other) = delete; // cant copy::cv::VideoCapture
                ~OpenCVVideoCapturer();

                ::boost::optional<::cv::Mat> frame();

                bool start();

            private:
                ::cv::VideoCapture videoCapture_;
                int32_t camera_index_;
            };
        }
    }
}
