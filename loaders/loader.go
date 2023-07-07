package main

/*
#cgo CFLAGS: -I${SRCDIR}/lib
#cgo LDFLAGS: -L${SRCDIR}/lib -Wl,-rpath=\$ORIGIN/lib -lexllama
#include "go_exllama.h"
*/
import "C"

func main() {
	C.cleanup()
}
