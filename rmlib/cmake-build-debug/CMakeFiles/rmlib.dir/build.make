# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /opt/clion-2017.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gerald/CLionProjects/rmlib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gerald/CLionProjects/rmlib/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rmlib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rmlib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rmlib.dir/flags.make

CMakeFiles/rmlib.dir/rmRef_h.cpp.o: CMakeFiles/rmlib.dir/flags.make
CMakeFiles/rmlib.dir/rmRef_h.cpp.o: ../rmRef_h.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gerald/CLionProjects/rmlib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rmlib.dir/rmRef_h.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rmlib.dir/rmRef_h.cpp.o -c /home/gerald/CLionProjects/rmlib/rmRef_h.cpp

CMakeFiles/rmlib.dir/rmRef_h.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rmlib.dir/rmRef_h.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gerald/CLionProjects/rmlib/rmRef_h.cpp > CMakeFiles/rmlib.dir/rmRef_h.cpp.i

CMakeFiles/rmlib.dir/rmRef_h.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rmlib.dir/rmRef_h.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gerald/CLionProjects/rmlib/rmRef_h.cpp -o CMakeFiles/rmlib.dir/rmRef_h.cpp.s

CMakeFiles/rmlib.dir/rmRef_h.cpp.o.requires:

.PHONY : CMakeFiles/rmlib.dir/rmRef_h.cpp.o.requires

CMakeFiles/rmlib.dir/rmRef_h.cpp.o.provides: CMakeFiles/rmlib.dir/rmRef_h.cpp.o.requires
	$(MAKE) -f CMakeFiles/rmlib.dir/build.make CMakeFiles/rmlib.dir/rmRef_h.cpp.o.provides.build
.PHONY : CMakeFiles/rmlib.dir/rmRef_h.cpp.o.provides

CMakeFiles/rmlib.dir/rmRef_h.cpp.o.provides.build: CMakeFiles/rmlib.dir/rmRef_h.cpp.o


# Object files for target rmlib
rmlib_OBJECTS = \
"CMakeFiles/rmlib.dir/rmRef_h.cpp.o"

# External object files for target rmlib
rmlib_EXTERNAL_OBJECTS =

librmlib.a: CMakeFiles/rmlib.dir/rmRef_h.cpp.o
librmlib.a: CMakeFiles/rmlib.dir/build.make
librmlib.a: CMakeFiles/rmlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gerald/CLionProjects/rmlib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library librmlib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/rmlib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rmlib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rmlib.dir/build: librmlib.a

.PHONY : CMakeFiles/rmlib.dir/build

CMakeFiles/rmlib.dir/requires: CMakeFiles/rmlib.dir/rmRef_h.cpp.o.requires

.PHONY : CMakeFiles/rmlib.dir/requires

CMakeFiles/rmlib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rmlib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rmlib.dir/clean

CMakeFiles/rmlib.dir/depend:
	cd /home/gerald/CLionProjects/rmlib/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gerald/CLionProjects/rmlib /home/gerald/CLionProjects/rmlib /home/gerald/CLionProjects/rmlib/cmake-build-debug /home/gerald/CLionProjects/rmlib/cmake-build-debug /home/gerald/CLionProjects/rmlib/cmake-build-debug/CMakeFiles/rmlib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rmlib.dir/depend

