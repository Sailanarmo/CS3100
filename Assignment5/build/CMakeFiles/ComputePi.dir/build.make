# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/sailanarmo/Documents/CS3100/Assignment5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sailanarmo/Documents/CS3100/Assignment5/build

# Include any dependencies generated for this target.
include CMakeFiles/ComputePi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ComputePi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ComputePi.dir/flags.make

CMakeFiles/ComputePi.dir/main.cpp.o: CMakeFiles/ComputePi.dir/flags.make
CMakeFiles/ComputePi.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sailanarmo/Documents/CS3100/Assignment5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ComputePi.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComputePi.dir/main.cpp.o -c /home/sailanarmo/Documents/CS3100/Assignment5/main.cpp

CMakeFiles/ComputePi.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComputePi.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sailanarmo/Documents/CS3100/Assignment5/main.cpp > CMakeFiles/ComputePi.dir/main.cpp.i

CMakeFiles/ComputePi.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComputePi.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sailanarmo/Documents/CS3100/Assignment5/main.cpp -o CMakeFiles/ComputePi.dir/main.cpp.s

CMakeFiles/ComputePi.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ComputePi.dir/main.cpp.o.requires

CMakeFiles/ComputePi.dir/main.cpp.o.provides: CMakeFiles/ComputePi.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ComputePi.dir/build.make CMakeFiles/ComputePi.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ComputePi.dir/main.cpp.o.provides

CMakeFiles/ComputePi.dir/main.cpp.o.provides.build: CMakeFiles/ComputePi.dir/main.cpp.o


CMakeFiles/ComputePi.dir/compPi.cpp.o: CMakeFiles/ComputePi.dir/flags.make
CMakeFiles/ComputePi.dir/compPi.cpp.o: ../compPi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sailanarmo/Documents/CS3100/Assignment5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ComputePi.dir/compPi.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComputePi.dir/compPi.cpp.o -c /home/sailanarmo/Documents/CS3100/Assignment5/compPi.cpp

CMakeFiles/ComputePi.dir/compPi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComputePi.dir/compPi.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sailanarmo/Documents/CS3100/Assignment5/compPi.cpp > CMakeFiles/ComputePi.dir/compPi.cpp.i

CMakeFiles/ComputePi.dir/compPi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComputePi.dir/compPi.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sailanarmo/Documents/CS3100/Assignment5/compPi.cpp -o CMakeFiles/ComputePi.dir/compPi.cpp.s

CMakeFiles/ComputePi.dir/compPi.cpp.o.requires:

.PHONY : CMakeFiles/ComputePi.dir/compPi.cpp.o.requires

CMakeFiles/ComputePi.dir/compPi.cpp.o.provides: CMakeFiles/ComputePi.dir/compPi.cpp.o.requires
	$(MAKE) -f CMakeFiles/ComputePi.dir/build.make CMakeFiles/ComputePi.dir/compPi.cpp.o.provides.build
.PHONY : CMakeFiles/ComputePi.dir/compPi.cpp.o.provides

CMakeFiles/ComputePi.dir/compPi.cpp.o.provides.build: CMakeFiles/ComputePi.dir/compPi.cpp.o


# Object files for target ComputePi
ComputePi_OBJECTS = \
"CMakeFiles/ComputePi.dir/main.cpp.o" \
"CMakeFiles/ComputePi.dir/compPi.cpp.o"

# External object files for target ComputePi
ComputePi_EXTERNAL_OBJECTS =

ComputePi: CMakeFiles/ComputePi.dir/main.cpp.o
ComputePi: CMakeFiles/ComputePi.dir/compPi.cpp.o
ComputePi: CMakeFiles/ComputePi.dir/build.make
ComputePi: CMakeFiles/ComputePi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sailanarmo/Documents/CS3100/Assignment5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ComputePi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ComputePi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ComputePi.dir/build: ComputePi

.PHONY : CMakeFiles/ComputePi.dir/build

CMakeFiles/ComputePi.dir/requires: CMakeFiles/ComputePi.dir/main.cpp.o.requires
CMakeFiles/ComputePi.dir/requires: CMakeFiles/ComputePi.dir/compPi.cpp.o.requires

.PHONY : CMakeFiles/ComputePi.dir/requires

CMakeFiles/ComputePi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ComputePi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ComputePi.dir/clean

CMakeFiles/ComputePi.dir/depend:
	cd /home/sailanarmo/Documents/CS3100/Assignment5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sailanarmo/Documents/CS3100/Assignment5 /home/sailanarmo/Documents/CS3100/Assignment5 /home/sailanarmo/Documents/CS3100/Assignment5/build /home/sailanarmo/Documents/CS3100/Assignment5/build /home/sailanarmo/Documents/CS3100/Assignment5/build/CMakeFiles/ComputePi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ComputePi.dir/depend

