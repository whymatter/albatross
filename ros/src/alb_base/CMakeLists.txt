cmake_minimum_required(VERSION 3.10.2)
project(alb_base)

find_package(
        catkin REQUIRED COMPONENTS
)

catkin_package(
        INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
        LIBRARIES
        ${PROJECT_NAME}
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/alb_base)

add_library(
        ${PROJECT_NAME}
        include/alb_base/alb_node.h
        src/alb_node.cpp
)
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})

#target_include_directories(
#        ${PROJECT_NAME}
#        PUBLIC
#        ${CMAKE_SOURCE_DIR}/include/
#        PRIVATE
#        ${CMAKE_SOURCE_DIR}/include/alb_base
#)
#
#target_link_libraries(
#        ${PROJECT_NAME}
#)