#include "stack.h"
#include <stdio.h>

const int STACK_SIZE=100;

int main(int argc, char** argv){ // NOLINT
    Stack stack_1;
    Stack stack_2;
    int n; // NOLINT(readability-identifier-length)
#ifdef USE_ARRAY
    stack_1 = stack_create();
    stack_2 = stack_create();
#else
    stack_1 = stack_create(STACK_SIZE);
    stack_2 = stack_create(2*STACK_SIZE);
#endif


    stack_push(stack_1, 1);
    stack_push(stack_1, 2);

    n = stack_pop(stack_1);
    printf("Popped %d from s1\n", n);
    stack_push(stack_2,n);
    n=stack_pop(stack_1);
    printf("Popped %d from s1\n", n);
    stack_push(stack_2,n);

    stack_destroy(stack_1);
    
    while( !is_stack_empty(stack_2)){
        printf("Popped %d from s2\n", stack_pop(stack_2));
    }
    
    stack_push(stack_2,3);
    stack_empty(stack_2);
    if( is_stack_empty(stack_2)){
        printf("s2 is empty.\n");
    }else{
        printf("s2 is not empty.\n");
    }

    stack_destroy(stack_2);

    return 0;
}