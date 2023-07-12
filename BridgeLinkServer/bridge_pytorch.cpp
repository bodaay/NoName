#include "bridge_pytorch.h"

Status PyTorchServiceImpl::IsCudaAvailable(
    ServerContext* context, 
    const CudaAvailableRequest* request, 
    CudaAvailableResponse* reply) {
    reply->set_available(cuda_is_available()); 
    return Status::OK;
}

Status PyTorchServiceImpl::GetCudaDeviceCount(
    ServerContext* context, 
    const CudaDeviceCountRequest* request, 
    CudaDeviceCountResponse* reply) {
    reply->set_count(torch_cuda_device_count()); 
    return Status::OK;
}