cmake_minimum_required(VERSION 3.10)
# Set the compiling mode flags

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -s")

# Set the project name
project(Lab1)

include_directories(include)

# Add the executable
add_executable(exercise1
src/PrintArray.c
src/main.c)