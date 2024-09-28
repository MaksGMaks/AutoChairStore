cmake_minimum_required(VERSION 3.10)
project(AutoChairStoreServer)

set(SERVER_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SERVER_BUILD_DIR ${CMAKE_BINARY_DIR}/apps/server)

# Locate conan packages
find_package(SQLite3 REQUIRED)
find_package(Boost QUIET)
find_package(nlohmann_json REQUIRED)

# Check if the Conan-provided
if(TARGET Boost::boost)
    add_library(boost_common ALIAS Boost::boost)
elseif(TARGET boost::boost)
    add_library(boost_common ALIAS boost::boost)
else()
    message(FATAL_ERROR "Boost not found")
endif()

set(DATABASE 
    ${SERVER_SOURCES_DIR}/Database/DatabaseManager.cpp
    ${SERVER_SOURCES_DIR}/Database/DatabaseQueries.cpp
    ${SERVER_SOURCES_DIR}/Database/InventoryTable.cpp
<<<<<<< HEAD:apps/server/CMakeLists.txt
    ${SERVER_SOURCES_DIR}/Database/ITableFactory.cpp
=======
>>>>>>> 180c82f (Server is ready):_server/CMakeLists.txt
    ${SERVER_SOURCES_DIR}/Database/PhotosTable.cpp
    ${SERVER_SOURCES_DIR}/Database/ProductInfoTable.cpp
    ${SERVER_SOURCES_DIR}/Database/ProductsTable.cpp
    ${SERVER_SOURCES_DIR}/Database/PurchaseOrdersTable.cpp
    ${SERVER_SOURCES_DIR}/Database/SuppliersTable.cpp
    ${SERVER_SOURCES_DIR}/Database/UserTable.cpp
    ${SERVER_SOURCES_DIR}/Database/ITableFactory.cpp
    )

# All server sources
set(ALL_SERVER_SOURCES
    ${SERVER_SOURCES_DIR}/main.cpp
    ${DATABASE}
    ${SERVER_SOURCES_DIR}/Network/NetworkManager.cpp
)

# Create server executable
add_executable(${PROJECT_NAME} ${ALL_SERVER_SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${SERVER_SOURCES_DIR})

# Link libs
target_link_libraries(${PROJECT_NAME} 
    boost_common 
    CommonLibrary
    nlohmann_json::nlohmann_json
    SQLite::SQLite3
    )

# Set the destination directory for the executable
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SERVER_BUILD_DIR})

# Compiler flags for GCC/MinGW
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)
endif()
