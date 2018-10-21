//
// Created by whymatter on 21.10.18.
//

#include "opencv_video_capturer.h"

namespace alb {
    namespace cam {
        namespace direct_capture {
            OpenCVVideoCapturer::OpenCVVideoCapturer(int32_t camera_index)
                    : videoCapture_(::cv::VideoCapture{camera_index}) {

            }

            OpenCVVideoCapturer::~OpenCVVideoCapturer() {
                this->videoCapture_.release();
            }

            ::boost::optional<::cv::Mat> OpenCVVideoCapturer::frame() {
                if (!this->videoCapture_.isOpened()) {
                    return ::boost::optional<::cv::Mat>();
                }

                ::cv::Mat frame;
                this->videoCapture_ >> frame;

                if (frame.empty()) {
                    return ::boost::optional<::cv::Mat>();
                }

                return frame;
            }
        }
    }
}