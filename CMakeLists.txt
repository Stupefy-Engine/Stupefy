# Main Builder CMakeLists.txt

cmake_minimum_required(VERSION 3.8.0)

message(STATUS "Started CMake")
message(AUTHOR_WARNING "CMake Required Version is 3.8.0")
project(Stupefy VERSION 1.0.0)
enable_language(CXX)

file(MAKE_DIRECTORY Logs)

if (WIN32)
    add_definitions(-D "SF_PLATFORM_WINDOWS")
    if(MSVC)
        add_definitions(/D "STUPEFY_API=__declspec(dllexport)")
        set (CMAKE_PREFIX_PATH "D:\\Softwares\\QT5\\5.9.9\\msvc2017_64")
    else()
        add_definitions(-D "STUPEFY_API=")
        set (CMAKE_PREFIX_PATH "D:\\Softwares\\QT5\\5.9.9\\mingw53_32")
    endif()
else()
    add_definitions(-D "STUPEFY_API=")
endif()

# C++ standard requirement
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_subdirectory(Stupefy)
add_subdirectory(Sandbox)