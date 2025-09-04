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

# Подключение GoogleTest
add_subdirectory(googletest)

set(TEST_SOURCE 
    tests/bug_fix_tests.cpp
    src/statistics/min.cpp
    src/statistics/max.cpp
    src/statistics/mean.cpp
    src/statistics/std.cpp
    src/statistics/pst.cpp
)

add_executable(bug_fix_test ${TEST_SOURCE})

set_target_properties(bug_fix_test PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# Подключение заголовочных файлов googletest и googlemock
target_include_directories(bug_fix_test PRIVATE 
    ${PROJECT_SOURCE_DIR}/googletest/googletest/include
    ${PROJECT_SOURCE_DIR}/googletest/googlemock/include
)

# Линковка тестов с gtest и gtest_main
target_link_libraries(bug_fix_test PRIVATE 
    gtest
    gtest_main
)

# Добавление тестов в CMake
enable_testing()
add_test(NAME bug_fix_test COMMAND bug_fix_test)