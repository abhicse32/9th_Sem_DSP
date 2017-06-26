#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000


queue* queue_new()
{
	queue *newq;
	newq = (queue *)malloc(sizeof(queue));
	newq->arr = (int *)malloc(size * sizeof(int)); 
	newq->front = 0;
	newq->rear = size-1;
	return newq;
}


void enqueue(queue *q, int ele)
{
	if(!queue_is_full(q))
	{
		q->rear++;
		if(q->rear == size)
			q->rear = 0;
		q->arr[q->rear] = ele;
	}
}


int dequeue(queue *q)
{
	int x = -1;
	if(!queue_is_empty(q))
	{
		x = q->arr[q->front];
		q->front++;
		if(q->front==size)
			q->front = 0;
	}
	return x;	
}


bool queue_is_full(queue *q)
{
	int count = (q->rear - q->front + size + 1)%size;
	if(count == size)
		return 1;
	else
		return 0;
}


bool queue_is_empty(queue *q)
{
	int count = (q->rear - q->front + size + 1)%size;
	if(count == 0)
		return 1;
	else
		return 0;
}

int queue_size(queue *q)
{
	int count = (q->rear - q->front + size + 1)%size;
	return count;
}


void queue_print(queue *q)
{
	int i = q->front;	
	printf("%d ", q->arr[i] );
	if(i != q->rear)
	{
		do
		{
			if(i == size - 1)
				i = 0;
			else
				i++;
			printf("%d ", q->arr[i]);

			
		}while(i != q->rear);	
	}
}
