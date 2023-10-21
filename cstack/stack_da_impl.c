#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
    {
        terminate("Failed to allocate memory for stack.");
    }
    s->contents = malloc(size * sizeof(Item));
    if( s->contents == NULL){
        free(s);
        terminate("Failed to allocate memory for stack.");
    }
    s->top = 0;
    s->size = size;
    return s;
}

void stack_destroy(Stack s)
{
    free(s->contents);
    free(s);
}

inline bool is_stack_empty(Stack s)
{
    return s->top == 0;
}

inline bool is_stack_full(Stack s)
{
    return s->top >= s->size;
}

void stack_push(Stack s, int i)
{
    if( is_stack_full(s) ){
        terminate("Stack is full!");
    }
    s->contents[s->top++]=i;
}

int stack_pop(Stack s){
    if( is_stack_empty(s) ){
        terminate("Stack is empty!");
    }
    return s->contents[--(s->top)];
}

void stack_empty(Stack s){
    s->top = 0;
}