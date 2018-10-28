//
// Created by whymatter on 20.10.18.
//

#ifndef CAM_DIRECT_CAPTURE_CAM_DIRECT_CAPTURE_NODE_H
#define CAM_DIRECT_CAPTURE_CAM_DIRECT_CAPTURE_NODE_H

#include <ros/ros.h>
#include <sensor_msgs/image_encodings.h>
#include <cv_bridge/cv_bridge.h>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>

#include "alb_base/alb_node.h"
#include "alb_base/alb_publisher.h"
#include "opencv_video_capturer.h"

#include "alb_ros_base/alb_ros_node_handle.h"

namespace alb {
    namespace cam {
        namespace direct_capture {
            template<class T>
            class DirectCaptureNode : public ::alb::base::AlbNode<T> {
            public:
                explicit DirectCaptureNode(T &nodeHandle)
                        : ::alb::base::AlbNode<T>(nodeHandle),
                          openCVCapturer_{0} {
                    this->camPublisher_ = this->template Advertise<::cv_bridge::CvImage>("/cam/image");
                }

                void CyclicStep() override {
                    ::boost::optional<::cv::Mat> frame_opt = this->openCVCapturer_.frame();
                    if (frame_opt) {
                        ::cv_bridge::CvImagePtr image_ptr = ::boost::make_shared<::cv_bridge::CvImage>();

                        image_ptr->image = frame_opt.get();
                        image_ptr->encoding = ::sensor_msgs::image_encodings::BGR8;

                        this->camPublisher_.Publish(image_ptr);
                    }
                }

                void Initialize() override {
                    bool success = this->openCVCapturer_.start();
                    if (!success) {
                        ROS_ERROR_STREAM("Failed to open capturing device");
                    } else {
                        ROS_INFO_STREAM("Success, capture device opened");
                    }
                }

            private:
                OpenCVVideoCapturer openCVCapturer_;
                typename T::template Publisher<::cv_bridge::CvImage> camPublisher_;
            };
        }
    }
}

#endif //CAM_DIRECT_CAPTURE_CAM_DIRECT_CAPTURE_NODE_H
