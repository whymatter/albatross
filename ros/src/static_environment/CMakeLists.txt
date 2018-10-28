cmake_minimum_required(VERSION 3.10.2)
project(static_environment)

find_package(Boost REQUIRED)

get_property(OpenCV_DIR GLOBAL PROPERTY OpenCV_DIR)

find_package(
        catkin REQUIRED COMPONENTS
        roscpp alb_ros_base OpenCV
)

catkin_package(
        INCLUDE_DIRS
            include
        CATKIN_DEPENDS
            alb_ros_base
            std_msgs
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME} ${catkin_INCLUDE_DIRS})

add_executable(
        ${PROJECT_NAME}
        src/main.cpp
        include/static_environment/static_environment_node.h src/static_environment_node.cpp)
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})