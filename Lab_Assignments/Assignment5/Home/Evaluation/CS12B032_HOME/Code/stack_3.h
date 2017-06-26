#ifndef STACK_3_H
#define STACK_3_H
#include "List_3.h"
#include <stdbool.h>

typedef struct Stack{
	LList* top;
}stack;

// create a new stack
stack* stack_new();

// push an element on the stack
void stack_push(stack*, char*);

// pop the top element from the stack
char* stack_pop(stack*);
char* stack_top(stack*);
// Check if stack is empty
bool stack_is_empty(stack*);

// find the size of the stack
int stack_size(stack*);

// print stack element
void stack_print(stack*);

#endif
