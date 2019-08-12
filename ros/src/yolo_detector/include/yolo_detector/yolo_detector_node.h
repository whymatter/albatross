//
// Created by whymatter on 27.10.18.
//

#ifndef PROJECT_CUP_DETECTOR_NODE_H
#define PROJECT_CUP_DETECTOR_NODE_H

#include <sensor_msgs/image_encodings.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv/cv.hpp>

#include "alb_base/alb_node.h"
#include "alb_msgs/cam_detections.h"

#include "alb_ros_msgs/CamDetection.h"
#include "alb_ros_msgs/CamDetections.h"

#include "detector.h"
#include "detector_visualizer.h"
#include "bbox_color_t.h"

#include <iostream>
#include <boost/function.hpp>
#include <boost/bind.hpp>

#include <alb_ros_msgs/cam_detections_converter.h>

#define CONFIG_PATH "/home/whymatter/github.com/AlexeyAB-darknet/cfg/yolov3-albatross.cfg"
#define WEIGHT_PATH "/home/whymatter/github.com/AlexeyAB-darknet/backup-yolov3-training_set_2/yolov3-albatross_2500.weights"

namespace alb {
 namespace yolo_detector {
  bbox_color_t ToBBoxColor(const ::cv_bridge::CvImageConstPtr &image, const bbox_t box) {
      bbox_color_t output = {
              box,
              1
      };

      ::cv::Mat frame;
      // the image comes as BGR (check image->encoding for that)
      ::cv::cvtColor(image->image, frame, ::cv::COLOR_BGR2HSV);

      ROS_INFO_STREAM("calculate color for " << box.x << "," << box.y);

      // crop the image to the region of the bounding box
      ::cv::Rect roi(box.x, box.y, box.w, box.h);
      ::cv::Mat croppedImage = frame(roi);

      // cast to floats
      croppedImage.convertTo(croppedImage, CV_32F);

      // reshape 2D Matrix to 1D Vector, because kmeans operates per row
      croppedImage = croppedImage.reshape(0, 1);

      ::cv::Mat labels;
      ::cv::Mat centers;
      ::cv::kmeans(croppedImage, 2, labels, ::cv::TermCriteria(CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 1000, 0.0001), 5,
                   ::cv::KMEANS_PP_CENTERS, centers);

      ::cv::Vec3f c0 = centers.at<::cv::Vec3f>(0);
      ::cv::Vec3f c1 = centers.at<::cv::Vec3f>(1);

      ROS_INFO_STREAM("L = " << labels.size);
      ROS_INFO_STREAM("C = " << 360.0 / 180 * c0[0] << "," << 100.0 / 255 * c0[1] << "," << 100.0 / 255 * c0[2]);
      ROS_INFO_STREAM("C = " << 360.0 / 180 * c1[0] << "," << 100.0 / 255 * c1[1] << "," << 100.0 / 255 * c1[2]);

      int numNonZero = ::cv::countNonZero(labels);
      int numZero = labels.size[0] - numNonZero;

      // assert that the gap between both clusters is big enough
      ROS_WARN_COND(abs(numZero - numNonZero) > labels.size[0] * 0.3, "cluster almost equal", numNonZero, numZero);

      int majorityIndex = numZero > numNonZero ? 0 : 1;

      ROS_INFO_STREAM("Winning: " << majorityIndex);

      output.dominantColor = centers.at<::cv::Vec3f>(majorityIndex)[0];

      return output;
  }

  template<class TNode>
  class CupDetectorNode : public ::alb::base::AlbNode<TNode> {

  public:
      explicit CupDetectorNode(TNode &nodeHandle)
              : ::alb::base::AlbNode<TNode>(nodeHandle),
                detector_{configFilePath_, weightFilePath_},
                detectorVisualizer_{objectNames_} {
          this->detectionImagePublisher_ = this->template Advertise<::cv_bridge::CvImage>("/detector/image");
          this->detectionsPublisher_ = this->template Advertise<::alb_ros_msgs::CamDetections>("/detector/detections");

          ::boost::function<void(const ::cv_bridge::CvImageConstPtr &)> boundCallback = ::boost::bind(
                  &CupDetectorNode::CamCallback, this, _1);
          this->template Subscribe<::cv_bridge::CvImage>("/cam/image", boundCallback);
      }

      ::std::vector<bbox_color_t>
      AddColors(const std::vector<bbox_t> &detections, const ::cv_bridge::CvImageConstPtr &image) {
          for (auto it = detections.begin(); it != detections.end(); it++) {
              const bbox_t detection = *it;
          }

          std::vector<bbox_color_t> output;
          output.resize(detections.size());
          auto transformLambda = [&](bbox_t box) { return ToBBoxColor(image, box); };
          std::transform(detections.begin(), detections.end(), output.begin(), transformLambda);

          return output;
      }

      void CamCallback(const ::cv_bridge::CvImageConstPtr &image) {
          auto detections = this->detector_.Detect(image->image);
          auto detectionsWithColor = AddColors(detections, image);
          auto visualizedFrame = this->detectorVisualizer_.DrawBoxes(image->image, detectionsWithColor);

          ::cv_bridge::CvImagePtr image_ptr = ::boost::make_shared<::cv_bridge::CvImage>();
          image_ptr->image = visualizedFrame;
          image_ptr->encoding = ::sensor_msgs::image_encodings::BGR8;

          this->detectionImagePublisher_.Publish(image_ptr);

          ::alb::alb_msgs::CamDetections alb_detections;

          std::transform(detectionsWithColor.begin(), detectionsWithColor.end(),
                         std::back_inserter(alb_detections.detections),
                         [this](const ::bbox_color_t &it) -> ::alb::alb_msgs::CamDetection {
                             return ::alb::alb_msgs::CamDetection{
                                     ::alb::alb_msgs::BoundingBox{it.box.x, it.box.y, it.box.w, it.box.h},
                                     it.box.prob, it.box.obj_id, it.dominantColor};
                         });
          ::alb::alb_ros_msgs::CamDetectionsConverter camDetectionsConverter{};
          this->detectionsPublisher_.Publish(camDetectionsConverter.Convert(alb_detections));
      }

      void Initialize() override {

      }

      void CyclicStep() override {

      }

  private:
      typename TNode::template Publisher<::cv_bridge::CvImage> detectionImagePublisher_;
      typename TNode::template Publisher<::alb_ros_msgs::CamDetections> detectionsPublisher_;
      const std::string configFilePath_ = CONFIG_PATH;
      const std::string weightFilePath_ = WEIGHT_PATH;
      Detector detector_;
      std::vector<std::string> objectNames_{"cup"};
      DetectorVisualizer detectorVisualizer_;

  };
 }
}

#endif //PROJECT_CUP_DETECTOR_NODE_H
