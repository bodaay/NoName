#!/bin/bash

PROTOBUF_VERSION="23.4"
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
# Download, compile and install protobuf
if [ -f "/usr/local/bin/protoc" ]; then                                                                                                                                                                                                                                               
    read -p "/usr/local/bin/protoc exists. Do you want to reinstall? (y/n) " -n 1 -r                                                                                                                                                                                                  
    echo                                                                                                                                                                                                                                                                              
    if [[ $REPLY =~ ^[Yy]$ ]]                                                                                                                                                                                                                                                         
    then                                                                                                                                                                                                                                                                              
        # https://github.com/protocolbuffers/protobuf/releases/download/v23.4/protobuf-23.4.tar.gz                                                                                                                                                                                    
        curl -OL https://github.com/protocolbuffers/protobuf/releases/download/v$PROTOBUF_VERSION/protobuf-$PROTOBUF_VERSION.tar.gz                                                                                                                                                   
        tar xzf protobuf-$PROTOBUF_VERSION.tar.gz                                                                                                                                                                                                                                     
        cd protobuf-$PROTOBUF_VERSION/third_party                                                                                                                                                                                                                                     
        rm -rf abseil-cpp                                                                                                                                                                                                                                                             
        git clone https://github.com/abseil/abseil-cpp                                                                                                                                                                                                                                
        cd ../                                                                                                                                                                                                                                                                        
        cmake -Dprotobuf_BUILD_TESTS=OFF .                                                                                                                                                                                                                                            
        cmake --build . --parallel 10                                                                                                                                                                                                                                                 
        sudo cmake --install .                                                                                                                                                                                                                                                        
        sudo ldconfig                                                                                                                                                                                                                                                                 
        cd ..                                                                                                                                                                                                                                                                         
        rm -rf protobuf-$PROTOBUF_VERSION protobuf-$PROTOBUF_VERSION.tar.gz                                                                                                                                                                                                           
    fi                                                                                                                                                                                                                                                                                
else                                                                                                                                                                                                                                                                                  
    # https://github.com/protocolbuffers/protobuf/releases/download/v23.4/protobuf-23.4.tar.gz                                                                                                                                                                                        
    curl -OL https://github.com/protocolbuffers/protobuf/releases/download/v$PROTOBUF_VERSION/protobuf-$PROTOBUF_VERSION.tar.gz                                                                                                                                                       
    tar xzf protobuf-$PROTOBUF_VERSION.tar.gz                                                                                                                                                                                                                                         
    cd protobuf-$PROTOBUF_VERSION/third_party                                                                                                                                                                                                                                         
    rm -rf abseil-cpp                                                                                                                                                                                                                                                                 
    git clone https://github.com/abseil/abseil-cpp                                                                                                                                                                                                                                    
    cd ../                                                                                                                                                                                                                                                                            
    cmake -Dprotobuf_BUILD_TESTS=OFF .                                                                                                                                                                                                                                                
    cmake --build . --parallel 10                                                                                                                                                                                                                                                     
    sudo cmake --install .                                                                                                                                                                                                                                                            
    sudo ldconfig                                                                                                                                                                                                                                                                     
    cd ..                                                                                                                                                                                                                                                                             
    rm -rf protobuf-$PROTOBUF_VERSION protobuf-$PROTOBUF_VERSION.tar.gz                                                                                                                                                                                                               
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
