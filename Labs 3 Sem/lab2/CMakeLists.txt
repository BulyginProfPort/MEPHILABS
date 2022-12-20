cmake_minimum_required(VERSION 3.23)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)
add_executable(
        test_lab2
        Tests/tests.h
        Tests/tests.cpp
        HashTable/HashTable.h
        HashTable/HashTable.cpp)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries (test_lab2  ${Boost_LIBRARIES})
add_test(lab2 test_lab2)

###############
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable(
        lab2
        HashTable/HashTable.h
        HashTable/HashTable.cpp
        #App/App.cpp
        #App/App.h
        #App/MainFrame.cpp
        #App/MainFrame.h
        #App/Presenter.cpp
        #App/Presenter.h
        main.cpp
)
target_link_libraries(lab2 ${wxWidgets_LIBRARIES})

enable_testing()