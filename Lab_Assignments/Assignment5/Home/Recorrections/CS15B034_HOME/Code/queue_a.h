//queue_a.h by Raghavan S CS15B034 Home Assignment 5
#ifndef QUEUE_A
#define QUEUE_A
#include <stdbool.h>
#define INT_MIN -2147483648

typedef struct Queue_a{
	int *arr;
	int front;
	int rear;
}queue;

// create a new queue
queue* queue_new();

// add an element in the queue
void enqueue(queue*, int);

// remove the first element from the queue
int dequeue(queue*);

// Check if queue is empty
bool queue_is_empty(queue*);

// bool check if queue is full
bool queue_is_full(queue*);

// find the size of the queue
int queue_size(queue*);

// print queue element
void queue_print(queue*);

#endif
