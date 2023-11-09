
add_executable(fftw3simple fftw3simple.cpp)

target_link_libraries( fftw3simple 
  PkgConfig::FFTW
  Eigen3::Eigen
)