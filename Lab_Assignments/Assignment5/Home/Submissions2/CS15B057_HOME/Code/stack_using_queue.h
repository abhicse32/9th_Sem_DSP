#ifndef STACK_USING_QUEUE_H
#define STACK_USING_QUEUE_H
#include "queue.h"
#include <stdbool.h>

// create a new stack
queue* stack_using_queue_new();

// push an element on the stack
void stack_using_queue_push(queue*, int);

// pop the top element from the stack
int stack_using_queue_pop(queue*);

// Check if stack is empty
bool stack_using_queue_is_empty(queue*);

// find the size of the stack
int stack_using_queue_size(queue*);

// print stack element
void stack_using_queue_print(queue*);

#endif
