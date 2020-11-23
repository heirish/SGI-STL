rm -rf build 2>&1 >null
mkdir build
cd build
cmake clean
cmake -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" ..
make  -j 4
