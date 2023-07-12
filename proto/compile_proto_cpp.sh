#!/bin/bash                                                                                                                  

# Set the paths to the protoc compiler and the grpc_cpp_plugin                                                               
PROTOC_PATH="../libgrpc/INSTALL/bin/protoc"                                                                                                
GRPC_CPP_PLUGIN_PATH="../libgrpc/INSTALL/bin/grpc_cpp_plugin"                                                                          
                                                                                                                                
# Set the path to the directory containing your_service.proto                                                                
PROTO_FILE_DIR="./"                                                                                      
                                                                                                                                
# Set the output directory for the generated cod
OUTPUT_DIR_CPP="../BridgeLinkServer/pb"
OUTPUT_DIR_GO="../BridgeLinkClient/pb" # specify your output path for Go files


$PROTOC_PATH --proto_path=$PROTO_FILE_DIR --cpp_out=$OUTPUT_DIR_CPP --grpc_out=$OUTPUT_DIR_CPP --plugin=protoc-gen-grpc=$GRPC_CPP_PLUGIN_PATH bridge.proto 


# Generate Go files
$PROTOC_PATH --proto_path=$PROTO_FILE_DIR --go_out=$OUTPUT_DIR_GO --go_opt paths=source_relative --go-grpc_out=$OUTPUT_DIR_GO --go-grpc_opt paths=source_relative bridge.proto