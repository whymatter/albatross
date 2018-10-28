//
// Created by whymatter on 27.10.18.
//

#ifndef PROJECT_CUP_DETECTOR_NODE_H
#define PROJECT_CUP_DETECTOR_NODE_H

#include <sensor_msgs/image_encodings.h>
#include <cv_bridge/cv_bridge.h>

#include "alb_base/alb_node.h"

#include "detector.h"
#include "detector_visualizer.h"

#include <iostream>
#include <boost/function.hpp>
#include <boost/bind.hpp>

namespace alb {
    namespace yolo_detector {
        template<class TNode>
        class CupDetectorNode : public ::alb::base::AlbNode<TNode> {

        public:
            explicit CupDetectorNode(TNode &nodeHandle)
                    : ::alb::base::AlbNode<TNode>(nodeHandle),
                      detector_{configFilePath_, weightFilePath_},
                      detectorVisualizer_{objectNames_} {
                this->detectionImagePublisher_ = this->template Advertise<::cv_bridge::CvImage>("/detector/image");
                ::boost::function<void(const ::cv_bridge::CvImageConstPtr &)> boundCallback = ::boost::bind(
                        &CupDetectorNode::CamCallback, this, _1);
                this->template Subscribe<::cv_bridge::CvImage>("/cam/image", boundCallback);
            }

            void CamCallback(const ::cv_bridge::CvImageConstPtr &image) {
                std::cout << "CamCallback" << std::endl;
                auto detections = this->detector_.Detect(image->image);
                auto visualizedFrame = this->detectorVisualizer_.DrawBoxes(image->image, detections);

                ::cv_bridge::CvImagePtr image_ptr = ::boost::make_shared<::cv_bridge::CvImage>();
                image_ptr->image = visualizedFrame;
                image_ptr->encoding = ::sensor_msgs::image_encodings::BGR8;

                this->detectionImagePublisher_.Publish(image_ptr);

            }

            void Initialize() override {

            }

            void CyclicStep() override {

            }

        private:
            typename TNode::template Publisher<::cv_bridge::CvImage> detectionImagePublisher_;
            const std::string configFilePath_ = "/home/whymatter/github.com/AlexeyAB-darknet/cfg/yolov3-albatross.cfg";
            const std::string weightFilePath_ = "/home/whymatter/github.com/AlexeyAB-darknet/backup-yolov3-training_set_2/yolov3-albatross_2500.weights";
            Detector detector_;
            std::vector<std::string> objectNames_{"cup"};
            DetectorVisualizer detectorVisualizer_;

        };
    }
}

#endif //PROJECT_CUP_DETECTOR_NODE_H
