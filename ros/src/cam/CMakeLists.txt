cmake_minimum_required(VERSION 2.8.3)
project(cam)

set_property(GLOBAL PROPERTY CXX_STANDARD 14)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        )
catkin_package(
        #  INCLUDE_DIRS include
        #  LIBRARIES cam
        #  CATKIN_DEPENDS roscpp
        #  DEPENDS system_lib
)

###########
## Build ##
###########

#add_subdirectory(src/cam_direct_capture)
#add_subdirectory(src/sandbox)
#add_subdirectory(src/capture_image)
#add_subdirectory(src/calc_extrinsic)
#add_subdirectory(src/label_video)
#add_subdirectory(src/detector)
