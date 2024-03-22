#!/bin/bash

# remove old build directory
rm -rf build
# create new build directory
mkdir -p build
cd build
cmake ..
make

echo "=== gumdrop done! ==="