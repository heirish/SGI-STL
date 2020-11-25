cmake_minimum_required(VERSION 3.0)

project(allocator VERSION 1.0.0)
set(SOURCE HeirishAlloc.cpp)
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -std=c++11 -Wall -g")
add_executable(allocator-test ${SOURCE})