#ifndef QUEUE_USING_STACK_H
#define QUEUE_USING_STACK_H
#include "List.h"
#include "stack.h"
#include <stdbool.h>

// Create a new queue
stack* queue_new();

// Add an element to the queue
void enqueue(stack*, int);

// Remove the front element from the queue
int dequeue(stack*);

// Check if queue is empty
bool queue_is_empty(stack*);

// Find the size of the queue
int queue_size(stack*);

// Print queue element
void queue_print(stack*);

#endif 
