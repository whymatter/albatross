cmake_minimum_required(VERSION 3.10.2)
project(cam_direct_capture)

# OpenCV install folder
set(OpenCV_DIR /usr/local/share/OpenCV/)

find_package(Boost REQUIRED)

find_package(
        catkin REQUIRED COMPONENTS
        roscpp alb_ros_base OpenCV cv_bridge
)

catkin_package(
        INCLUDE_DIRS
        include
        CATKIN_DEPENDS
        alb_ros_base
        image_transport
        std_msgs
        sensor_msgs
        cv_bridge
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/cam_direct_capture ${catkin_INCLUDE_DIRS})

add_executable(
        ${PROJECT_NAME}
        include/cam_direct_capture/cam_direct_capture_node.h
        include/cam_direct_capture/opencv_video_capturer.h
        src/cam_direct_capture_node.cpp
        src/opencv_video_capturer.cpp
        src/main.cpp
)
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})