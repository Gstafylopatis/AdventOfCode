cmake_minimum_required(VERSION 3.29)
project(ModularCppProject)

set(CMAKE_CXX_STANDARD 20)

# Include custom cmake module
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(AddProject)

# Add subprojects
add_subdirectory(day_1)
#add_subdirectory(project2)
#add_subdirectory(project3)
#add_executable(AdventOfCode Day_1/main.cpp)
