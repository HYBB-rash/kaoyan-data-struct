cmake_minimum_required(VERSION 3.16.3)
project(data_struct)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

#add_executable(data_struct)

add_executable(
    SeqList 
    LinearList/LinerList.h
    LinearList/SeqList.cpp
)

add_executable(
    SingleLinkedList
    LinearList/LinerList.h
    LinearList/SingleLinkedList.cpp
)

add_executable(
    DoubleLinkedList
    LinearList/LinerList.h
    LinearList/DoubleLinkedList.cpp
)