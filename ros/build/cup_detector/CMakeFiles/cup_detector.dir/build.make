# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/whymatter/github.com/albatross/ros/src/cup_detector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/whymatter/github.com/albatross/ros/build/cup_detector

# Include any dependencies generated for this target.
include CMakeFiles/cup_detector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cup_detector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cup_detector.dir/flags.make

CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.o: CMakeFiles/cup_detector.dir/flags.make
CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.o: /home/whymatter/github.com/albatross/ros/src/cup_detector/src/cup_detector_node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/whymatter/github.com/albatross/ros/build/cup_detector/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.o -c /home/whymatter/github.com/albatross/ros/src/cup_detector/src/cup_detector_node.cpp

CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/whymatter/github.com/albatross/ros/src/cup_detector/src/cup_detector_node.cpp > CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.i

CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/whymatter/github.com/albatross/ros/src/cup_detector/src/cup_detector_node.cpp -o CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.s

CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.o.requires:

.PHONY : CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.o.requires

CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.o.provides: CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.o.requires
	$(MAKE) -f CMakeFiles/cup_detector.dir/build.make CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.o.provides.build
.PHONY : CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.o.provides

CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.o.provides.build: CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.o


CMakeFiles/cup_detector.dir/src/main.cpp.o: CMakeFiles/cup_detector.dir/flags.make
CMakeFiles/cup_detector.dir/src/main.cpp.o: /home/whymatter/github.com/albatross/ros/src/cup_detector/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/whymatter/github.com/albatross/ros/build/cup_detector/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cup_detector.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cup_detector.dir/src/main.cpp.o -c /home/whymatter/github.com/albatross/ros/src/cup_detector/src/main.cpp

CMakeFiles/cup_detector.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cup_detector.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/whymatter/github.com/albatross/ros/src/cup_detector/src/main.cpp > CMakeFiles/cup_detector.dir/src/main.cpp.i

CMakeFiles/cup_detector.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cup_detector.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/whymatter/github.com/albatross/ros/src/cup_detector/src/main.cpp -o CMakeFiles/cup_detector.dir/src/main.cpp.s

CMakeFiles/cup_detector.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/cup_detector.dir/src/main.cpp.o.requires

CMakeFiles/cup_detector.dir/src/main.cpp.o.provides: CMakeFiles/cup_detector.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/cup_detector.dir/build.make CMakeFiles/cup_detector.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/cup_detector.dir/src/main.cpp.o.provides

CMakeFiles/cup_detector.dir/src/main.cpp.o.provides.build: CMakeFiles/cup_detector.dir/src/main.cpp.o


CMakeFiles/cup_detector.dir/src/darknet_main.cpp.o: CMakeFiles/cup_detector.dir/flags.make
CMakeFiles/cup_detector.dir/src/darknet_main.cpp.o: /home/whymatter/github.com/albatross/ros/src/cup_detector/src/darknet_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/whymatter/github.com/albatross/ros/build/cup_detector/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cup_detector.dir/src/darknet_main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cup_detector.dir/src/darknet_main.cpp.o -c /home/whymatter/github.com/albatross/ros/src/cup_detector/src/darknet_main.cpp

CMakeFiles/cup_detector.dir/src/darknet_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cup_detector.dir/src/darknet_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/whymatter/github.com/albatross/ros/src/cup_detector/src/darknet_main.cpp > CMakeFiles/cup_detector.dir/src/darknet_main.cpp.i

CMakeFiles/cup_detector.dir/src/darknet_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cup_detector.dir/src/darknet_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/whymatter/github.com/albatross/ros/src/cup_detector/src/darknet_main.cpp -o CMakeFiles/cup_detector.dir/src/darknet_main.cpp.s

CMakeFiles/cup_detector.dir/src/darknet_main.cpp.o.requires:

.PHONY : CMakeFiles/cup_detector.dir/src/darknet_main.cpp.o.requires

CMakeFiles/cup_detector.dir/src/darknet_main.cpp.o.provides: CMakeFiles/cup_detector.dir/src/darknet_main.cpp.o.requires
	$(MAKE) -f CMakeFiles/cup_detector.dir/build.make CMakeFiles/cup_detector.dir/src/darknet_main.cpp.o.provides.build
.PHONY : CMakeFiles/cup_detector.dir/src/darknet_main.cpp.o.provides

CMakeFiles/cup_detector.dir/src/darknet_main.cpp.o.provides.build: CMakeFiles/cup_detector.dir/src/darknet_main.cpp.o


CMakeFiles/cup_detector.dir/src/detector.cpp.o: CMakeFiles/cup_detector.dir/flags.make
CMakeFiles/cup_detector.dir/src/detector.cpp.o: /home/whymatter/github.com/albatross/ros/src/cup_detector/src/detector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/whymatter/github.com/albatross/ros/build/cup_detector/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cup_detector.dir/src/detector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cup_detector.dir/src/detector.cpp.o -c /home/whymatter/github.com/albatross/ros/src/cup_detector/src/detector.cpp

