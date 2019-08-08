cmake_minimum_required(VERSION 3.10.2)
project(cam_transform)

find_package(Boost REQUIRED)

get_property(OpenCV_DIR GLOBAL PROPERTY OpenCV_DIR)

find_package(
        catkin REQUIRED COMPONENTS
        message_generation roscpp geometry_msgs alb_msgs alb_ros_msgs OpenCV
)

add_service_files(
        FILES
        ProjectToWorld.srv
)

generate_messages(
        DEPENDENCIES
        geometry_msgs
)

catkin_package(
        INCLUDE_DIRS
        include
        CATKIN_DEPENDS
        alb_msgs
        alb_ros_msgs
        geometry_msgs
        message_runtime
        LIBRARIES
        ${PROJECT_NAME}
)

if (NOT_CATKIN)
    set(ROS_MSGS_INCLUDE_DIR ${CATKIN_DEVEL_PREFIX}/../../../devel/.private/cam_transform/include)
endif ()
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME} ${catkin_INCLUDE_DIRS} ${ROS_MSGS_INCLUDE_DIR})

add_library(
        ${PROJECT_NAME}
        include/${PROJECT_NAME}/camera_parameters.h
        include/cam_transform/cam_transform_service.h
        src/cam_transform_service.cpp)
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_executable(
        ${PROJECT_NAME}_node
        src/main.cpp)
add_dependencies(${PROJECT_NAME}_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES} ${PROJECT_NAME})