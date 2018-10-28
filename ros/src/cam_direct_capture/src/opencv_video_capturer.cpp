//
// Created by whymatter on 21.10.18.
//

#include "opencv_video_capturer.h"

namespace alb {
    namespace cam {
        namespace direct_capture {
            OpenCVVideoCapturer::OpenCVVideoCapturer(int32_t camera_index)
                    : camera_index_{camera_index} {

            }

            OpenCVVideoCapturer::~OpenCVVideoCapturer() {
                this->videoCapture_.release();
            }

            bool OpenCVVideoCapturer::start() {
                bool success = this->videoCapture_.open(this->camera_index_);
                if (success) {
                    this->videoCapture_.set(CV_CAP_PROP_FRAME_WIDTH, 640);
                    this->videoCapture_.set(CV_CAP_PROP_FRAME_HEIGHT, 360);
                    this->videoCapture_.set(CV_CAP_PROP_FPS, 24);
                }

                return success;
            }

            ::boost::optional<::cv::Mat> OpenCVVideoCapturer::frame() {
                // check that device is 'open', if not reopen it
                if (!this->videoCapture_.isOpened() && !this->start()) {
                    return ::boost::optional<::cv::Mat>();
                }

                ::cv::Mat frame;
                this->videoCapture_ >> frame;

                if (frame.empty()) {
                    return ::boost::optional<::cv::Mat>();
                }

                return ::boost::optional<::cv::Mat>(frame);
            }
        }
    }
}