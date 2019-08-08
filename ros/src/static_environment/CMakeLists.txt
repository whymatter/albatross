cmake_minimum_required(VERSION 3.10.2)
project(static_environment)

find_package(Boost REQUIRED)

get_property(OpenCV_DIR GLOBAL PROPERTY OpenCV_DIR)

find_package(
        catkin REQUIRED COMPONENTS
        roscpp alb_ros_base OpenCV alb_msgs alb_ros_msgs cam_transform rviz_visual_tools
)

catkin_package(
        INCLUDE_DIRS
            include
        CATKIN_DEPENDS
            alb_ros_base
            alb_ros_msgs
            rviz_visual_tools
            cam_transform
            alb_msgs
            std_msgs
)

if (NOT_CATKIN)
    set(ROS_MSGS_INCLUDE_DIR ${CATKIN_DEVEL_PREFIX}/../../../devel/include)
endif ()
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME} ${catkin_INCLUDE_DIRS} ${ROS_MSGS_INCLUDE_DIR})

add_executable(
        ${PROJECT_NAME}_node
        src/main.cpp
        include/static_environment/static_environment_node.h src/static_environment_node.cpp include/static_environment/environment_core.h src/environment_core.cpp)
add_dependencies(${PROJECT_NAME}_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})