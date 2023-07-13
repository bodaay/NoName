#include "pytorch.h"
#include <cuda_runtime.h>
#include <torch/torch.h>

int torch_cuda_device_count() {
    return torch::cuda::device_count();
}


bool cuda_is_available() {
    // return torch::cuda::is_available() ? 1 : 0;
    return torch::cuda::is_available();
}

MemoryStatus getGPUMemoryStatus(int deviceId) {
    cudaSetDevice(deviceId);

    size_t free_byte;
    size_t total_byte;
    cudaError_t cuda_status = cudaMemGetInfo(&free_byte, &total_byte);

    if (cudaSuccess != cuda_status) {
        printf("Error: cudaMemGetInfo fails, %s \n", cudaGetErrorString(cuda_status));
        
        // Return all zeros on error
        return MemoryStatus{0.0, 0.0, 0.0};
    }

    double total_db = (double)total_byte;
    double free_db = (double)free_byte;
    double used_db = total_db - free_db;

    MemoryStatus memoryStatus;
    memoryStatus.total = total_db / 1024.0 / 1024.0;
    memoryStatus.allocated = used_db / 1024.0 / 1024.0;
    memoryStatus.available = free_db / 1024.0 / 1024.0;

    return memoryStatus;
}