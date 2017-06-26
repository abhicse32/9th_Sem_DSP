#ifndef QUEUE_A
#define QUEUE_A
#include <stdbool.h>

typedef struct Queue_a{
	int *arr;
	int front;
	int rear;
	int count;
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
