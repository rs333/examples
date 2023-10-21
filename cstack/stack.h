#pragma once
#include <stdbool.h>

typedef int Item;

typedef struct stack_type *Stack;

#ifdef USE_ARRAY
Stack stack_create(void);
#else 
Stack stack_create(int size);
#endif

void stack_destroy(Stack s);
void stack_empty(Stack s);
bool is_stack_empty(Stack s);
bool is_stack_full(Stack s);
void stack_push(Stack s, int i);
int stack_pop(Stack s);
