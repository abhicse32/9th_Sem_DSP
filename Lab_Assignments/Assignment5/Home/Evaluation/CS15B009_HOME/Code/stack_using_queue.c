/*  Program to implement the stack data structure using the queue data structure

	By : Chandrashekhar D --- Roll no. CS15B009 --- 17 Sept 2016  */

#include "stack_using_queue.h"
#include <stdio.h>

/*  Returns a new queue disguised as a stack */
queue* stack_new()
{
	queue *stk = queue_new();
	return stk;
}

bool stack_is_empty(queue* q)
{
	return queue_is_empty(q);
}

void stack_push(queue* q, int num)
{
	queue *aux = queue_new();		// Auxillary queue for storing current queue
	while(!queue_is_empty(q))
		enqueue(aux,dequeue(q));
	enqueue(q,num);					// Add num to current empty queue
	while(!queue_is_empty(aux))
		enqueue(q,dequeue(aux));	// Enqueue all elements from aux back to original queue
}

int stack_pop(queue* q)
{
	return dequeue(q);
}

int stack_size(queue* q)
{
	return queue_size(q);
}

void stack_print(queue* q)
{
	queue_print(q);
}