cmake_minimum_required(VERSION 2.8.3)
project(cam_calc_extrinsic)

set(OpenCV_DIR /usr/local/share/OpenCV)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        OpenCV REQUIRED
        )

include_directories(
        ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node node.cpp
        intrinsic_parameters.h)

target_link_libraries(${PROJECT_NAME}_node
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS}
        )