#!/bin/bash                                                                                                                  

# Set the paths to the protoc compiler and the grpc_cpp_plugin                                                               
PROTOC_PATH="/usr/local/bin/protoc"                                                                                                
GRPC_CPP_PLUGIN_PATH="/usr/local/bin/grpc_cpp_plugin"                                                                          
                                                                                                                                
# Set the path to the directory containing your_service.proto                                                                
PROTO_FILE_DIR="./"                                                                                      
                                                                                                                                
# Set the output directory for the generated code                                                                            
OUTPUT_DIR="../src/pb/"                                                                                        
                                                                                                                                

$PROTOC_PATH --proto_path=$PROTO_FILE_DIR --cpp_out=$OUTPUT_DIR --grpc_out=$OUTPUT_DIR --plugin=protoc-gen-grpc=$GRPC_CPP_PLUGIN_PATH bridge.proto 


