cmake_minimum_required(VERSION 3.10)

# Set the compiling mode flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -o0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-o3 -DNDEBUG -s")

# Set the project name
project(Exercise2)

# Include the current directory for header files
include_directories(include)

# Add the executable
add_executable(exercise_2
    src/main
    src/fill_date.c)