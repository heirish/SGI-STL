cmake_minimum_required(VERSION 3.0)
project(iterator VERSION 1.0.0)

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -std=c++11 -Wall -g")
add_executable(find3 find3.cpp)
add_executable(tag_test tag_test.cpp)