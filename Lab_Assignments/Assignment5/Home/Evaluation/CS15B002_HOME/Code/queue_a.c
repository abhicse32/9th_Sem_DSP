#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
queue* queue_new()
{
	queue* q;
	q= (queue*)malloc(sizeof(queue));
	q->arr = (int*)malloc(sizeof(int)*size);
	q->rear = 0;
	q->front = 0;
	return q;
}
void enqueue(queue* q, int n)
{
	if(!queue_is_full(q))
	{
		if(q->rear < size)
		{
			q->arr[q->rear] = n;
			q->rear = q->rear +1;
		}
		else if((q->rear - q->front) !=size)
		{
			q->rear = 0;
			q->arr[q->rear ] = n;
			q->rear = q->rear +1;
		}
	}
}
int dequeue(queue* q)
{
	if(!queue_is_empty(q))
	{
		int a;
		if(q->front < size)
		{
			a = q->arr[q->front];
			q->front = q->front +1;
		}
		else
		{
			q->front = 0;
			a = q->arr[q->front];
			q->front++;
		}
		return a;
	}
}
bool queue_is_empty(queue* q)
{
	if(q->rear == q->front) return true;
	else return false;
}
bool queue_is_full(queue* q)
{
	if(q->rear > q->front) 
	{
		if((q->rear - q->front) == size) return true;
		else return false;
	}
	else 
	{
		if((q->rear+1) == q->front) return true;			
		else return false;
	}
}
int queue_size(queue* q)
{
	if(q->rear > q->front) return (q->rear - q->front);
	else return (q->rear - q->front + size);
}
void queue_print(queue* q)
{
	int i;
	if(q->rear < q->front)
	{
		for(i=q->front;i<size;i++)
		{
			printf("%d ",q->arr[i]);
		}
		for(i=0;i<q->rear;i++)
		{
			printf("%d ",q->arr[i]);
		}
	}
	else
	{
		for(i = q->front;i<q->rear;i++)
		{
			printf("%d ",q->arr[i]);
		}
	}
}
