#include "stack_using_queue.h"
#include "List.h"
#include"queue.h"
#include <stdio.h>
#include <stdlib.h>
// create a new stack
queue* stack_new()
{
	queue *q;
	q=queue_new();
	return q;
}

// push an element on the stack
void stack_push(queue* q, int a)
{
	
	queue *temp;
	temp=queue_new();
	int b;
	while(!queue_is_empty(q))
	{
		b=dequeue(q);
		enqueue(temp,b);
	}
	enqueue(q,a);
	while(!queue_is_empty(temp))
	{
		b=dequeue(temp);
		enqueue(q,b);
	}
	free(temp);
}

// pop the top element from the stack
int stack_pop(queue* q)
{
	return dequeue(q);
}

// Check if stack is empty
bool stack_is_empty(queue* q)
{
	return queue_is_empty(q);
}

// find the size of the stack
int stack_size(queue* q)
{
	return queue_size(q);
}

// print stack element
void stack_print(queue* q)
{
	queue_print(q);
}
