cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(gotorch)


find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")





# Add all CPP files to a variable
set(SOURCES
  src/gotorch.cpp
)



# Create a library instead of an executable
add_library(gotorch SHARED ${SOURCES})
target_link_libraries(gotorch "${TORCH_LIBRARIES}")
set_property(TARGET gotorch PROPERTY CXX_STANDARD 17)
