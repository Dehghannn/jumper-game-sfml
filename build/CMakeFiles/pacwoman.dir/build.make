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
CMAKE_SOURCE_DIR = /home/dehghannn/Documents/Code/Cplusplus/Pac-Woman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dehghannn/Documents/Code/Cplusplus/Pac-Woman/build

# Include any dependencies generated for this target.
include CMakeFiles/pacwoman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pacwoman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pacwoman.dir/flags.make

CMakeFiles/pacwoman.dir/src/main.cpp.o: CMakeFiles/pacwoman.dir/flags.make
CMakeFiles/pacwoman.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dehghannn/Documents/Code/Cplusplus/Pac-Woman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pacwoman.dir/src/main.cpp.o"
	/usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pacwoman.dir/src/main.cpp.o -c /home/dehghannn/Documents/Code/Cplusplus/Pac-Woman/src/main.cpp

CMakeFiles/pacwoman.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pacwoman.dir/src/main.cpp.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dehghannn/Documents/Code/Cplusplus/Pac-Woman/src/main.cpp > CMakeFiles/pacwoman.dir/src/main.cpp.i

CMakeFiles/pacwoman.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pacwoman.dir/src/main.cpp.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dehghannn/Documents/Code/Cplusplus/Pac-Woman/src/main.cpp -o CMakeFiles/pacwoman.dir/src/main.cpp.s

CMakeFiles/pacwoman.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/pacwoman.dir/src/main.cpp.o.requires

CMakeFiles/pacwoman.dir/src/main.cpp.o.provides: CMakeFiles/pacwoman.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/pacwoman.dir/build.make CMakeFiles/pacwoman.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/pacwoman.dir/src/main.cpp.o.provides

CMakeFiles/pacwoman.dir/src/main.cpp.o.provides.build: CMakeFiles/pacwoman.dir/src/main.cpp.o


# Object files for target pacwoman
pacwoman_OBJECTS = \
"CMakeFiles/pacwoman.dir/src/main.cpp.o"

# External object files for target pacwoman
pacwoman_EXTERNAL_OBJECTS =

pacwoman: CMakeFiles/pacwoman.dir/src/main.cpp.o
pacwoman: CMakeFiles/pacwoman.dir/build.make
pacwoman: CMakeFiles/pacwoman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dehghannn/Documents/Code/Cplusplus/Pac-Woman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pacwoman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pacwoman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pacwoman.dir/build: pacwoman

.PHONY : CMakeFiles/pacwoman.dir/build

CMakeFiles/pacwoman.dir/requires: CMakeFiles/pacwoman.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/pacwoman.dir/requires

CMakeFiles/pacwoman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pacwoman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pacwoman.dir/clean

CMakeFiles/pacwoman.dir/depend:
	cd /home/dehghannn/Documents/Code/Cplusplus/Pac-Woman/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dehghannn/Documents/Code/Cplusplus/Pac-Woman /home/dehghannn/Documents/Code/Cplusplus/Pac-Woman /home/dehghannn/Documents/Code/Cplusplus/Pac-Woman/build /home/dehghannn/Documents/Code/Cplusplus/Pac-Woman/build /home/dehghannn/Documents/Code/Cplusplus/Pac-Woman/build/CMakeFiles/pacwoman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pacwoman.dir/depend

