# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/pi/ros_joystic_teleoperation/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/ros_joystic_teleoperation/catkin_ws/build

# Utility rule file for clean_test_results_joy.

# Include the progress variables for this target.
include joy/CMakeFiles/clean_test_results_joy.dir/progress.make

joy/CMakeFiles/clean_test_results_joy:
	cd /home/pi/ros_joystic_teleoperation/catkin_ws/build/joy && /usr/bin/python2 /home/pi/ros_catkin_ws/src/catkin/cmake/test/remove_test_results.py /home/pi/ros_joystic_teleoperation/catkin_ws/build/test_results/joy

clean_test_results_joy: joy/CMakeFiles/clean_test_results_joy
clean_test_results_joy: joy/CMakeFiles/clean_test_results_joy.dir/build.make

.PHONY : clean_test_results_joy

# Rule to build all files generated by this target.
joy/CMakeFiles/clean_test_results_joy.dir/build: clean_test_results_joy

.PHONY : joy/CMakeFiles/clean_test_results_joy.dir/build

joy/CMakeFiles/clean_test_results_joy.dir/clean:
	cd /home/pi/ros_joystic_teleoperation/catkin_ws/build/joy && $(CMAKE_COMMAND) -P CMakeFiles/clean_test_results_joy.dir/cmake_clean.cmake
.PHONY : joy/CMakeFiles/clean_test_results_joy.dir/clean

joy/CMakeFiles/clean_test_results_joy.dir/depend:
	cd /home/pi/ros_joystic_teleoperation/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/ros_joystic_teleoperation/catkin_ws/src /home/pi/ros_joystic_teleoperation/catkin_ws/src/joy /home/pi/ros_joystic_teleoperation/catkin_ws/build /home/pi/ros_joystic_teleoperation/catkin_ws/build/joy /home/pi/ros_joystic_teleoperation/catkin_ws/build/joy/CMakeFiles/clean_test_results_joy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : joy/CMakeFiles/clean_test_results_joy.dir/depend

