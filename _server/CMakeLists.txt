project(${SERVER_NAME})

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

set(SERVER_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SERVER_BUILD_DIR ${CMAKE_BINARY_DIR}/_server)

set(DATABASE 
    ${SERVER_SOURCES_DIR}/Database/DatabaseManager.cpp
    ${SERVER_SOURCES_DIR}/Database/DatabaseQueries.cpp
    ${SERVER_SOURCES_DIR}/Database/InventoryTable.cpp
    ${SERVER_SOURCES_DIR}/Database/PhotosTable.cpp
    ${SERVER_SOURCES_DIR}/Database/ProductInfoTable.cpp
    ${SERVER_SOURCES_DIR}/Database/ProductsTable.cpp
    ${SERVER_SOURCES_DIR}/Database/PurchaseOrdersTable.cpp
    ${SERVER_SOURCES_DIR}/Database/SuppliersTable.cpp
    ${SERVER_SOURCES_DIR}/Database/UserTable.cpp
    ${SERVER_SOURCES_DIR}/Database/ITableFactory.cpp
    )

set(NETWORK 
    ${SERVER_SOURCES_DIR}/Network/NetworkManager.cpp)


# All server sources
set(ALL_SERVER_SOURCES
    ${SERVER_SOURCES_DIR}/main.cpp
    ${DATABASE}
    ${NETWORK}
)



if (BUILD_SERVER)
    add_subdirectory(src)
endif()
