#include "gotorch.h"
#include <torch/torch.h>

int torch_cuda_device_count() {
    return torch::cuda::device_count();
}


int cuda_is_available() {
    return torch::cuda::is_available() ? 1 : 0;
}