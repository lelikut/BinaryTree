cmake_minimum_required(VERSION 3.21)
project(BinaryTree)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

add_executable(BinaryTree main.cpp Node.h Tree.h Iterator.h Tests.cpp)

target_link_libraries(BinaryTree gtest)