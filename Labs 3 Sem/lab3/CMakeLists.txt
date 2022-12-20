cmake_minimum_required(VERSION 3.23)
project(lab3)

set(CMAKE_CXX_STANDARD 14)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)
add_executable(
        test_lab3
        Tests.h
        Tests.cpp
        Graph.h
        Graph.cpp
)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries (test_lab3  ${Boost_LIBRARIES})
add_test(lab3 test_lab3)

add_executable(lab3 main.cpp)

enable_testing()

