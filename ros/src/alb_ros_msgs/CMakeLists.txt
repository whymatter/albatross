cmake_minimum_required(VERSION 3.10.2)
project(alb_ros_msgs)

find_package(Boost REQUIRED)

find_package(
        catkin REQUIRED COMPONENTS
        roscpp rospy alb_msgs std_msgs geometry_msgs message_generation
)

add_message_files(
        FILES
        BoundingBox.msg
        CamDetection.msg
        CamDetections.msg
        CupObject.msg
        StaticEnvironment.msg
)

generate_messages(
        DEPENDENCIES
        std_msgs
        geometry_msgs
)

catkin_package(
        INCLUDE_DIRS
        include
        CATKIN_DEPENDS
        alb_msgs
        message_runtime
        LIBRARIES
        ${PROJECT_NAME}
)

if (NOT_CATKIN)
    set(ROS_MSGS_INCLUDE_DIR ${CATKIN_DEVEL_PREFIX}/../../../devel/.private/alb_ros_msgs/include)
endif ()
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME} ${catkin_INCLUDE_DIRS} ${ROS_MSGS_INCLUDE_DIR})

add_library(
        ${PROJECT_NAME}
        include/alb_ros_msgs/bounding_box_converter.h
        include/alb_ros_msgs/cam_detection_converter.h
        include/alb_ros_msgs/cup_object_converter.h
        include/alb_ros_msgs/cam_detections_converter.h
        include/alb_ros_msgs/point_converter.h
        include/alb_ros_msgs/static_environment_converter.h
        include/alb_ros_msgs/pose_with_covariance_converter.h
        include/alb_ros_msgs/pose_converter.h
        src/bounding_box_converter.cpp
        src/cam_detection_converter.cpp
        src/cam_detections_converter.cpp
        src/cup_object_converter.cpp
        src/point_converter.cpp
        src/pose_with_covariance_converter.cpp
        src/static_environment_converter.cpp
        src/pose_converter.cpp)

add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)