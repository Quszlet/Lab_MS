# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sletch/Projects_C++/MC/Lab2_MC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sletch/Projects_C++/MC/Lab2_MC/build

# Include any dependencies generated for this target.
include CMakeFiles/Lab2_MC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Lab2_MC.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab2_MC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab2_MC.dir/flags.make

CMakeFiles/Lab2_MC.dir/src/main.cpp.o: CMakeFiles/Lab2_MC.dir/flags.make
CMakeFiles/Lab2_MC.dir/src/main.cpp.o: /home/sletch/Projects_C++/MC/Lab2_MC/src/main.cpp
CMakeFiles/Lab2_MC.dir/src/main.cpp.o: CMakeFiles/Lab2_MC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sletch/Projects_C++/MC/Lab2_MC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab2_MC.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Lab2_MC.dir/src/main.cpp.o -MF CMakeFiles/Lab2_MC.dir/src/main.cpp.o.d -o CMakeFiles/Lab2_MC.dir/src/main.cpp.o -c /home/sletch/Projects_C++/MC/Lab2_MC/src/main.cpp

CMakeFiles/Lab2_MC.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Lab2_MC.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sletch/Projects_C++/MC/Lab2_MC/src/main.cpp > CMakeFiles/Lab2_MC.dir/src/main.cpp.i

CMakeFiles/Lab2_MC.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Lab2_MC.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sletch/Projects_C++/MC/Lab2_MC/src/main.cpp -o CMakeFiles/Lab2_MC.dir/src/main.cpp.s

# Object files for target Lab2_MC
Lab2_MC_OBJECTS = \
"CMakeFiles/Lab2_MC.dir/src/main.cpp.o"

# External object files for target Lab2_MC
Lab2_MC_EXTERNAL_OBJECTS =

Lab2_MC: CMakeFiles/Lab2_MC.dir/src/main.cpp.o
Lab2_MC: CMakeFiles/Lab2_MC.dir/build.make
Lab2_MC: librunge_kutta.a
Lab2_MC: CMakeFiles/Lab2_MC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/sletch/Projects_C++/MC/Lab2_MC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab2_MC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab2_MC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab2_MC.dir/build: Lab2_MC
.PHONY : CMakeFiles/Lab2_MC.dir/build

CMakeFiles/Lab2_MC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab2_MC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab2_MC.dir/clean

CMakeFiles/Lab2_MC.dir/depend:
	cd /home/sletch/Projects_C++/MC/Lab2_MC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sletch/Projects_C++/MC/Lab2_MC /home/sletch/Projects_C++/MC/Lab2_MC /home/sletch/Projects_C++/MC/Lab2_MC/build /home/sletch/Projects_C++/MC/Lab2_MC/build /home/sletch/Projects_C++/MC/Lab2_MC/build/CMakeFiles/Lab2_MC.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Lab2_MC.dir/depend

