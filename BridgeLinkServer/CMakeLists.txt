cmake_minimum_required(VERSION 3.20)
project(BridgeLinkServer)

set(GRPC_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/../libgrpc/INSTALL")
set(LIBTORCH_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/../libtorch/src")

set(INSTALL_DESTINATION_BINARIES "${CMAKE_CURRENT_SOURCE_DIR}/out")
set(INSTALL_DESTINATION_LIBRARIES "${INSTALL_DESTINATION_BINARIES}/lib")


################################################## CORE GRPC ########################################################

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
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${INSTALL_DESTINATION_BINARIES})
file(GLOB PB_SRC "pb/*.cc")
file(GLOB BRDIGE_SRC "*.cpp")
add_executable(bridgeLinkServer ${BRDIGE_SRC} ${PB_SRC})

set_target_properties(
    bridgeLinkServer
    PROPERTIES
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH "\$ORIGIN/lib"
)

install(TARGETS bridgeLinkServer
    RUNTIME DESTINATION ${INSTALL_DESTINATION_BINARIES})

# KEEP ADDING OTHER NEW MODELS/REFERENCES HERE FOR REFERNCING
target_link_libraries(
    bridgeLinkServer 
    ${_GRPC_GRPCPP} 
    ${_REFLECTION} 
    ${_PROTOBUF_LIBPROTOBUF} 
    OpenSSL::SSL 
    bridgetorch
)

################################################## BRIDGE PYTORCH ########################################################
set(CMAKE_PREFIX_PATH "${LIBTORCH_FOLDER}")
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")


# Add all CPP files to a variable
set(bridgetorchSourceFiles
    pytorch/pytorch.cpp)
# Create a library instead of an executable
add_library(bridgetorch SHARED ${bridgetorchSourceFiles})
target_link_libraries(bridgetorch "${TORCH_LIBRARIES}")
set_property(TARGET bridgetorch PROPERTY CXX_STANDARD 17)

# Set the output directory for the bridgetorch library
set_target_properties(
    bridgetorch 
    PROPERTIES 
    LIBRARY_OUTPUT_DIRECTORY ${INSTALL_DESTINATION_LIBRARIES}
)