cmake_minimum_required(VERSION 3.10)
project(AutoChairStore)

# CMake standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options to build different components
option(BUILD_CLIENT "Build the client application." ON)
option(BUILD_SERVER "Build the server application." ON)

add_subdirectory(libs/common)

if(BUILD_CLIENT)
    add_subdirectory(apps/client)
endif()

if(BUILD_SERVER)
    add_subdirectory(apps/server)
endif()

