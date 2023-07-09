#!/bin/bash

PROTOC_VERSION="23.4"
GRPC_VERSION="v1.56.0"
# Update system
sudo apt-get update

# Install dependencies
for pkg in autoconf automake libtool curl make g++ unzip build-essential pkg-config git;
do
    if ! dpkg -s $pkg >/dev/null 2>&1;
    then
        sudo apt-get install $pkg -y
    fi
done

# Download protobuf if not exist
# https://github.com/protocolbuffers/protobuf/releases/download/v23.4/protoc-23.4-linux-x86_64.zip
if [ ! -f "/usr/local/bin/protoc" ];
then                            
    curl -OL https://github.com/protocolbuffers/protobuf/releases/download/v$PROTOC_VERSION/protoc-$PROTOC_VERSION-linux-x86_64.zip
    unzip protoc-$PROTOC_VERSION-linux-x86_64.zip -d protoc3
    sudo mv protoc3/bin/* /usr/local/bin/
    sudo mv protoc3/include/* /usr/local/include/
    sudo ldconfig
    rm -rf protoc3 protoc-$PROTOC_VERSION-linux-x86_64.zip
fi

# Clone gRPC if not exist

if [ ! -d "$HOME/grpc" ];
then
    git clone -b $GRPC_VERSION https://github.com/grpc/grpc
    cd grpc
    git submodule update --init
fi

# Build gRPC
cd grpc
mkdir -p cmake/build
cd cmake/build
cmake ../..
make
sudo make install

# Echo versions
echo "Installed versions:"
protoc --version
