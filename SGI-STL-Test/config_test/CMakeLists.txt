cmake_minimum_required(VERSION 3.0)
project(config_test VERSION 1.0.0)

set(SOURCE config_test.cpp)
set(CMAKE_CXX_FLAGS_DEBUG "$ENV(CXXFLAGS) -O0 -Wall -g")
add_executable(${PROJECTNAME} ${SOURCE})