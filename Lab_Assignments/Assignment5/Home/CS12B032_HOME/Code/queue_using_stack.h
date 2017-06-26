#ifndef QUEUE_USING_STACK
#define QUEUE_USING_STACK
#include <stdbool.h>
#include "stack.h"

typedef struct Queue_using_stack{
	stack* st1;
	stack* st2;
}queue_s;

// create a new queue
queue_s* queue_new();

// add an element to the queue
void enqueue(queue_s*, int);

// remove the front element from the queue
int dequeue(queue_s*);

// Check if queue is empty
bool queue_is_empty(queue_s*);

// find the size of the queue
int queue_size(queue_s*);

// print queue element
void queue_print(queue_s*);

#endif