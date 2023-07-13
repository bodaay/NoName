#ifndef GO_TORCH_H
#define GO_TORCH_H

#ifdef __cplusplus
extern "C" {
#endif

int torch_cuda_device_count();
int cuda_is_available();

#ifdef __cplusplus
}
#endif

#endif // GO_TORCH_H