//
// Created by whymatter on 01.11.18.
//

#include <vector>

#include <ros/ros.h>
#include <opencv2/opencv.hpp>

#include "cam_transform/ProjectToWorld.h"

#include "camera_parameters.h"

using cam_transform::ProjectToWorld;


cv::Mat scaledIntrinsic;
cv::Mat inverseRotationMatrix;

bool project_to_world(ProjectToWorld::Request &req, ProjectToWorld::Response &resp) {
    std::vector<cv::Point2d> image_points;
    std::vector<cv::Point2d> image_points_undistorted;
    std::vector<cv::Point3d> object_points;

    if (req.imagePoints.empty()) {
        return true;
    }

    std::transform(req.imagePoints.begin(), req.imagePoints.end(), std::back_inserter(image_points),
                   [](const ::geometry_msgs::Point &p) -> cv::Point2d {
                       return cv::Point2d(p.x, p.y);
                   });

    ::cv::undistortPoints(image_points, image_points_undistorted, scaledIntrinsic, ::alb::cam_transform::distortion);

    for (uint32_t i = 0; i < image_points.size(); ++i) {
        auto &ip = image_points.at(i);
        auto &ipu = image_points_undistorted.at(i);
        ROS_INFO_STREAM("undistort " << ip.x << "," << ip.y << " -> " << ipu.x << "," << ipu.y);

//        auto yc = 1;
//        auto zc = yc / ipu.y;
//        auto xc = ipu.x * zc;
//
//        auto op = cv::Point3d(xc, zc, yc);
//        ROS_INFO_STREAM("cam cords " << xc << "," << yc << "," << zc);

        cv::Point3d A_m_(ipu.x, ipu.y, 1.0);
        auto R_t = cv::Mat(inverseRotationMatrix * ::alb::cam_transform::transform);
        auto R_A_m_ = cv::Mat(inverseRotationMatrix * ::cv::Mat(A_m_));
        auto s = (0 + R_t.at<double>(2)) / R_A_m_.at<double>(2);
        ROS_INFO_STREAM("s " << s);

        auto op = cv::Point3d(cv::Mat(s * R_A_m_ - R_t));
        ROS_INFO_STREAM("world " << op.x << "," << op.y << "," << op.z);

        object_points.push_back(op);
    }

    std::transform(object_points.begin(), object_points.end(), std::back_inserter(resp.worldPoints),
                   [](const cv::Point3d &p) -> geometry_msgs::Point {
                       auto new_p = geometry_msgs::Point();
                       new_p.x = p.x;
                       new_p.y = p.y;
                       new_p.z = p.z;
                       return new_p;
                   });

    return true;
}

int main(int argc, char **argv) {
    ::ros::init(argc, argv, "cam_transform");

    cv::Mat rotationMatrix = cv::Mat(3, 3, CV_32F);
    cv::Rodrigues(::alb::cam_transform::rotation, rotationMatrix);
    inverseRotationMatrix = rotationMatrix.t(); // inverse of a rotation matrix is its transpose

    scaledIntrinsic = ::alb::cam_transform::scaleIntrinsic(1.0 / 3.0);

    ::ros::NodeHandle nodeHandle;
    auto server = nodeHandle.advertiseService("/cam/project_to_world", project_to_world);

    ::ros::spin();
}