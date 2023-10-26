find_package( Eigen3 3.3 REQUIRED NO_MODULE )

add_executable( eigen eigen.cpp )
target_link_libraries( eigen Eigen3::Eigen)