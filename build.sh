#! /bin/bash
rm -fr build
mkdir build
cd build
cmake ..
build-wrapper-linux-x86-64 --out-dir build_wrapper_output_directory make clean all