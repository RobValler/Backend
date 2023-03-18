#!/bin/bash
set -e
. /opt/ros/humble/setup.bash
. install/setup.bash

cd build
rm -rf *
conan install .. 
cmake .. -DCMAKE_BUILD_TYPE=Debug -DROS_ENABLE=ON
make -j16
