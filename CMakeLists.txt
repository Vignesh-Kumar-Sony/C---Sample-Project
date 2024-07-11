# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(DemoStub)

# C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find GTest
find_package(GTest REQUIRED)

# Include Directories
include_directories(${GTEST_INCLUDE_DIRS} include)

# Add Coverage Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

# Source Files
set(SOURCE_FILES 
    src/time_utils.c  # Add your source file here
)

# Test Files
file(GLOB_RECURSE TEST_FILES "test/*.cpp")

# Create the Utils library from the source files
add_library(Utils ${SOURCE_FILES})

# Add Executable
add_executable(TimeStub ${TEST_FILES})

# Link the executable against GoogleTest, pthread, and Utils library
target_link_libraries(TimeStub Utils ${GTEST_LIBRARIES} pthread)

# Enable Testing
enable_testing()

# Add Test
add_test(NAME TimeStubTest COMMAND TimeStub)
