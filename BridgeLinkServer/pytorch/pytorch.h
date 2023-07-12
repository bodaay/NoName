#ifndef B_TORCH_H
#define B_TORCH_H

#ifdef __cplusplus
extern "C" {
#endif

int torch_cuda_device_count();
bool cuda_is_available();

#ifdef __cplusplus
}
#endif

#endif // GO_TORCH_H