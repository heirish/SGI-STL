#!/bin/bash

rm -rf build >/dev/null 2>&1
mkdir build
cd build
#cmake -DCMAKE_C_COMPILER:FILEPATH=D:\\cygwin64\\bin\\gcc.exe -DCMAKE_CXX_COMPILER:FILEPATH=D:\\cygwin64\\bin\\g++.exe -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" ..
cmake -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" ..
make -j 4