CMakeFiles/cup_detector.dir/src/detector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cup_detector.dir/src/detector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/whymatter/github.com/albatross/ros/src/cup_detector/src/detector.cpp > CMakeFiles/cup_detector.dir/src/detector.cpp.i

CMakeFiles/cup_detector.dir/src/detector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cup_detector.dir/src/detector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/whymatter/github.com/albatross/ros/src/cup_detector/src/detector.cpp -o CMakeFiles/cup_detector.dir/src/detector.cpp.s

CMakeFiles/cup_detector.dir/src/detector.cpp.o.requires:

.PHONY : CMakeFiles/cup_detector.dir/src/detector.cpp.o.requires

CMakeFiles/cup_detector.dir/src/detector.cpp.o.provides: CMakeFiles/cup_detector.dir/src/detector.cpp.o.requires
	$(MAKE) -f CMakeFiles/cup_detector.dir/build.make CMakeFiles/cup_detector.dir/src/detector.cpp.o.provides.build
.PHONY : CMakeFiles/cup_detector.dir/src/detector.cpp.o.provides

CMakeFiles/cup_detector.dir/src/detector.cpp.o.provides.build: CMakeFiles/cup_detector.dir/src/detector.cpp.o


# Object files for target cup_detector
cup_detector_OBJECTS = \
"CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.o" \
"CMakeFiles/cup_detector.dir/src/main.cpp.o" \
"CMakeFiles/cup_detector.dir/src/darknet_main.cpp.o" \
"CMakeFiles/cup_detector.dir/src/detector.cpp.o"

# External object files for target cup_detector
cup_detector_EXTERNAL_OBJECTS =

/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.o
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: CMakeFiles/cup_detector.dir/src/main.cpp.o
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: CMakeFiles/cup_detector.dir/src/darknet_main.cpp.o
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: CMakeFiles/cup_detector.dir/src/detector.cpp.o
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: CMakeFiles/cup_detector.dir/build.make
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /home/whymatter/github.com/albatross/ros/devel/.private/alb_ros_base/lib/libalb_ros_base.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /home/whymatter/github.com/albatross/ros/devel/.private/alb_base/lib/libalb_base.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /opt/ros/melodic/lib/libroscpp.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_cudabgsegm.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_cudaobjdetect.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_cudastereo.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_dnn.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_ml.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_shape.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_stitching.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_superres.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_videostab.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_viz.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /opt/ros/melodic/lib/libcv_bridge.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /opt/ros/melodic/lib/librosconsole.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /opt/ros/melodic/lib/librostime.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /opt/ros/melodic/lib/libcpp_common.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_cudafeatures2d.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_cudacodec.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_cudaoptflow.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_cudalegacy.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_calib3d.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_cudawarping.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_features2d.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_flann.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_highgui.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_objdetect.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_photo.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_cudaimgproc.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_cudafilters.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_cudaarithm.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_video.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_videoio.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_imgcodecs.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_imgproc.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_core.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: /usr/local/lib/libopencv_cudev.so.3.4.0
/home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector: CMakeFiles/cup_detector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/whymatter/github.com/albatross/ros/build/cup_detector/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable /home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cup_detector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cup_detector.dir/build: /home/whymatter/github.com/albatross/ros/devel/.private/cup_detector/lib/cup_detector/cup_detector

.PHONY : CMakeFiles/cup_detector.dir/build

CMakeFiles/cup_detector.dir/requires: CMakeFiles/cup_detector.dir/src/cup_detector_node.cpp.o.requires
CMakeFiles/cup_detector.dir/requires: CMakeFiles/cup_detector.dir/src/main.cpp.o.requires
CMakeFiles/cup_detector.dir/requires: CMakeFiles/cup_detector.dir/src/darknet_main.cpp.o.requires
CMakeFiles/cup_detector.dir/requires: CMakeFiles/cup_detector.dir/src/detector.cpp.o.requires

.PHONY : CMakeFiles/cup_detector.dir/requires

CMakeFiles/cup_detector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cup_detector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cup_detector.dir/clean

CMakeFiles/cup_detector.dir/depend:
	cd /home/whymatter/github.com/albatross/ros/build/cup_detector && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/whymatter/github.com/albatross/ros/src/cup_detector /home/whymatter/github.com/albatross/ros/src/cup_detector /home/whymatter/github.com/albatross/ros/build/cup_detector /home/whymatter/github.com/albatross/ros/build/cup_detector /home/whymatter/github.com/albatross/ros/build/cup_detector/CMakeFiles/cup_detector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cup_detector.dir/depend
