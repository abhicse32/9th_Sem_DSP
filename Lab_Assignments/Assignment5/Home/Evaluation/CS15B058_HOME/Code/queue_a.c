#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

// create a new queue
queue* queue_new()
{
	queue* que=(queue*)malloc(sizeof(queue));
	que->arr=(int*)malloc(size*sizeof(int));
	que->front=0;
	que->rear=-1;
	return que;
}

// add an element in the queue
void enqueue(queue* que, int data)
{
	if(!queue_is_full(que))
	{
		if(que)
		if(que->rear==size-1)
			que->rear=0;
		else	
			que->rear++;
		que->arr[que->rear]=data;
	}
}

// remove the first element from the queue
int dequeue(queue* que)
{
	if(!queue_is_empty(que))
	{
		if(que->rear==que->front)			//if only 1 element, we have to reinitialise front and rear
		{
			int val=que->arr[que->front];
			que->front=0;
			que->rear=-1;
			return val;
		}
		else
		{
			int val=que->arr[que->front];
			if(que->front==size-1)
				que->front=0;
			else
				que->front++;
			return val;
		}
	}
}

// Check if queue is empty
bool queue_is_empty(queue* que)
{
	if(que->front==0&&que->rear==-1)
		return 1;
	else
		return 0;
}

// bool check if queue is full
bool queue_is_full(queue* que)
{
	if(queue_size(que)==size)
		return 1;
	else
		return 0;
}

// find the size of the queue
int queue_size(queue* que)
{
	
	if(!queue_is_empty(que))
	{
		return (que->rear-que->front+1)%size;
	}
	return 0;
}

// print queue element
void queue_print(queue* que)
{
	int i;
	for(i=que->front;i<=que->rear;i++)
		printf("%d ",que->arr[i]);
}