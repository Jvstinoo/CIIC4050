# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/build

# Include any dependencies generated for this target.
include CMakeFiles/exercise1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/exercise1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/exercise1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exercise1.dir/flags.make

CMakeFiles/exercise1.dir/src/PrintArray.c.o: CMakeFiles/exercise1.dir/flags.make
CMakeFiles/exercise1.dir/src/PrintArray.c.o: /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/src/PrintArray.c
CMakeFiles/exercise1.dir/src/PrintArray.c.o: CMakeFiles/exercise1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/exercise1.dir/src/PrintArray.c.o"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/exercise1.dir/src/PrintArray.c.o -MF CMakeFiles/exercise1.dir/src/PrintArray.c.o.d -o CMakeFiles/exercise1.dir/src/PrintArray.c.o -c /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/src/PrintArray.c

CMakeFiles/exercise1.dir/src/PrintArray.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/exercise1.dir/src/PrintArray.c.i"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/src/PrintArray.c > CMakeFiles/exercise1.dir/src/PrintArray.c.i

CMakeFiles/exercise1.dir/src/PrintArray.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/exercise1.dir/src/PrintArray.c.s"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/src/PrintArray.c -o CMakeFiles/exercise1.dir/src/PrintArray.c.s

CMakeFiles/exercise1.dir/src/main.c.o: CMakeFiles/exercise1.dir/flags.make
CMakeFiles/exercise1.dir/src/main.c.o: /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/src/main.c
CMakeFiles/exercise1.dir/src/main.c.o: CMakeFiles/exercise1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/exercise1.dir/src/main.c.o"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/exercise1.dir/src/main.c.o -MF CMakeFiles/exercise1.dir/src/main.c.o.d -o CMakeFiles/exercise1.dir/src/main.c.o -c /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/src/main.c

CMakeFiles/exercise1.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/exercise1.dir/src/main.c.i"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/src/main.c > CMakeFiles/exercise1.dir/src/main.c.i

CMakeFiles/exercise1.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/exercise1.dir/src/main.c.s"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/src/main.c -o CMakeFiles/exercise1.dir/src/main.c.s

# Object files for target exercise1
exercise1_OBJECTS = \
"CMakeFiles/exercise1.dir/src/PrintArray.c.o" \
"CMakeFiles/exercise1.dir/src/main.c.o"

# External object files for target exercise1
exercise1_EXTERNAL_OBJECTS =

exercise1: CMakeFiles/exercise1.dir/src/PrintArray.c.o
exercise1: CMakeFiles/exercise1.dir/src/main.c.o
exercise1: CMakeFiles/exercise1.dir/build.make
exercise1: CMakeFiles/exercise1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable exercise1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exercise1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exercise1.dir/build: exercise1
.PHONY : CMakeFiles/exercise1.dir/build

CMakeFiles/exercise1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exercise1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exercise1.dir/clean

CMakeFiles/exercise1.dir/depend:
	cd /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/build /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/build /home/jvstinoo/jvstinoo_code/CIIC4050/Lab1AtLab/build/CMakeFiles/exercise1.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/exercise1.dir/depend

