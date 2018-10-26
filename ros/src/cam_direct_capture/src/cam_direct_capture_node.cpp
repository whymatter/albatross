//
// Created by whymatter on 20.10.18.
//

#include "cam_direct_capture_node.h"

namespace alb {
    namespace cam {
        namespace direct_capture {
            DirectCaptureNode::DirectCaptureNode(double loopRate)
                    : ::alb::base::ros::AlbRosNode("/cam/direct_capture", loopRate),
                      openCVCapturer_{0} {
                this->camPublisher_ = this->Advertise<::sensor_msgs::Image>("/cam/image");
            }

            void DirectCaptureNode::Initialize() {
                bool success = this->openCVCapturer_.start();
                if (!success) {
                    ROS_ERROR_STREAM("Failed to open capturing device");
                } else {
                    ROS_INFO_STREAM("Success, capture device opened");
                }
            }

            void DirectCaptureNode::CyclicStep() {
                ::boost::optional<::cv::Mat> frame_opt = this->openCVCapturer_.frame();
                if (frame_opt) {
                    ::cv_bridge::CvImagePtr image_ptr = ::boost::make_shared<::cv_bridge::CvImage>();

                    image_ptr->image = frame_opt.get();
                    image_ptr->encoding = ::sensor_msgs::image_encodings::BGR8;

                    this->camPublisher_.publish(image_ptr);
                }
            }
        }
    }
}