# @file CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

project(statistics)

set(SOURCES
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

set(${PROJECT_NAME}_INCLUDES
    ${PROJECT_SOURCE_DIR}/src/statistics
)

target_include_directories(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_INCLUDES})

add_subdirectory(src/statistics)
target_link_libraries(${PROJECT_NAME} statistics_lib)

add_subdirectory(tests)
