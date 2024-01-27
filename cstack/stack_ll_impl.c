#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
    Item data;
    struct node *prev;
};

struct stack_type
{
    struct node *top;
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
    stack->top = NULL;
    return stack;
}

void stack_destroy(Stack stack)
{
    stack_empty(stack); 
    free(stack);
}

inline bool is_stack_empty(Stack stack)
{
    return stack->top == NULL;
}

inline bool is_stack_full(Stack stack)
{
    return false;
}

void stack_push(Stack stack, int item)
{
    struct node *new_top = malloc(sizeof(struct node));
    if( new_top == NULL ){
        terminate("Stack is full!");
    }
    new_top->data = item;
    new_top->prev = stack->top;
    stack->top = new_top;
}

int stack_pop(Stack stack){
    struct node *old_top;
    Item item;

    if( is_stack_empty(stack) ){
        terminate("Stack is empty!");
    }
    old_top = stack->top;
    item = old_top->data;
    stack->top = old_top->prev;
    free(old_top); 

    return item;
}

void stack_empty(Stack stack){
    while (!is_stack_empty(stack)){
        stack_pop(stack);
    }
}