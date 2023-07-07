cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(autogptq)

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

# Separate the source files for each library
set(SOURCES_64
  src/autogptq_cuda_64.cpp
  src/autogptq_cuda_kernel_64.cu
)

set(SOURCES_256
  src/autogptq_cuda_256.cpp
  src/autogptq_cuda_kernel_256.cu
)

# Create a library for each set of source files
add_library(autogptq_cuda_64 SHARED ${SOURCES_64})
target_link_libraries(autogptq_cuda_64 "${TORCH_LIBRARIES}")
set_property(TARGET autogptq_cuda_64 PROPERTY CXX_STANDARD 17)

add_library(autogptq_cuda_256 SHARED ${SOURCES_256})
target_link_libraries(autogptq_cuda_256 "${TORCH_LIBRARIES}")
set_property(TARGET autogptq_cuda_256 PROPERTY CXX_STANDARD 17)