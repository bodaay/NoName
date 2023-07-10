cmake_minimum_required(VERSION 3.20)
project(Bridge)

set(CMAKE_CXX_STANDARD 17)

set(OPENSSL_USE_STATIC_LIBS TRUE)

# set(CMAKE_VERBOSE_MAKEFILE ON)cd 
set(CMAKE_PREFIX_PATH "PACKAGES/grpc/lib/cmake/absl/")
find_package(absl CONFIG REQUIRED)


set(CMAKE_PREFIX_PATH "PACKAGES/grpc/lib/cmake/utf8_range/")
find_package(utf8_range CONFIG REQUIRED)

set(CMAKE_PREFIX_PATH "PACKAGES/grpc/lib/cmake/protobuf/")
find_package(Protobuf CONFIG REQUIRED)
set(CMAKE_PREFIX_PATH "PACKAGES/grpc/lib/cmake/grpc/")
find_package(gRPC CONFIG REQUIRED)

# set(OPENSSL_ROOT_DIR /usr/lib/x86_64-linux-gnu/)
# set(OPENSSL_LIBRARIES /usr/lib/x86_64-linux-gnu/)
find_package(OpenSSL REQUIRED)  
if(OpenSSL_FOUND)
    include_directories(${OPENSSL_INCLUDE_DIR})
    message(STATUS "OpenSSL SSL Library: ${OPENSSL_SSL_LIBRARY}")
    message(STATUS "OpenSSL Crypto Library: ${OPENSSL_CRYPTO_LIBRARY}")
endif()


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
target_link_libraries(Bridge ${_GRPC_GRPCPP} ${_REFLECTION} ${_PROTOBUF_LIBPROTOBUF} OpenSSL::SSL)
