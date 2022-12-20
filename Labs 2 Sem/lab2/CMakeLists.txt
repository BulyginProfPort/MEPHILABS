cmake_minimum_required(VERSION 3.23)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})
include_directories(DynamicArray)
include_directories(LinkedList)
include_directories(Matrix)
include_directories(Sequence)
include_directories(Sequence/ArraySequence)
include_directories(Sequence/LinkedListSequence)

add_executable(
        lab1
        DynamicArray/DynamicArray.cpp
        DynamicArray/DynamicArray.h
        LinkedList/LinkedList.cpp
        LinkedList/LinkedList.h
        Matrix/matrix.cpp
        Matrix/matrix.h
        Sequence/ArraySequence/ArraySequence.cpp
        Sequence/ArraySequence/ArraySequence.h
        Sequence/LinkedListSequence/LinkedListSequence.cpp
        Sequence/LinkedListSequence/LinkedListSequence.h
        Sequence/Sequence.cpp
        Sequence/Sequence.h
        ISorter/ISorter.cpp
        ISorter/ISorter.h
        Tests/test.cpp
        Tests/test.h
        Menu/Menu.h
        Menu/Menu.cpp
        App/MainFrame.cpp
        App/MainFrame.h
        App/MyApp.cpp
        App/MyApp.h
        App/Presenter.cpp
        App/Presenter.h
        main.cpp)

target_link_libraries(lab1 ${wxWidgets_LIBRARIES})

