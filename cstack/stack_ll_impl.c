#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
    {
        terminate("Failed to allocate memory for stack.");
    }
    s->top = NULL;
    return s;
}

void stack_destroy(Stack s)
{
    stack_empty(s); 
    free(s);
}

inline bool is_stack_empty(Stack s)
{
    return s->top == NULL;
}

inline bool is_stack_full(Stack s)
{
    return false;
}

void stack_push(Stack s, int i)
{
    struct node *new_top = malloc(sizeof(struct node));
    if( new_top == NULL ){
        terminate("Stack is full!");
    }
    new_top->data = i;
    new_top->prev = s->top;
    s->top = new_top;
}

int stack_pop(Stack s){
    struct node *old_top;
    Item item;

    if( is_stack_empty(s) ){
        terminate("Stack is empty!");
    }
    old_top = s->top;
    item = old_top->data;
    s->top = old_top->prev;
    free(old_top); 

    return item;
}

void stack_empty(Stack s){
    while (!is_stack_empty(s)){
        stack_pop(s);
    }
}