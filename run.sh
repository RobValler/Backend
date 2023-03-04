#!/bin/sh
set -e
cd build
rm -rf *
conan install .. 
cmake ..
make -j16
