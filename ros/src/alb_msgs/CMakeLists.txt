cmake_minimum_required(VERSION 3.10.2)
project(alb_msgs)

find_package(Boost REQUIRED)

find_package(
        catkin REQUIRED COMPONENTS
)

catkin_package(
        INCLUDE_DIRS
            include
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME} ${catkin_INCLUDE_DIRS})

add_library(
        ${PROJECT_NAME}
        include/alb_msgs/bounding_box.h
        include/alb_msgs/cam_detection.h
        include/alb_msgs/cam_detections.h
        include/alb_msgs/point.h
        include/alb_msgs/pose.h
        include/alb_msgs/pose_with_covariance.h
        include/alb_msgs/static_environment.h)

add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)