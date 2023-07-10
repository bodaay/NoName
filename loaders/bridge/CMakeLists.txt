cmake_minimum_required(VERSION 3.20)
project(Bridge)

set(CMAKE_CXX_STANDARD 17)

set(OPENSSL_USE_STATIC_LIBS TRUE)

set(CMAKE_VERBOSE_MAKEFILE ON)

# set(OPENSSL_SSL_LIBRARY /usr/lib/x86_64-linux-gnu/libssl.so)                                                                                                                                                                                                                                              
# set(OPENSSL_CRYPTO_LIBRARY /usr/lib/x86_64-linux-gnu/libcrypto.so)                                                                                                                                                                                                                                        
find_package(OpenSSL REQUIRED)  
# Protobuf
set(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

# gRPC

set(_GRPC_GRPCPP gRPC::grpc++)
set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)

message(STATUS "Using protobuf ${Protobuf_VERSION}")
message(STATUS "Using gRPC ${gRPC_VERSION}")
message(STATUS "Protobuf libraries: ${Protobuf_LIBRARIES}")
message(STATUS "Protobuf include path: ${Protobuf_INCLUDE_DIRS}")
message(STATUS "Protobuf compiler libraries: ${Protobuf_PROTOC_LIBRARIES}")
message(STATUS "Protobuf compiler: ${Protobuf_PROTOC_EXECUTABLE}")



add_executable(Bridge src/bridge.cpp src/pb/bridge.pb.cc src/pb/bridge.grpc.pb.cc)
target_link_libraries(Bridge ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF} OpenSSL::SSL OpenSSL::Crypto)
