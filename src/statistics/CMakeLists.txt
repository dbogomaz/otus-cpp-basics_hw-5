# @file statistics/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

project(statistics_lib)

set(STATISTICS_LIB_SOURCES
    max.cpp
    mean.cpp
    min.cpp
    pst.cpp
    std.cpp
)

add_library(${PROJECT_NAME} ${STATISTICS_LIB_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
