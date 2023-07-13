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


Status PyTorchServiceImpl::GetGPUMemoryInfo(
    ServerContext* context, 
    const CudaMemInfoRequest* request, 
    CudaMemInfoResponse* reply) {
    
    int deviceId = request->cudadeviceid();
    MemoryStatus status = getGPUMemoryStatus(deviceId); //TODO: Handle this in a better way, handle the errors properly and return the actual cuda_status error
    if (status.total==0) return Status(grpc::NOT_FOUND, "Invalid Device Cuda Device ID");
    reply->set_totalmemorymb(status.total);
    reply->set_totalallocatedmb(status.allocated);
    reply->set_totalavailablemb(status.available);

    return Status::OK;
}