#!/bin/bash

guake -r "core" -e "roscore"
guake -n " " -r "rviz" -e "rviz"
guake -n " " -r "cam" -e "rosrun cam_direct_capture cam_direct_capture_node"
guake -n " " -r "detector" -e "rosrun yolo_detector yolo_detector_node"
guake -n " " -r "cam transform" -e "rosrun cam_transform cam_transform_node"
sleep 2 
guake -n " " -r "env" -e "rosrun static_environment static_environment_node"
guake -n " " -r "tf" -e "rosrun tf2_ros static_transform_publisher -0.8 -6 0 0 0 0 camera map"