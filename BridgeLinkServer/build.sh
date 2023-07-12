#!/bin/bash
# PATH="/usr/local/cuda-11.8/bin:$PATH"
# LD_LIBRARY_PATH="/usr/local/cuda-11.8/lib64:$LD_LIBRARY_PATH"
CUDAVERSON="11.8"
# rm -rf build
mkdir -p build
cd build
GRPC_FOLDER=${PWD}/../../libgrpc/INSTALL
# echo 
cmake -DCMAKE_PREFIX_PATH=$GRPC_FOLDER ..
cmake --build . --config Release 

#cleanup
# cd .. && rm -rf build