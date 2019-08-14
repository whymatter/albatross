cmake_minimum_required(VERSION 3.10.2)
project(roadmodel)

find_package(Boost REQUIRED)

find_package(
        catkin REQUIRED COMPONENTS
        roscpp alb_ros_base alb_msgs alb_ros_msgs static_environment rviz_visual_tools
)

catkin_package(
        INCLUDE_DIRS
        include
        CATKIN_DEPENDS
        alb_ros_base
        alb_ros_msgs
        rviz_visual_tools
        static_environment
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
        include/roadmodel/roadmodel_node.h
        src/roadmodel_node.cpp include/roadmodel/spline.h)

add_dependencies(${PROJECT_NAME}_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})