cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(app.exe main.cpp)

add_executable(test.exe test.cpp)
target_link_libraries(test.exe GTest::GTest GTest::Main)
add_test(NAME SortTests COMMAND test.exe)
