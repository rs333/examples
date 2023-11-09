cmake_minimum_required(VERSION 3.22)

project( examples )
set( CMAKE_C_STANDARD 99 )

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

find_package(PkgConfig REQUIRED)
pkg_search_module(FFTW REQUIRED fftw3 IMPORTED_TARGET)

find_package( Eigen3 3.3 REQUIRED NO_MODULE )

add_subdirectory( argcargv )
add_subdirectory( bitmagic )
add_subdirectory( crazymacros )
add_subdirectory( cstack )
add_subdirectory( eigen )
add_subdirectory( fftw3simple )
add_subdirectory( floatbits )