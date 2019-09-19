cmake_minimum_required(VERSION 3.4)

project(ClassFactory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB example example/*.h example/*.cpp)

add_executable(classfactory_test ${example} ClassFactory.h)
