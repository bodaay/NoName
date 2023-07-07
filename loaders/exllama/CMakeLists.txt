cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(exllama)


find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")





# Add all CPP files to a variable
set(SOURCES
  src/exllama_ext/exllama_ext.cpp
  src/exllama_ext/cuda_buffers.cu
  src/exllama_ext/cuda_func/q4_matrix.cu
  src/exllama_ext/cuda_func/q4_matmul.cu
  src/exllama_ext/cuda_func/column_remap.cu
  src/exllama_ext/cuda_func/rms_norm.cu
  src/exllama_ext/cuda_func/rope.cu
  src/exllama_ext/cuda_func/half_matmul.cu
  src/exllama_ext/cuda_func/q4_attn.cu
  src/exllama_ext/cuda_func/q4_mlp.cu
  src/exllama_ext/cpu_func/rep_penalty.cpp
)



# Create a library instead of an executable
add_library(exllama SHARED ${SOURCES})
target_link_libraries(exllama "${TORCH_LIBRARIES}")
set_property(TARGET exllama PROPERTY CXX_STANDARD 17)
