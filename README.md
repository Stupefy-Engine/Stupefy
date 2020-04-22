[![Stupefy Engine logo](/logo.png)](https://stupefy-engine.github.io/Stupefy-Website/)

## Stupefy Engine

Homepage: https://stupefy-engine.github.io/Stupefy-Website/

#### 2D and 3D cross-platform game engine

Stupefy Engine is a feature-packed, cross-platform game engine to create 2D and
3D games from a unified interface. It provides a comprehensive set of common
tools, so that users can focus on making games without having to reinvent the
wheel. Games can be exported in one click to a number of platforms, including
the major desktop platforms (Linux, Mac OSX, Windows) as well as mobile
(Android, iOS) and web-based (HTML5) platforms.

### Documentation and demos

The official documentation is hosted on [ReadTheDocs](https://stupefy-docs.readthedocs.io/en/latest/#).
It is maintained by the Stupefy community in its own [GitHub repository](https://github.com/Stupefy-Engine/Stupefy-docs).

### Getting Started

Visual Studio 2017 or 2019 is recommended, Stupefy is currently for Windows only!

You can clone the repository to a local destination using git:

`git clone --recursive https://github.com/Stupefy-Engine/Stupefy.git`

Make sure that you do a `--recursive` clone to fetch all of the submodules!

### Building Engine

- Building On Windows

    - Stupefy Engine can be built from its source by running the Win-Gen.bat from scripts.
    - The default building is for Visual Studio 2019.
    
    - IF YOU WANT TO WORK USING VS CODE IDE ON WINDOWS THEN FOLLOW THESE STEPS
    
    - To build on Linux platform you will need:-
    - VS Code (C++ Extension Installed)
    - MinGW (Latest)
    - Cmake (Latest)

    - After cloning the the Stupefy Engine from git repository:-
    - Enter the root directory
    - Open terminal and type `mkdir build && cd build`
    - Next type `cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..`
    - Then type `cmake --build .`
    - Then go to build/Sandbox and run Sandbox


- Building On Linux
    - To build on Linux platform you will need:-
    - VS Code (C++ Extension Installed)
    - MinGW (Latest)
    - Cmake (Latest)

    - After cloning the the Stupefy Engine from git repository:-
    - Enter the root directory
    - Open terminal and type `mkdir build && cd build`
    - Next type `cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..`
    - Then type `cmake --build .`
    - Then go to build/Sandbox and run Sandbox


- Building On MAC OS
    - To build on Linux platform you will need:-
    - VS Code (C++ Extension Installed)
    - MinGW (Latest)
    - Cmake (Latest)

    - After cloning the the Stupefy Engine from git repository:-
    - Enter the root directory
    - Open terminal and type `mkdir build && cd build`

### Upcoming Features

- Cmake build system
- Support for Mac OS and Linux
- Native rendering API support (Vulkan)


[![Travis Build Status](https://travis-ci.org/Stupefy-Engine/Stupefy.svg?branch=master)](https://travis-ci.org/Stupefy-Engine/Stupefy)


