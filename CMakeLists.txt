cmake_minimum_required(VERSION 3.10)

project(statistics)

set(SOURCES
    src/main.cpp
    src/statistics/min.cpp
    src/statistics/max.cpp
    src/statistics/mean.cpp
    src/statistics/std.cpp
    src/statistics/pst.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)