cmake_minimum_required(VERSION 2.8.3)
project(cam_label_video)

set(OpenCV_DIR /usr/local/share/OpenCV)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        OpenCV REQUIRED
        )

include_directories(
        /usr/include/opencv2
        ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node node.cpp)

target_link_libraries(${PROJECT_NAME}_node
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS}
        )