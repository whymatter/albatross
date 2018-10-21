//
// Created by whymatter on 21.10.18.
//

#ifndef CAM_DIRECT_CAPTURE_OPENCV_VIDEO_CAPTURER_H
#define CAM_DIRECT_CAPTURE_OPENCV_VIDEO_CAPTURER_H

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

            private:
                ::cv::VideoCapture videoCapture_;
            };
        }
    }
}

#endif //CAM_DIRECT_CAPTURE_OPENCV_VIDEO_CAPTURER_H
