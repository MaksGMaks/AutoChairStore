# set(COMMON_DIR ${CMAKE_SOURCE_DIR}/_common)

# set(COMMON_SOURCES
#     ${COMMON_DIR}/src/StructureSerializer.cpp
# )

# add_library(common STATIC "${COMMON_SOURCES}")

# target_include_directories(common PUBLIC "${COMMON_DIR}/src")

project(CommonLibrary)

set(COMMON_DIR ${CMAKE_CURRENT_SOURCE_DIR})
find_package(nlohmann_json REQUIRED)

set(COMMON_SOURCES
    ${COMMON_DIR}/src/StructureSerializer.cpp
)

add_library(common STATIC ${COMMON_SOURCES})

target_link_libraries(common
    nlohmann_json::nlohmann_json
)


target_include_directories(common PUBLIC ${COMMON_DIR}/src)
