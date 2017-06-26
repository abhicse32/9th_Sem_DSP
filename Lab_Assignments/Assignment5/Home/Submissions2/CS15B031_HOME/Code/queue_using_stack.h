//Author: Phalguna Rao Ch.
//CS15B031
#ifndef STACK_H
#define STACK_H
#include "List.h"
#include <stdbool.h>

typedef struct Stack{
	LList* top;
}stack;

// create a new stack
stack* queue_new();

// push an element on the stack
void enqueue(stack**, int);

// pop the top element from the stack
int dequeue(stack*);

// Check if stack is empty
bool queue_is_empty(stack*);

// find the size of the stack
int queue_size(stack*);

// print stack element
void queue_print(stack*);

#endif
