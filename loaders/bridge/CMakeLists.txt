cmake_minimum_required(VERSION 3.13)
project(Bridge)

set(CMAKE_CXX_STANDARD 17)

find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

add_executable(Bridge src/bridge.cpp src/pb/bridge.pb.cc src/pb/bridge.grpc.pb.cc)
target_link_libraries(Bridge gRPC::grpc++ ${Protobuf_LIBRARIES})


message(STATUS "Using protobuf ${protobuf_VERSION}")
message(STATUS "Using gRPC ${gRPC_VERSION}")
message(STATUS "Protobuf libraries: ${Protobuf_LIBRARIES}")
message(STATUS "Protobuf include path: ${Protobuf_INCLUDE_DIRS}")
message(STATUS "Protobuf compiler libraries: ${Protobuf_PROTOC_LIBRARIES}")
message(STATUS "Protobuf compiler: ${Protobuf_PROTOC_EXECUTABLE}")
message(STATUS "gRPC libraries: ${gRPC_LIBRARIES}")
message(STATUS "gRPC include path: ${gRPC_INCLUDE_DIRS}")