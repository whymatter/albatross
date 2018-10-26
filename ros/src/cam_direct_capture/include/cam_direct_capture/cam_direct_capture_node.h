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

#include "alb_ros_base/alb_ros_node.h"
#include "opencv_video_capturer.h"

namespace alb {
    namespace cam {
        namespace direct_capture {
            class DirectCaptureNode : public ::alb::base::ros::AlbRosNode {
            public:
                explicit DirectCaptureNode(double loopRate = 10);

                void CyclicStep() override;
                void Initialize() override;

            private:
                OpenCVVideoCapturer openCVCapturer_;
                ::alb::base::ros::AlbRosPublisher camPublisher_;
            };
        }
    }
}

#endif //CAM_DIRECT_CAPTURE_CAM_DIRECT_CAPTURE_NODE_H
