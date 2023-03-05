#!/bin/sh
set -e
cd build
rm -rf *
conan install .. 
cmake .. -DCMAKE_BUILD_TYPE=Release -DROS_ENABLE=ON
make -j16
