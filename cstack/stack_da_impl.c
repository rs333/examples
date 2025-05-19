#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack_type
{
    Item *contents;
    int top;
    int size;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack stack_create(int size)
{
    Stack stack = malloc(sizeof(struct stack_type));
    if (stack == NULL)
    {
        terminate("Failed to allocate memory for stack.");
    }
    stack->contents = malloc(size * sizeof(Item));
    if( stack->contents == NULL){
        free(stack);
        terminate("Failed to allocate memory for stack.");
    }
    stack->top = 0;
    stack->size = size;
    return stack;
}

void stack_destroy(Stack stack)
{
    free(stack->contents);
    free(stack);
}

inline bool is_stack_empty(Stack stack)
{
    return stack->top == 0;
}

inline bool is_stack_full(Stack stack)
{
    return stack->top >= stack->size;
}

void stack_push(Stack stack, int item)
{
    if( is_stack_full(stack) ){
        terminate("Stack is full!");
    }
    stack->contents[stack->top++]=item;
}

int stack_pop(Stack stack){
    if( is_stack_empty(stack) ){
        terminate("Stack is empty!");
    }
    return stack->contents[--(stack->top)];
}

void stack_empty(Stack stack){
    stack->top = 0;
}