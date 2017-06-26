#ifndef QUEUE_USING_STACK_H
#define QUEUE_USING_STACK_H
#include "stack.h"
#include <stdbool.h>
// create a new queue
stack* queue_using_stack_new();

// add an element to the queue
void enqueue_using_stack(stack*, int);

// remove the front element from the queue
int dequeue_using_stack(stack*);

// Check if queue is empty
bool queue_using_stack_is_empty(stack*);

// find the size of the queue
int queue_using_stack_size(stack*);

// print queue element
void queue_using_stack_print(stack*);

#endif
