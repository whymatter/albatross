cmake_minimum_required(VERSION 3.10.2)
project(alb_ros_msgs)

find_package(Boost REQUIRED)

find_package(
        catkin REQUIRED COMPONENTS
        roscpp rospy alb_msgs std_msgs message_generation
)

add_message_files(
        FILES
        BoundingBox.msg
        CamDetection.msg
)

generate_messages(
        DEPENDENCIES
        std_msgs
)

catkin_package(
        INCLUDE_DIRS
            include
        CATKIN_DEPENDS
            message_runtime
)

set(ROS_MSGS_INCLUDE_DIR ${CATKIN_DEVEL_PREFIX}/../../../devel/${CATKIN_PACKAGE_INCLUDE_DESTINATION})
message(STATUS ${ROS_MSGS_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME} ${catkin_INCLUDE_DIRS}, ${ROS_MSGS_INCLUDE_DIR})

add_library(
        ${PROJECT_NAME}
        include/alb_ros_msgs/bounding_box_converter.h include/alb_ros_msgs/cam_detection_converter.h src/bounding_box_converter.cpp)

add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)