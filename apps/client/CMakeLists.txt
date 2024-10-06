cmake_minimum_required(VERSION 3.10)
project(AutoChairStoreClient)

set(CLIENT_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CLIENT_BUILD_DIR ${CMAKE_BINARY_DIR}/apps/client)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Locate Qt packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui Network)
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

set(FACTORY_SOURCES 
    ${CLIENT_SOURCES_DIR}/Ui/Factory/ModelFactory.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Factory/ViewFactory.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Factory/ViewModelFactory.cpp
)

set(MODEL_SOURCES 
    ${CLIENT_SOURCES_DIR}/Ui/Models/IModel.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Models/UsersModel.cpp
)

set(VIEWMODEL_SOURCES 
    ${CLIENT_SOURCES_DIR}/Ui/ViewModels/AccountViewModel.cpp
    ${CLIENT_SOURCES_DIR}/Ui/ViewModels/IViewModel.cpp
)

set(VIEW_SOURCES 
    ${CLIENT_SOURCES_DIR}/Ui/Views/AccountView.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/IView.cpp
)

set(UI_SOUCES
    ${CLIENT_SOURCES_DIR}/Ui/MainWindow.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Menu.cpp
    ${FACTORY_SOURCES}
    ${MODEL_SOURCES}
    ${VIEW_SOURCES}
    ${VIEWMODEL_SOURCES}
)

set(NETWORK_SOURCES
    ${CLIENT_SOURCES_DIR}/Network/ApiManager.cpp
    ${CLIENT_SOURCES_DIR}/Network/NetworkManager.cpp
)

# All sources
set(ALL_CLIENT_SOURCES
    ${CLIENT_SOURCES_DIR}/main.cpp
    ${NETWORK_SOURCES}
    ${UI_SOUCES}
    
)

# Create client executable
add_executable(${PROJECT_NAME} ${ALL_CLIENT_SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${CLIENT_SOURCES_DIR})

# Link libraries 
target_link_libraries(${PROJECT_NAME} 
    boost_common
    CommonLibrary
    nlohmann_json::nlohmann_json
    Qt6::Core 
    Qt6::Gui 
    Qt6::Network 
    Qt6::Widgets 
)

# Set the destination directory for the executable
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CLIENT_BUILD_DIR})

# Compiler flags for GCC/MinGW
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)
endif()
