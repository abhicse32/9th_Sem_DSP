#include "stack_using_queue.h"
#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

queue* stack_new()
{
	queue* q = queue_new();
	
	return q;
}

void stack_push(queue* q, int data)
{
	int x;
	queue* temp = queue_new();
	enqueue(temp, data);
	while(!queue_is_empty(q))
	{
		x = dequeue(q);
		enqueue(temp,x);
	}
	while(!queue_is_empty(temp))
	{
		x = dequeue(temp);
		enqueue(q,x);
	}
}

int stack_pop(queue* q)
{
	return dequeue(q);
}

bool stack_is_empty(queue* q)
{	
	return queue_is_empty(q);	
}

int stack_size(queue* q)
{
	return queue_size(q);
}

void stack_print(queue* q)
{
	queue_print(q);
}