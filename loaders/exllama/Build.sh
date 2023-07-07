#!/bin/bash

CUDAVERSON="11.8"
# rm -rf build
mkdir -p build
cd build


cmake -DCUDA_BIN_PATH=/usr/local/cuda-$CUDAVERSON/bin/ -DCUDA_TOOLKIT_ROOT_DIR=/usr/local/cuda-$CUDAVERSON/ -DCMAKE_PREFIX_PATH=../../libtorch/src/ ..
cmake --build . --config Release && mv libexllama.so ../../lib/ && cp ../src/go_exllama.h ../../lib/

#cleanup
# cd .. && rm -rf build