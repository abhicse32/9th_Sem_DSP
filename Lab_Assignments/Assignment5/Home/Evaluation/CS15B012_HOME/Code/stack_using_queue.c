#include "stack_using_queue.h"
#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

/* implemneting stack using queue */
/* Author : CGR */

queue* stack_new()
{
	queue* new;
	new=queue_new();
	
	return new;
}

void stack_push(queue* que, int data)
{
/* generally in queue the newly added one is last leaving one*/
/* so here we implemented stack suck that the front is updated*/
	queue* new;
	new=queue_new();
	if(queue_is_empty(que))
	{
		enqueue(que,data);
	}
	else
	{
		while(!queue_is_empty(que))
		{
			int x;
			x=dequeue(que);
			enqueue(new,x);
		}
		enqueue(que,data);
		while(!queue_is_empty(new))
		{
		int x;
		x=dequeue(new);
		enqueue(que,x);
		}
	}
}

int stack_pop(queue* que)
{
	if(!queue_is_empty(que))
	{
		return dequeue(que);
	}
}
/* these functions are similar to stack*/
bool stack_is_empty(queue* que)
{
	return queue_is_empty(que);
		
}

int stack_size(queue* que)
{
	return queue_size(que);
}

void stack_print(queue* que)
{
	queue_print(que);
}
