#!/bin/bash

echo "Enter the name for your project:"
read PROJECTNAME

# Define the directory name (default: new_directory)
DIRPARENT=${1:-$PROJECTNAME}
# DIRINCLUDE=${2:-include}
DIRSRC=${2:-src}
DIRBUILD=${3:-build}

# Create the directory
mkdir -p "$DIRPARENT/$DIRSRC"

# Create build directory
touch "$DIRPARENT/$DIRBUILD"

# Create files
CMAKELISTS=${4:-CMakeLists.txt}

touch "$DIRPARENT/$CMAKELISTS"
echo "cmake_minimum_required(VERSION 3.10)
# Set the compiling mode flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -s")
# Set the project name
project($PROJECTNAME)

# Add the executable
add_executable(\${CMAKE_PROJECT_NAME}
	src/main.c)

#link external libraries
target_link_libraries(\${CMAKE_PROJECT_NAME} m)" >> "$DIRPARENT/$CMAKELISTS"

# MAIN FILE
CMAIN=${5:-main.c}
cat <<EOF > "$DIRPARENT/$DIRSRC/$CMAIN"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <semaphore.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <signal.h>

int main() {
    return 0;
}
EOF

# CLANG
CLANG=${6:-.clang-format}
touch "$DIRPARENT/$CLANG"
echo '# Google C/C++ Code Style settings

Language: Cpp
BasedOnStyle: Google
ColumnLimit: 80' >> "$DIRPARENT/$CLANG"

# Confirm
echo "New C project has been created."
