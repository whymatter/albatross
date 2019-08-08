cmake_minimum_required(VERSION 3.10.2)
project(alb_base)

find_package(
        catkin REQUIRED COMPONENTS
)

catkin_package(
        INCLUDE_DIRS
        include/
        LIBRARIES
        ${PROJECT_NAME}
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/alb_base)

add_library(
        ${PROJECT_NAME}
        include/alb_base/alb_node.h
        include/alb_base/alb_publisher.h
        include/alb_base/alb_subscriber.h
)
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)