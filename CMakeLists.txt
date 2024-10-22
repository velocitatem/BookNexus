cmake_minimum_required(VERSION 3.29)
project(LibrarySystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(LibrarySystem main.cpp
        library.cpp
        library.h
        Items.cpp
        Items.h)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests testing/tests.cpp
        library.cpp
        library.h
        Items.cpp
        Items.h)

target_link_libraries(runTests GTest::GTest GTest::Main pthread)
target_include_directories(runTests PRIVATE ${PROJECT_SOURCE_DIR})

enable_testing()
add_test(NAME runTests COMMAND runTests)