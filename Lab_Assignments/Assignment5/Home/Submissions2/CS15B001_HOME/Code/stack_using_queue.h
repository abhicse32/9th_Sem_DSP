#ifndef STACK_USING_QUEUE_H
#define STACK_USING_QUEUE_H
#include "List.h"
#include <stdbool.h>
#include <limits.h>

typedef struct Queue{
	LList* front;
	LList* rear;
}queue;

// create a new queue
queue* queue_new();

//reverses the given queue
void queue_reverse(queue*);

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
