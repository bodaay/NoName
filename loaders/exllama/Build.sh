#!/bin/bash

CUDAVERSON="11.8"
CMAKE_PREFIX_PATH=${PWD}/../../libtorch/src/
echo $CMAKE_PREFIX_PATH
rm -rf build/*
cd build


cmake -DCUDA_BIN_PATH=/usr/local/cuda-$CUDAVERSON/bin/ -DCUDA_TOOLKIT_ROOT_DIR=/usr/local/cuda-$CUDAVERSON/ -DCMAKE_PREFIX_PATH=/home/khalefa/projects/NoName/libtorch/src/ ..
cmake --build . --config Release && mv libexllama.so ../../lib/



