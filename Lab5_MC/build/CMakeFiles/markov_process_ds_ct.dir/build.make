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
CMAKE_SOURCE_DIR = /home/sletch/Projects_C++/MC/Lab5_MC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sletch/Projects_C++/MC/Lab5_MC/build

# Include any dependencies generated for this target.
include CMakeFiles/markov_process_ds_ct.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/markov_process_ds_ct.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/markov_process_ds_ct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/markov_process_ds_ct.dir/flags.make

CMakeFiles/markov_process_ds_ct.dir/src/markov_process_ds_ct/markov_process_ds_ct.cpp.o: CMakeFiles/markov_process_ds_ct.dir/flags.make
CMakeFiles/markov_process_ds_ct.dir/src/markov_process_ds_ct/markov_process_ds_ct.cpp.o: /home/sletch/Projects_C++/MC/Lab5_MC/src/markov_process_ds_ct/markov_process_ds_ct.cpp
CMakeFiles/markov_process_ds_ct.dir/src/markov_process_ds_ct/markov_process_ds_ct.cpp.o: CMakeFiles/markov_process_ds_ct.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sletch/Projects_C++/MC/Lab5_MC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/markov_process_ds_ct.dir/src/markov_process_ds_ct/markov_process_ds_ct.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/markov_process_ds_ct.dir/src/markov_process_ds_ct/markov_process_ds_ct.cpp.o -MF CMakeFiles/markov_process_ds_ct.dir/src/markov_process_ds_ct/markov_process_ds_ct.cpp.o.d -o CMakeFiles/markov_process_ds_ct.dir/src/markov_process_ds_ct/markov_process_ds_ct.cpp.o -c /home/sletch/Projects_C++/MC/Lab5_MC/src/markov_process_ds_ct/markov_process_ds_ct.cpp

CMakeFiles/markov_process_ds_ct.dir/src/markov_process_ds_ct/markov_process_ds_ct.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/markov_process_ds_ct.dir/src/markov_process_ds_ct/markov_process_ds_ct.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sletch/Projects_C++/MC/Lab5_MC/src/markov_process_ds_ct/markov_process_ds_ct.cpp > CMakeFiles/markov_process_ds_ct.dir/src/markov_process_ds_ct/markov_process_ds_ct.cpp.i

CMakeFiles/markov_process_ds_ct.dir/src/markov_process_ds_ct/markov_process_ds_ct.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/markov_process_ds_ct.dir/src/markov_process_ds_ct/markov_process_ds_ct.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sletch/Projects_C++/MC/Lab5_MC/src/markov_process_ds_ct/markov_process_ds_ct.cpp -o CMakeFiles/markov_process_ds_ct.dir/src/markov_process_ds_ct/markov_process_ds_ct.cpp.s

# Object files for target markov_process_ds_ct
markov_process_ds_ct_OBJECTS = \
"CMakeFiles/markov_process_ds_ct.dir/src/markov_process_ds_ct/markov_process_ds_ct.cpp.o"

# External object files for target markov_process_ds_ct
markov_process_ds_ct_EXTERNAL_OBJECTS =

libmarkov_process_ds_ct.a: CMakeFiles/markov_process_ds_ct.dir/src/markov_process_ds_ct/markov_process_ds_ct.cpp.o
libmarkov_process_ds_ct.a: CMakeFiles/markov_process_ds_ct.dir/build.make
libmarkov_process_ds_ct.a: CMakeFiles/markov_process_ds_ct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/sletch/Projects_C++/MC/Lab5_MC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmarkov_process_ds_ct.a"
	$(CMAKE_COMMAND) -P CMakeFiles/markov_process_ds_ct.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/markov_process_ds_ct.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/markov_process_ds_ct.dir/build: libmarkov_process_ds_ct.a
.PHONY : CMakeFiles/markov_process_ds_ct.dir/build

CMakeFiles/markov_process_ds_ct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/markov_process_ds_ct.dir/cmake_clean.cmake
.PHONY : CMakeFiles/markov_process_ds_ct.dir/clean

CMakeFiles/markov_process_ds_ct.dir/depend:
	cd /home/sletch/Projects_C++/MC/Lab5_MC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sletch/Projects_C++/MC/Lab5_MC /home/sletch/Projects_C++/MC/Lab5_MC /home/sletch/Projects_C++/MC/Lab5_MC/build /home/sletch/Projects_C++/MC/Lab5_MC/build /home/sletch/Projects_C++/MC/Lab5_MC/build/CMakeFiles/markov_process_ds_ct.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/markov_process_ds_ct.dir/depend

