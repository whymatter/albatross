//
// Created by whymatter on 20.10.18.
//

#include "cam_direct_capture_node.h"

namespace alb {
    namespace cam {
        namespace direct_capture {
            DirectCaptureNode::DirectCaptureNode(double loopRate)
                    : ::alb::base::ros::AlbRosNode("/cam/direct_capture", loopRate),
                      openCVCapturer_(0) {
                this->Advertise("/cam/image");
            }

            void DirectCaptureNode::CyclicStep() {
                ::cv::Mat frame = this->openCVCapturer_.frame();
            }
        }
    }
}