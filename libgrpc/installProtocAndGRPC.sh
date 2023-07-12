#!/bin/bash

# PROTOBUF_VERSION="23.4" # No need. somce grpc include protobuf library as well
GRPC_VERSION="v1.56.0"
# Update system
sudo apt-get update

# Install dependencies
for pkg in build-essential autoconf libtool pkg-config;
do
    if ! dpkg -s $pkg >/dev/null 2>&1;
    then
        sudo apt-get install $pkg -y
    fi
done

# # Download, compile and install protobuf locally

SRC_FOLDER="src"
INSTALL_FOLDER="INSTALL"

# mkdir -p $INSTALL_FOLDER


# Clone gRPC if not exist

if [ ! -d "$SRC_FOLDER" ];
then
    git clone --recurse-submodules -b $GRPC_VERSION --depth 1 --shallow-submodules https://github.com/grpc/grpc $SRC_FOLDER
fi

# Build gRPC
pushd $SRC_FOLDER
mkdir -p cmake/build 
pushd cmake/build
# for SSL, I dont need to be local, we just need to make sure we have installed: libssl-dev,libcrypt-dev,libcrypto++-dev

cmake -DgRPC_INSTALL=ON \
      -DgRPC_BUILD_TESTS=OFF \
      -DCMAKE_INSTALL_PREFIX=../../../$INSTALL_FOLDER \
      ../..

make -j 10
make install
popd
# Echo versions
popd
echo "Installed versions:"
$INSTALL_FOLDER/bin/protoc --version

# rm -rf grpc