#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

struct stack_type
{
    Item contents[STACK_SIZE];
    int top;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack stack_create(void)
{
    Stack stack = malloc(sizeof(struct stack_type));
    if (stack == NULL)
    {
        terminate("Failed to allocate memory for stack.");
    }
    stack->top = 0;
    return stack;
}

void stack_destroy(Stack stack)
{
    free(stack);
}

inline bool is_stack_empty(Stack stack)
{
    return stack->top == 0;
}

inline bool is_stack_full(Stack stack)
{
    return stack->top >= STACK_SIZE;
}

void stack_push(Stack stack, Item item)
{
    if( is_stack_full(stack) ){
        terminate("Stack is full!");
    }
    stack->contents[stack->top++]=item;
}

Item stack_pop(Stack stack){
    if( is_stack_empty(stack) ){
        terminate("Stack is empty!");
    }
    return stack->contents[--(stack->top)];
}

void stack_empty(Stack stack){
    stack->top = 0;
}