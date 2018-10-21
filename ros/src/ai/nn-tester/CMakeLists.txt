cmake_minimum_required(VERSION 2.8.3)
project(nn-tester)

#set(CMAKE_CXX_FLAGS "-Wl,--verbose")
set(OpenCV_DIR /usr/local/share/OpenCV)

find_package(
        OpenCV REQUIRED
        )

include_directories(/home/whymatter/github.com/AlexeyAB-darknet/src)

link_directories(/home/whymatter/github.com/AlexeyAB-darknet)

add_executable(nn-tester
        main.cpp
        )

target_link_libraries(nn-tester darknet ${OpenCV_LIBS})
