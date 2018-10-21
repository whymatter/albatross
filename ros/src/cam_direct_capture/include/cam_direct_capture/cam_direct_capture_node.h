//
// Created by whymatter on 20.10.18.
//

#ifndef CAM_DIRECT_CAPTURE_CAM_DIRECT_CAPTURE_NODE_H
#define CAM_DIRECT_CAPTURE_CAM_DIRECT_CAPTURE_NODE_H

#include "alb_ros_base/alb_ros_node.h"
#include "opencv_video_capturer.h"

namespace alb {
    namespace cam {
        namespace direct_capture {
            class DirectCaptureNode : public ::alb::base::ros::AlbRosNode {
            public:
                explicit DirectCaptureNode(double loopRate = 10);

                void CyclicStep() override;

            private:
                OpenCVVideoCapturer openCVCapturer_;
            };
        }
    }
}

#endif //CAM_DIRECT_CAPTURE_CAM_DIRECT_CAPTURE_NODE_H
