#!/bin/bash

output_folder="out"
output_binary="${output_folder}/bridgeLinkServer"
library_folder="${output_folder}/lib"
CUDAVERSON="11.8"
PATH="/usr/local/cuda-${CUDAVERSON}/bin:${PATH}"
LD_LIBRARY_PATH="/usr/local/cuda-${CUDAVERSON}/lib64:${LD_LIBRARY_PATH}"
# rm -rf build
mkdir -p build
pushd build
# echo 
cmake -DCUDA_BIN_PATH=/usr/local/cuda-$CUDAVERSON/bin/ -DCUDA_TOOLKIT_ROOT_DIR=/usr/local/cuda-$CUDAVERSON/ ..
cmake --build . --config Release 
cmake --install . 
popd


# copy all required libraries to the output folder

# The directory of your executable
exe_dir=$output_binary # change this to your own path

# The directory to copy libraries to
lib_dir=$library_folder # change this to your own path

# Get all the linked libraries
libraries=$(ldd $output_binary | awk '{ print $3 }')

# Copy all the libraries to your library directory
for lib in $libraries
do
    if [ "$lib" != "" ] && [ -e $lib ]; then
        cp -L $lib $lib_dir/
    fi
done

# mv bin/bridgeLinkServer bin/bridgeLinkServer_linux_x86_64
#cleanup
# cd .. && rm -rf build