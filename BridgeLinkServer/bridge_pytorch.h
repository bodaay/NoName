#include <grpcpp/grpcpp.h>
#include "pb/bridgelink_pytorch.grpc.pb.h" // Generated from your protos
#include "pytorch/pytorch.h"
using bridgelink::PyTorchService;
//  CUDA Service Implemenation
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::ServerWriter;
using bridgelink::CudaAvailableRequest; //for the new service
using bridgelink::CudaAvailableResponse; //for the new service
using bridgelink::CudaDeviceCountRequest; //for the new service
using bridgelink::CudaDeviceCountResponse; //for the new service
using bridgelink::CudaMemInfoRequest;
using bridgelink::CudaMemInfoResponse;

class PyTorchServiceImpl final : public PyTorchService::Service {
public:
     Status IsCudaAvailable(
          ServerContext* context, 
          const CudaAvailableRequest* request, 
          CudaAvailableResponse* reply) override;

     Status GetCudaDeviceCount(
          ServerContext* context, 
          const CudaDeviceCountRequest* request, 
          CudaDeviceCountResponse* reply) override;
     Status GetGPUMemoryInfo(
          ServerContext* context, 
          const CudaMemInfoRequest* request, 
          CudaMemInfoResponse* reply) override;
};