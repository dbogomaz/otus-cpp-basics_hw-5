# @file CMakeLists.txt
# 1. Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# 2. Имя проекта. Потом можно будет использовать ${PROJECT_NAME}
project(statistics)

# 3. Добавление исполняемого файла (файлов). Если файлов много, то лучше
#    перечислить их в переменной и потом использовать эту переменную ${SOURCES}
#    вместо перечисления всех файлов.
#    Если включаются шаблонные классы в виде .h/.ipp и они подключены в main.cpp, то
#    их указывать не нужно (см. домашнее задание 7).
set(SOURCES
    src/main.cpp
    # если далее будет библиотека, то эти файлы нужно будет удалить
    #src/statistics/min.cpp
    #src/statistics/max.cpp
    #src/statistics/mean.cpp
    #src/statistics/std.cpp
    #src/statistics/pst.cpp
)

# 4. Добавление исполняемого файла (файлов)
add_executable(${PROJECT_NAME} ${SOURCES})

# 5. Установка свойств для цели (target)
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# 6. Добавление путей к заголовочным файлам потом эту переменную можно будет
#    использовать в target_include_directories
set(${PROJECT_NAME}_INCLUDES
    ${PROJECT_SOURCE_DIR}/src/statistics # PROJECT_SOURCE_DIR - папка с CMakeLists.txt
)

# 7. Добавление путей к заголовочным файлам
#    После этого в исходных файлах можно будет писать #include "min.h" не указывая путь
#    до файла.
#    Три уровня видимости:
#    PUBLIC - для текущего проекта и для тех, кто будет линковаться с этим проектом
#    INTERFACE - для тех, кто будет линковаться с этим проектом
#    PRIVATE - для текущего проекта
target_include_directories(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_INCLUDES})

# ********************** Настройка основного проекта в виде библиотеки *************
# 8. Добавление библиотеки (файлов). Если файлов много, то лучше
#    перечислить их в переменной и потом использовать эту переменную ${SOURCES_LIB}
# 

# 9. Добавление библиотеки (файлов). STATIC - статическая, SHARED - динамическая
#    Если включаются шаблонные классы в виде .h/.ipp ,то нужно указать INTERFACE
#    потому что в библиотеку они не компилируются.
# add_library(${PROJECT_NAME}_lib STATIC ${SOURCES_LIB})

# 10. Установка свойств для цели (target)
# set_target_properties(${PROJECT_NAME}_lib PROPERTIES
#     CXX_STANDARD 17
#     CXX_STANDARD_REQUIRED ON
#     CXX_EXTENSIONS OFF
# )

# 11. Добавление путей к заголовочным файлам
# target_include_directories(${PROJECT_NAME}_lib PUBLIC ${${PROJECT_NAME}_INCLUDES})

# 12. Линковка библиотеки с исполняемым файлом
# target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)

add_subdirectory(src/statistics)
target_link_libraries(${PROJECT_NAME} statistics_lib)

# теперь можено удалить из set(SOURCES ...) файлы, которые есть в библиотеке

# ********************** Подключение GoogleTest *************
# 13. Добавление GoogleTest
#     Предварительно нужно скачать googletest из репозитория
#     лучше git submodule add
add_subdirectory(googletest)

# 14. Добавление файлов, которые будут тестироваться
#     Если файлов много, то лучше перечислить их в переменной и потом использовать
set(TEST_SOURCE 
    tests/bug_fix_tests.cpp
    #src/statistics/min.cpp
    #src/statistics/max.cpp
    #src/statistics/mean.cpp
    #src/statistics/std.cpp
    #src/statistics/pst.cpp
)

# 15. Добавление исполняемого файла (файлов) для тестов
add_executable(bug_fix_test ${TEST_SOURCE})

# 16. Установка свойств для цели (target)
set_target_properties(bug_fix_test PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# 17. Добавление путей к заголовочным файлам
#     После этого в исходных файлах можно будет писать #include "min.h" не указывая путь
#     до файла.
target_include_directories(bug_fix_test PRIVATE ${${PROJECT_NAME}_INCLUDES})

# 18. Линковка тестов с библиотекой проекта и gtest и gtest_main
#     если линкуем в библиотекой проекта, то можно удалить из TEST_SOURCE файлы
#     которые есть в библиотеке
#     И можно удалить target_include_directories
#     GTest::gtest_main уже включает в себя GTest::gtest
#     Если используется GTest::gtest, Можно убрать строки с googletest/googletest/include
#     и googlemock/include из target_include_directories для тестов — они добавятся автоматически.
target_link_libraries(bug_fix_test PRIVATE
    # ${PROJECT_NAME}_lib
    statistics_lib
    #GTest::gtest
    GTest::gtest_main
)

# 19. Добавление тестов в CMake
#     После этого можно будет запускать тесты из папки сборки командой ctest
#     или cmake --build . --target test
enable_testing()
add_test(NAME bug_fix_test COMMAND bug_fix_test)