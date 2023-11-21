# Random Examples
This is a repository of random examples used for testing out code snippets.

## Dependencies
Some dependencies are downlaoded as part of the CMake build process.  Those that require installation are _italicized_ Others are listed here.  
- _[FFTW3](https://fftw.org)_ - Tested on Windows with `mingw-w64-x86_64-fftw`
- [JSON For Modern C++](https://github.com/nlohmann/json) - Nlohmann C++ Json Parser
- [libeigen3](https://eigen.tuxfamily.org/) - A C++ template library for linear algebra

## Static Analysis
```bash
cd build
scan-build cmake ../
scan-build -o . make
```
