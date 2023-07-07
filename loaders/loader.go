package main

/*
#cgo CFLAGS: -I${SRCDIR}/lib
#cgo LDFLAGS: -L${SRCDIR}/lib -Wl,-rpath=\$ORIGIN/lib -lexllama -lgotorch
#include "go_exllama.h"
#include "gotorch.h"

*/
import "C"
import "fmt"

func main() {
	if C.cuda_is_available() == 1 {
		fmt.Println("Yes there are cuda devices")
		deviceCount := C.torch_cuda_device_count()
		fmt.Printf("Number of CUDA devices: %d\n", int(deviceCount))
	}

	C.cleanup()
}
