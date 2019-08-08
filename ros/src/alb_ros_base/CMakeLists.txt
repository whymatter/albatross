cmake_minimum_required(VERSION 3.10.2)
project(alb_ros_base)

find_package(
        catkin REQUIRED COMPONENTS
        roscpp alb_base
)

catkin_package(
        INCLUDE_DIRS
        include
        CATKIN_DEPENDS
        alb_base
        roscpp
        LIBRARIES
        ${PROJECT_NAME}
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/alb_ros_base ${catkin_INCLUDE_DIRS})

add_library(
        ${PROJECT_NAME}
        include/alb_ros_base/alb_ros_node_handle.h
        include/alb_ros_base/alb_ros_subscriber.h
        include/alb_ros_base/alb_ros_publisher.h
        src/alb_ros_node_handle.cpp
        src/alb_subscriber.cpp
)

add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})