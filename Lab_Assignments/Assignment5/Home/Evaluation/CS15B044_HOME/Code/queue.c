#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include"List.h"
// create a new queue
queue* queue_new()
{
	queue *q;
	q=(queue *)malloc(sizeof(queue*));
	q->front=llist_new();
	q->rear=llist_new();
	return q;
}

// add an element to the queue
void enqueue(queue* q, int a)
{
	llist_append(q->front,a);
//	llist_prepend(q->rear,a);
}
// remove the front element from the queue
int dequeue(queue* q)
{
	int a;
	a=llist_get(q->front,0);
	llist_remove_first(q->front);
//	llist_remove_last(q->rear);
	return a;
}

// Check if queue is empty
bool queue_is_empty(queue* q)
{
	if(q->front->head==NULL)
	return 1;
	return 0;
}

// find the size of the queue
int queue_size(queue* q)
{
	return llist_size(q->front);
}

// print queue element
void queue_print(queue* q)
{
	llist_print(q->front);
}
