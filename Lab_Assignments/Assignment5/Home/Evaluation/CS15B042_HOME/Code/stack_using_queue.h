#ifndef STACK_USING_QUEUE_H
#define STACK_USING_QUEUE_H
#include "List.h"
#include "queue.h"
#include <stdbool.h>

// create a new stack
queue * stack_new();

// push an element on the stack
void stack_push(queue *, int);

// pop the top element from the stack
int stack_pop(queue*);

// Check if stack is empty
bool stack_is_empty(queue *);

// find the size of the stack
int stack_size(queue *);

// print stack element
void stack_print(queue *);

#endif