#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
    {
        terminate("Failed to allocate memory for stack.");
    }
    s->top = 0;
    return s;
}

void stack_destroy(Stack s)
{
    free(s);
}

inline bool is_stack_empty(Stack s)
{
    return s->top == 0;
}

inline bool is_stack_full(Stack s)
{
    return s->top >= STACK_SIZE;
}

void stack_push(Stack s, Item i)
{
    if( is_stack_full(s) ){
        terminate("Stack is full!");
    }
    s->contents[s->top++]=i;
}

Item stack_pop(Stack s){
    if( is_stack_empty(s) ){
        terminate("Stack is empty!");
    }
    return s->contents[--(s->top)];
}

void stack_empty(Stack s){
    s->top = 0;
}