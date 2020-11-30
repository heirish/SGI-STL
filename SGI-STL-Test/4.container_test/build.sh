#!/bin/bash
rm -rf build > /dev/null 2>&1
mkdir build
cd build
cmake -G "Unix Makefiles" ../
make -j 4
