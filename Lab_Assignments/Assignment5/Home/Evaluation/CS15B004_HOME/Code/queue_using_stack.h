#ifndef QUEUE_H
#define QUEUE_H
#include "stack.h"
#include <stdbool.h>

typedef struct Queue{
	LList* front;
	LList* rear;
}queue;

// create a new queue
stack* queue_new();

// add an element to the queue
void enqueue(stack*, int);

// remove the front element from the queue
int dequeue(stack*);

// Check if queue is empty
bool queue_is_empty(stack*);

// find the size of the queue
int queue_size(stack*);

// print queue element
void queue_print(stack*);

#endif
