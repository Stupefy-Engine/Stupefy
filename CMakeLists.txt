# Main CMakeLists.txt

cmake_minimum_required(VERSION 3.8.0)
project(Stupefy VERSION 1.0.0)
enable_language(CXX)

# C++ standard requirement
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Running CMake")

add_subdirectory(Stupefy)
add_subdirectory(Sandbox)
