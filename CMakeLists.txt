cmake_minimum_required(VERSION 3.5...3.20)
project(ASSIGNMENT1)

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

# Find required packages if any
find_package(PkgConfig REQUIRED)

# Collect source files
file(GLOB_RECURSE ASSIGNMENT1_src
    "src/*.cpp"
    "src/*/*.cpp"
    "src/*.h"
)

# Create the executable
add_executable(ASSIGNMENT1 ${ASSIGNMENT1_src})

# Set compiler flags for Debug mode
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -Wall -Wextra")

# Link any libraries if needed
target_link_libraries(ASSIGNMENT1)

# Set output directory for executables
set(CMAKE_BINARY_DIR "../bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})


