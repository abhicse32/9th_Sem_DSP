#ifndef STACK_A
#define STACK_A

#include <stdbool.h>

typedef struct Stack_a {
    int *arr;
    int top;
} stack;

// create a new stack
stack *stack_new();

// push an element on the stack
void stack_push(stack *, int);

// pop the top element from the stack
int stack_pop(stack *);

// Check if stack is empty
bool stack_is_empty(stack *);

// bool check if stack is full
bool stack_is_full(stack *);

// find the size of the stack
int stack_size(stack *);

// print stack element
void stack_print(stack *);

#endif