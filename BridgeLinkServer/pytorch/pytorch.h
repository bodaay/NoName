#ifndef B_TORCH_H
#define B_TORCH_H

#ifdef __cplusplus
extern "C" {
#endif

int torch_cuda_device_count();
bool cuda_is_available();

// Struct for memory status
typedef struct {
    float total;
    float allocated;
    float available;
} MemoryStatus;
// Function to get GPU memory status
MemoryStatus getGPUMemoryStatus(int deviceId);

#ifdef __cplusplus
}
#endif

#endif // GO_TORCH_H