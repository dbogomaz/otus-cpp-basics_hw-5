# @file tests/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

project(bug_fix_tests)

set(BUG_FIX_TESTS_SOURCES
    bug_fix_tests.cpp
)

add_executable(${PROJECT_NAME} ${BUG_FIX_TESTS_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

set(${PROJECT_NAME}_INCLUDES
    ../src/statistics
)
target_include_directories(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_INCLUDES})

# add_subdirectory(../src/statistics ../src/statistics)
target_link_libraries(${PROJECT_NAME} statistics_lib)

# add_subdirectory(../googletest ../googletest)
add_subdirectory(${CMAKE_SOURCE_DIR}/googletest ${CMAKE_CURRENT_BINARY_DIR}/googletest)
target_link_libraries(${PROJECT_NAME} GTest::gtest_main)

enable_testing()
add_test(NAME bug_fix_tests COMMAND bug_fix_test)
