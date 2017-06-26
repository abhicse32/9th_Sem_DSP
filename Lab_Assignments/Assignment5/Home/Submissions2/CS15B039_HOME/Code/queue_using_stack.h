#ifndef QUEUE_USING_STACK
#define QUEUE_USING_STACK
#include <stdbool.h>

typedef struct Stack_a{
	int *arr;
	int top;
}stack;

// create a new queue
stack* queue_new();

// add an element in the queue
void enqueue(stack*, int);

// remove the first element from the queue
int dequeue(stack*);

// Check if queue is empty
bool queue_is_empty(stack*);

// bool check if queue is full
bool queue_is_full(stack*);

// find the size of the queue
int queue_size(stack*);

// print queue element
void queue_print(stack*);

#endif
