cmake_minimum_required(VERSION 3.22)

project( examples )
set( CMAKE_C_STANDARD 11 )

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_CLANG_TIDY
    clang-tidy;
    --checks=*,cert-*,google-*,-llvmlibc-*,-altera-*,-cpp*;
    --fix;
)

enable_testing()
include(FetchContent)

######################################################
# Google Test
######################################################
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

######################################################
# FFTW
######################################################
find_package(PkgConfig REQUIRED)
pkg_search_module(FFTW REQUIRED fftw3 IMPORTED_TARGET)

######################################################
# libeigen3
######################################################
find_package( Eigen3 3.3 REQUIRED NO_MODULE )

######################################################
# JSON For Modern C++
######################################################
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

add_subdirectory( argcargv )
add_subdirectory( bitmagic )
add_subdirectory( crazymacros )
add_subdirectory( cstack )
add_subdirectory( eigen )
add_subdirectory( fftw3simple )
add_subdirectory( floatbits )
add_subdirectory( jsondefault )
