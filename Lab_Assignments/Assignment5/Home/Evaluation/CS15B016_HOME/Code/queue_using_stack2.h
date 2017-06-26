#ifndef QUEUE_H
#define QUEUE_H
#include "stack.h"
#include <stdbool.h>
typedef struct Queue{
	stack* front;
//	LList* rear;
}queue;

// create a new queue
queue* queue_new();

// add an element to the queue
void enqueue(queue*, int);

// remove the front element from the queue
int dequeue(queue*);

// Check if queue is empty
bool queue_is_empty(queue*);

// find the size of the queue
int queue_size(queue*);

// print queue element
void queue_print(queue*);

#endif