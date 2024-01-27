set(CMAKE_C_CLANG_TIDY
    clang-tidy;
    --checks=*,cert-*,google-*,-llvmlibc-*,-altera-*,-cpp*;
)
add_executable(argcargv argcargv.c)