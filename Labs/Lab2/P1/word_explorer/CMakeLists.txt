cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -s")

# Set the project name
project(word_explorer)

include_directories(include)

# Add the executable
add_executable(${CMAKE_PROJECT_NAME} 
    src/ContainsWord.c
    src/ExploreDirectory.c
	src/main.c)
	
#link external libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    m)
