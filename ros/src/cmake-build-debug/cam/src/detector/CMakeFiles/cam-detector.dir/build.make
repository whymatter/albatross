# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2018.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/whymatter/github.com/albatross/ros/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/whymatter/github.com/albatross/ros/src/cmake-build-debug

# Include any dependencies generated for this target.
include cam/src/detector/CMakeFiles/cam-detector.dir/depend.make

# Include the progress variables for this target.
include cam/src/detector/CMakeFiles/cam-detector.dir/progress.make

# Include the compile flags for this target's objects.
include cam/src/detector/CMakeFiles/cam-detector.dir/flags.make

cam/src/detector/CMakeFiles/cam-detector.dir/main.cpp.o: cam/src/detector/CMakeFiles/cam-detector.dir/flags.make
cam/src/detector/CMakeFiles/cam-detector.dir/main.cpp.o: ../cam/src/detector/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/whymatter/github.com/albatross/ros/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object cam/src/detector/CMakeFiles/cam-detector.dir/main.cpp.o"
	cd /home/whymatter/github.com/albatross/ros/src/cmake-build-debug/cam/src/detector && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cam-detector.dir/main.cpp.o -c /home/whymatter/github.com/albatross/ros/src/cam/src/detector/main.cpp

cam/src/detector/CMakeFiles/cam-detector.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cam-detector.dir/main.cpp.i"
	cd /home/whymatter/github.com/albatross/ros/src/cmake-build-debug/cam/src/detector && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/whymatter/github.com/albatross/ros/src/cam/src/detector/main.cpp > CMakeFiles/cam-detector.dir/main.cpp.i

cam/src/detector/CMakeFiles/cam-detector.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cam-detector.dir/main.cpp.s"
	cd /home/whymatter/github.com/albatross/ros/src/cmake-build-debug/cam/src/detector && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/whymatter/github.com/albatross/ros/src/cam/src/detector/main.cpp -o CMakeFiles/cam-detector.dir/main.cpp.s

cam/src/detector/CMakeFiles/cam-detector.dir/detector_node.cpp.o: cam/src/detector/CMakeFiles/cam-detector.dir/flags.make
cam/src/detector/CMakeFiles/cam-detector.dir/detector_node.cpp.o: ../cam/src/detector/detector_node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/whymatter/github.com/albatross/ros/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object cam/src/detector/CMakeFiles/cam-detector.dir/detector_node.cpp.o"
	cd /home/whymatter/github.com/albatross/ros/src/cmake-build-debug/cam/src/detector && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cam-detector.dir/detector_node.cpp.o -c /home/whymatter/github.com/albatross/ros/src/cam/src/detector/detector_node.cpp

cam/src/detector/CMakeFiles/cam-detector.dir/detector_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cam-detector.dir/detector_node.cpp.i"
	cd /home/whymatter/github.com/albatross/ros/src/cmake-build-debug/cam/src/detector && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/whymatter/github.com/albatross/ros/src/cam/src/detector/detector_node.cpp > CMakeFiles/cam-detector.dir/detector_node.cpp.i

cam/src/detector/CMakeFiles/cam-detector.dir/detector_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cam-detector.dir/detector_node.cpp.s"
	cd /home/whymatter/github.com/albatross/ros/src/cmake-build-debug/cam/src/detector && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/whymatter/github.com/albatross/ros/src/cam/src/detector/detector_node.cpp -o CMakeFiles/cam-detector.dir/detector_node.cpp.s

# Object files for target cam-detector
cam__detector_OBJECTS = \
"CMakeFiles/cam-detector.dir/main.cpp.o" \
"CMakeFiles/cam-detector.dir/detector_node.cpp.o"

# External object files for target cam-detector
cam__detector_EXTERNAL_OBJECTS =

