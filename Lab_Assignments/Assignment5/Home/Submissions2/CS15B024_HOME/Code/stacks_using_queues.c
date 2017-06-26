#include<stdio.h>
#include<stdlib.h>
#include "queue_a.h"
#include <stdbool.h>
#define size 1000
queue* stack_new()
{
	queue *q1=queue_new();
	return q1;
}
bool stack_is_empty(queue *q1)
{
	return queue_is_empty(q1);
}
bool stack_is_full(queue *q1)
{
	return queue_is_full(q1);
}
int stack_pop(queue *q1)
{
	return dequeue(q1);	
}
void stack_push(queue *q1,int n)
{
	queue *q2=queue_new();
	while(queue_is_empty(q1)!=1)
	{
		int x;
		x=dequeue(q1);
		enqueue(q2,x);
	}
	enqueue(q1,n);
	while(queue_is_empty(q2)!=1)
	{
		int y;
		y=dequeue(q2);
		enqueue(q1,y);
	}	
}
int stack_size(queue *q1)
{
	return queue_size(q1);
}
void stack_print(queue *q1)
{
	queue_print(q1);
}

