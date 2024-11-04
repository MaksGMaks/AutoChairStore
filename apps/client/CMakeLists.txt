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
    ${CLIENT_SOURCES_DIR}/Ui/Models/PhotosModel.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Models/ProductsModel.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Models/PurchaseOrdersModel.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Models/UsersModel.cpp
)    

set(NETWORK_SOURCES
    ${CLIENT_SOURCES_DIR}/Network/ApiManager.cpp
    ${CLIENT_SOURCES_DIR}/Network/NetworkManager.cpp
)

set(VIEW_SOURCES 
    ${CLIENT_SOURCES_DIR}/Ui/Views/AccountView.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/CatalogueView.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/LoginRegistrationView.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/IView.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/PurchaseOrderInfoV.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/ProductPageView.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/BasketView.cpp
)    

set(VIEWMODEL_SOURCES 
    ${CLIENT_SOURCES_DIR}/Ui/ViewModels/AccountViewModel.cpp
    ${CLIENT_SOURCES_DIR}/Ui/ViewModels/CatalogueViewModel.cpp
    ${CLIENT_SOURCES_DIR}/Ui/ViewModels/ProductPageViewModel.cpp
    ${CLIENT_SOURCES_DIR}/Ui/ViewModels/IViewModel.cpp
    ${CLIENT_SOURCES_DIR}/Ui/ViewModels/LoginRegistrationViewModel.cpp
    ${CLIENT_SOURCES_DIR}/Ui/ViewModels/PurchaseOrderInfoVM.cpp
)    

set(SUBVIEW_SOURCES
    ${CLIENT_SOURCES_DIR}/Ui/Views/SubViews/CatalogueMenuSV.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/SubViews/CatalogueProductSV.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/SubViews/CatalogueSearchBaseSeatV.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/SubViews/CatalogueSearchChildSeatV.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/SubViews/CatalogueSearchSportSeatV.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/SubViews/CatalogueSearchLuxurySeatV.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/SubViews/BaseSeatPage.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/SubViews/ChildSeatPage.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/SubViews/SportSeatPage.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Views/SubViews/LuxurySeatPage.cpp
)    

set(UI_SOUCES
    ${CLIENT_SOURCES_DIR}/Ui/MainWindow.cpp
    ${CLIENT_SOURCES_DIR}/Ui/Menu.cpp
    ${CLIENT_SOURCES_DIR}/Ui/MessageBox.cpp
    ${CLIENT_SOURCES_DIR}/Ui/TimerButton.cpp
    ${FACTORY_SOURCES}
    ${MODEL_SOURCES}
    ${VIEW_SOURCES}
    ${VIEWMODEL_SOURCES}
    ${SUBVIEW_SOURCES}
)    

qt6_add_resources(RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resources/resources.qrc)

# All sources
set(ALL_CLIENT_SOURCES
    ${CLIENT_SOURCES_DIR}/main.cpp
    ${NETWORK_SOURCES}
    ${UI_SOUCES}
    ${RESOURCES}
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
