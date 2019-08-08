cmake_minimum_required(VERSION 3.10.2)
project(yolo_detector)

find_package(Boost REQUIRED)

get_property(OpenCV_DIR GLOBAL PROPERTY OpenCV_DIR)
get_property(Darknet_include_DIR GLOBAL PROPERTY Darknet_include_DIR)
get_property(Darknet_link_DIR GLOBAL PROPERTY Darknet_link_DIR)

message(STATUS, "${Darknet_link_DIR}")

find_package(
        catkin REQUIRED COMPONENTS
        roscpp alb_ros_base OpenCV cv_bridge alb_msgs alb_ros_msgs
)

catkin_package(
        INCLUDE_DIRS
            include
        CATKIN_DEPENDS
            alb_ros_base
            alb_ros_msgs
            image_transport
            std_msgs
            sensor_msgs
            cv_bridge
)

if (NOT_CATKIN)
    set(ROS_MSGS_INCLUDE_DIR ${CATKIN_DEVEL_PREFIX}/../../../devel/include)
endif ()
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME} ${Darknet_include_DIR} ${catkin_INCLUDE_DIRS} ${ROS_MSGS_INCLUDE_DIR})
link_directories(${Darknet_link_DIR})

add_executable(
        ${PROJECT_NAME}_node
        include/yolo_detector/yolo_detector_node.h
        include/yolo_detector/detector.h
        include/yolo_detector/detector_visualizer.h
        src/yolo_detector_node.cpp
        src/main.cpp
        src/darknet_main.cpp
        src/detector.cpp
        src/detector_visualizer.cpp include/yolo_detector/bbox_color_t.h)
add_dependencies(${PROJECT_NAME}_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_node darknet ${catkin_LIBRARIES})