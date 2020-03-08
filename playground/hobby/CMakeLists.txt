cmake_minimum_required(VERSION 3.10)
project(Hobby)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(hobby main.cpp)
target_link_libraries (hobby Eigen3::Eigen)