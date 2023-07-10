#!/bin/bash

PROTOBUF_VERSION="23.4"
GRPC_VERSION="v1.56.0"
# Update system
sudo apt-get update

# Install dependencies
for pkg in autoconf automake libtool curl make g++ unzip build-essential pkg-config libcrypt-dev libcrypto++-dev libssl-dev git;
do
    if ! dpkg -s $pkg >/dev/null 2>&1;
    then
        sudo apt-get install $pkg -y
    fi
done

# # Download, compile and install protobuf locally

INSTALL_FOLDER="PACKAGES"

# mkdir -p $INSTALL_FOLDER

# curl -OL https://github.com/protocolbuffers/protobuf/releases/download/v$PROTOBUF_VERSION/protobuf-$PROTOBUF_VERSION.tar.gz                                                                                                                                                       
# tar xzf protobuf-$PROTOBUF_VERSION.tar.gz                                                                                                                                                                                                                                         
# cd protobuf-$PROTOBUF_VERSION/third_party                                                                                                                                                                                                                                         
# rm -rf abseil-cpp                                                                                                                                                                                                                                                                 
# git clone https://github.com/abseil/abseil-cpp
# cd abseil-cpp
# cmake -DCMAKE_CXX_STANDARD=17 -DCMAKE_INSTALL_PREFIX=../../../$INSTALL_FOLDER/absl .
# cmake --build . --parallel 10
# cmake --install .
# cd ../../
# cmake -Dprotobuf_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=../$INSTALL_FOLDER/protobuf .
# cmake --build . --parallel 10
# cmake --install .
# cd ..
# rm -rf protobuf-$PROTOBUF_VERSION protobuf-$PROTOBUF_VERSION.tar.gz             


# Clone gRPC if not exist

if [ ! -d "$HOME/grpc" ];
then
    git clone --recurse-submodules -b $GRPC_VERSION --depth 1 --shallow-submodules https://github.com/grpc/grpc
fi

# Build gRPC
cd grpc
mkdir -p cmake/build 
cd cmake/build
# for SSL, I dont need to be local, we just need to make sure we have installed: libssl-dev,libcrypt-dev,libcrypto++-dev
cmake ../.. -DgRPC_INSTALL=ON                \
              -DCMAKE_BUILD_TYPE=Release       \
              -DgRPC_ABSL_PROVIDER=module     \
              -DgRPC_CARES_PROVIDER=module    \
              -DgRPC_PROTOBUF_PROVIDER=module \
              -DgRPC_RE2_PROVIDER=module      \
              -DgRPC_SSL_PROVIDER=packages      \
              -DgRPC_ZLIB_PROVIDER=module     \
              -DCMAKE_CXX_STANDARD=17       \
              -DCMAKE_INSTALL_PREFIX=../../../$INSTALL_FOLDER/grpc 

make -j 10
make install

# Echo versions
echo "Installed versions:"
$INSTALL_FOLDER/protobuf/bin/protoc --version
cd ../../../
# rm -rf grpc