#ifndef STACK_H
#define STACK_H
#include "List.h"
#include <stdbool.h>
#include "binary_tree.h"

typedef struct Stack{
	LList* top;
}stack;

// create a new stack
stack* stack_new();

// push an element on the stack
void stack_push(stack*, Node*);

// pop the top element from the stack
Node* stack_pop(stack*);

// Check if stack is empty
bool stack_is_empty(stack*);

Node* stack_top(stack* st);

// find the size of the stack
int stack_size(stack*);

// print stack element
void stack_print(stack*);

#endif