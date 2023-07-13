I had to separate the actual repo source, from my modified source. 

Mostly I need to remove any import to python.h, and remove the python binding PYBIND11_MODULE

this is built on this source code:

https://github.com/PanQiWei/AutoGPTQ