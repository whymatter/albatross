cmake_minimum_required(VERSION 2.8.3)
project(cam-detector)

#set(CMAKE_CXX_FLAGS "-Wl,--verbose")
set(OpenCV_DIR /usr/local/share/OpenCV)

find_package(
        OpenCV REQUIRED
        )

include_directories(/home/whymatter/github.com/AlexeyAB-darknet)
link_directories(/home/whymatter/github.com/AlexeyAB-darknet)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(cam-detector
        main.cpp
        detector_node.cpp
        )

target_link_libraries(cam-detector darknet ${OpenCV_LIBS})
target_link_libraries(cam-detector ${catkin_LIBRARIES})