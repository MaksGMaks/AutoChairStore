project(${SERVER_NAME})

# Locate conan packages

find_package(SQLite3 REQUIRED)
find_package(Boost QUIET)

# Check if the Conan-provided
if(TARGET Boost::boost)
    add_library(boost_common ALIAS Boost::boost)
elseif(TARGET boost::boost)
    add_library(boost_common ALIAS boost::boost)
else()
    message(FATAL_ERROR "Boost not found")
endif()

set(SERVER_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SERVER_BUILD_DIR ${CMAKE_BINARY_DIR}/_server)

set(DATABASE ${SERVER_SOURCES_DIR}/Database/DatabaseManager.cpp)

# All server sources
set(ALL_SERVER_SOURCES
    ${SERVER_SOURCES_DIR}/main.cpp
    ${DATABASE}
)



if (BUILD_SERVER)
    add_subdirectory(src)
endif()
