project(CommonLibrary)

find_package(nlohmann_json REQUIRED)

set(COMMON_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(COMMON_HEADERS
    ${COMMON_DIR}/include/Repositories.hpp
    ${COMMON_DIR}/include/StructureSerializer.hpp
)

set(COMMON_SOURCES
    ${COMMON_DIR}/src/StructureSerializer.cpp
)

add_library(${PROJECT_NAME}
    ${COMMON_HEADERS}
    ${COMMON_SOURCES}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${COMMON_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    nlohmann_json::nlohmann_json
)