devel/lib/cam/cam-detector: cam/src/detector/CMakeFiles/cam-detector.dir/main.cpp.o
devel/lib/cam/cam-detector: cam/src/detector/CMakeFiles/cam-detector.dir/detector_node.cpp.o
devel/lib/cam/cam-detector: cam/src/detector/CMakeFiles/cam-detector.dir/build.make
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_cudabgsegm.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_cudaobjdetect.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_cudastereo.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_dnn.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_ml.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_shape.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_stitching.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_superres.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_videostab.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_viz.so.3.4.0
devel/lib/cam/cam-detector: /opt/ros/melodic/lib/libroscpp.so
devel/lib/cam/cam-detector: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
devel/lib/cam/cam-detector: /usr/lib/x86_64-linux-gnu/libboost_signals.so
devel/lib/cam/cam-detector: /opt/ros/melodic/lib/librosconsole.so
devel/lib/cam/cam-detector: /opt/ros/melodic/lib/librosconsole_log4cxx.so
devel/lib/cam/cam-detector: /opt/ros/melodic/lib/librosconsole_backend_interface.so
devel/lib/cam/cam-detector: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
devel/lib/cam/cam-detector: /usr/lib/x86_64-linux-gnu/libboost_regex.so
devel/lib/cam/cam-detector: /opt/ros/melodic/lib/libroscpp_serialization.so
devel/lib/cam/cam-detector: /opt/ros/melodic/lib/libxmlrpcpp.so
devel/lib/cam/cam-detector: /opt/ros/melodic/lib/librostime.so
devel/lib/cam/cam-detector: /opt/ros/melodic/lib/libcpp_common.so
devel/lib/cam/cam-detector: /usr/lib/x86_64-linux-gnu/libboost_system.so
devel/lib/cam/cam-detector: /usr/lib/x86_64-linux-gnu/libboost_thread.so
devel/lib/cam/cam-detector: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
devel/lib/cam/cam-detector: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
devel/lib/cam/cam-detector: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
devel/lib/cam/cam-detector: /usr/lib/x86_64-linux-gnu/libpthread.so
devel/lib/cam/cam-detector: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_cudafeatures2d.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_cudacodec.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_cudaoptflow.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_cudalegacy.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_calib3d.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_cudawarping.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_features2d.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_flann.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_highgui.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_objdetect.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_photo.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_cudaimgproc.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_cudafilters.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_cudaarithm.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_video.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_videoio.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_imgcodecs.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_imgproc.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_core.so.3.4.0
devel/lib/cam/cam-detector: /usr/local/lib/libopencv_cudev.so.3.4.0
devel/lib/cam/cam-detector: cam/src/detector/CMakeFiles/cam-detector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/whymatter/github.com/albatross/ros/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../devel/lib/cam/cam-detector"
	cd /home/whymatter/github.com/albatross/ros/src/cmake-build-debug/cam/src/detector && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cam-detector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cam/src/detector/CMakeFiles/cam-detector.dir/build: devel/lib/cam/cam-detector

.PHONY : cam/src/detector/CMakeFiles/cam-detector.dir/build

cam/src/detector/CMakeFiles/cam-detector.dir/clean:
	cd /home/whymatter/github.com/albatross/ros/src/cmake-build-debug/cam/src/detector && $(CMAKE_COMMAND) -P CMakeFiles/cam-detector.dir/cmake_clean.cmake
.PHONY : cam/src/detector/CMakeFiles/cam-detector.dir/clean

cam/src/detector/CMakeFiles/cam-detector.dir/depend:
	cd /home/whymatter/github.com/albatross/ros/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/whymatter/github.com/albatross/ros/src /home/whymatter/github.com/albatross/ros/src/cam/src/detector /home/whymatter/github.com/albatross/ros/src/cmake-build-debug /home/whymatter/github.com/albatross/ros/src/cmake-build-debug/cam/src/detector /home/whymatter/github.com/albatross/ros/src/cmake-build-debug/cam/src/detector/CMakeFiles/cam-detector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cam/src/detector/CMakeFiles/cam-detector.dir/depend
