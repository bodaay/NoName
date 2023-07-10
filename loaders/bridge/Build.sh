#!/bin/bash
export PATH="/usr/local/cuda-11.8/bin:$PATH"
export LD_LIBRARY_PATH="/usr/local/cuda-11.8/lib64:$LD_LIBRARY_PATH"
CUDAVERSON="11.8"
# rm -rf build
mkdir -p build
cd build


cmake -DCMAKE_PREFIX_PATH=/home/khalefa/projects/NoName/loaders/bridge/PACKAGES/grpc ..
cmake --build . --config Release 

#cleanup
# cd .. && rm -rf build