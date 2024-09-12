project(${CLIENT_NAME})

set(CLIENT_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CLIENT_BUILD_DIR ${CMAKE_BINARY_DIR}/_client)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Locate Qt packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui Network)
find_package(Boost QUIET)

# Check if the Conan-provided
if(TARGET Boost::boost)
    add_library(boost_common ALIAS Boost::boost)
elseif(TARGET boost::boost)
    add_library(boost_common ALIAS boost::boost)
else()
    message(FATAL_ERROR "Boost not found")
endif()

# All sources
set(ALL_CLIENT_SOURCES
    ${CLIENT_SOURCES_DIR}/main.cpp
)

# Adding main code and tests
if (BUILD_CLIENT)
    add_subdirectory(src)
endif()
