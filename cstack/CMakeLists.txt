add_executable( cstack_array cstack.c stack_array_impl.c )
target_compile_definitions(cstack_array PUBLIC USE_ARRAY)

add_executable( cstack_da cstack.c stack_da_impl.c )
target_compile_definitions(cstack_da PUBLIC USE_DYNAMIC_ARRAY)

add_executable( cstack_ll cstack.c stack_ll_impl.c )
target_compile_definitions(cstack_ll PUBLIC USE_LL )