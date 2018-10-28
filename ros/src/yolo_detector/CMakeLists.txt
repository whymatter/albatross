cmake_minimum_required(VERSION 3.10.2)
project(yolo_detector)

find_package(Boost REQUIRED)

get_property(OpenCV_DIR GLOBAL PROPERTY OpenCV_DIR)
get_property(Darknet_include_DIR GLOBAL PROPERTY Darknet_include_DIR)
get_property(Darknet_link_DIR GLOBAL PROPERTY Darknet_link_DIR)

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

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME} ${Darknet_include_DIR} ${catkin_INCLUDE_DIRS})
link_directories(${Darknet_link_DIR})

add_executable(
        ${PROJECT_NAME}
        include/yolo_detector/yolo_detector_node.h
        include/yolo_detector/detector.h
        include/yolo_detector/detector_visualizer.h
        src/yolo_detector_node.cpp
        src/main.cpp
        src/darknet_main.cpp
        src/detector.cpp
        src/detector_visualizer.cpp
        ../alb_msgs/include/alb_msgs/bounding_box.h)
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME} darknet ${catkin_LIBRARIES})