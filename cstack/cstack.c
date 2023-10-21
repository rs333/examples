#include <stdio.h>
#include "stack.h"

int main(int argc, char** argv){
    Stack s1, s2;
    int n;
#ifdef USE_ARRAY
    s1 = stack_create();
    s2 = stack_create();
#else
    s1 = stack_create(100);
    s2 = stack_create(200);
#endif


    stack_push(s1, 1);
    stack_push(s1, 2);

    n = stack_pop(s1);
    printf("Popped %d from s1\n", n);
    stack_push(s2,n);
    n=stack_pop(s1);
    printf("Popped %d from s1\n", n);
    stack_push(s2,n);

    stack_destroy(s1);
    
    while( !is_stack_empty(s2)){
        printf("Popped %d from s2\n", stack_pop(s2));
    }
    
    stack_push(s2,3);
    stack_empty(s2);
    if( is_stack_empty(s2)){
        printf("s2 is empty.\n");
    }else{
        printf("s2 is not empty.\n");
    }

    stack_destroy(s2);

    return 0;
}