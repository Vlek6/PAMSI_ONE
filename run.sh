#!/bin/bash
rm -rf build
mkdir build/
cd build
cmake ../
make
./unit_tests
./main
rm -rf build
