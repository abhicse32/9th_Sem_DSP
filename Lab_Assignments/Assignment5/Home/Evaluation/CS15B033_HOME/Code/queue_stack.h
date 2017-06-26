#ifndef QUEUE1_H
#define QUEUE1_H
#include "List.h"
#include <stdbool.h>

typedef struct Stack{
	LList* top;
}stack;

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