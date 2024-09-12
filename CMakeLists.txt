cmake_minimum_required(VERSION 3.10)
project("AutoChairStore")

set(CLIENT_NAME "${PROJECT_NAME}Client")
set(SERVER_NAME "${PROJECT_NAME}Server")

# CMake standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options to build different components
option(BUILD_CLIENT "Build the client application." OFF)
option(BUILD_SERVER "Build the server application." OFF)

# Common includes and sources
set(COMMON_DIR "${CMAKE_CURRENT_SOURCE_DIR}/_common")

# if(BUILD_CLIENT OR BUILD_SERVER)
#     add_subdirectory(_common)
# endif()

if(BUILD_CLIENT)
    add_subdirectory(_client)
endif()

if(BUILD_SERVER)
    add_subdirectory(_server)
endif()

