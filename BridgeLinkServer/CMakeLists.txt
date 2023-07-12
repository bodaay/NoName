cmake_minimum_required(VERSION 3.20)
project(BridgeLinkServer)
set(GRPC_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/../libgrpc/INSTALL")

set(CMAKE_CXX_STANDARD 17)

set(OPENSSL_USE_STATIC_LIBS TRUE)

# set(CMAKE_VERBOSE_MAKEFILE ON)cd 
set(CMAKE_PREFIX_PATH "${GRPC_FOLDER}/lib/cmake/absl/")
find_package(absl CONFIG REQUIRED)


set(CMAKE_PREFIX_PATH "${GRPC_FOLDER}/lib/cmake/utf8_range/")
find_package(utf8_range CONFIG REQUIRED)

set(CMAKE_PREFIX_PATH "${GRPC_FOLDER}/lib/cmake/protobuf/")
find_package(Protobuf CONFIG REQUIRED)
set(CMAKE_PREFIX_PATH "${GRPC_FOLDER}/lib/cmake/grpc/")
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


# Set the directory for the output executable files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

file(GLOB PB_SRC "pb/*.cc")

add_executable(bridgeLinkServer bridge.cpp ${PB_SRC})
target_link_libraries(bridgeLinkServer ${_GRPC_GRPCPP} ${_REFLECTION} ${_PROTOBUF_LIBPROTOBUF} OpenSSL::SSL)
