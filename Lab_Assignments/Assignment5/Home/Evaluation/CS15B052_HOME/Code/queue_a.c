// Defines functions defined in queue_a.h
// Author : Milind Srivastava
// Date : 16 Sep 2016

#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

// create a new queue
queue* queue_new()
{
	queue* temp = (queue*)malloc(sizeof(queue));
	temp->arr = (int*)malloc(size*sizeof(int));
	temp->rear = -1;
	temp->front = 0;
	return temp;
}

// add an element in the queue
void enqueue(queue* qu, int x)
{
	if(queue_size(qu) == size)
	{
		return;
	}
	qu->rear++;
	qu->rear = (qu->rear)%size;
	qu->arr[qu->rear] = x;
}

// remove the first element from the queue
int dequeue(queue* qu)
{
	int temp = qu->arr[qu->front];
	if(queue_size(qu) == 1)
	{
		qu->front = 0;
		qu->rear = -1;
	}
	else
	{
		qu->front++;
		qu->front = (qu->front)%size;
	}
	return temp;
}

// Check if queue is empty
bool queue_is_empty(queue* qu)
{
	return (queue_size(qu) == 0);
}

// bool check if queue is full
bool queue_is_full(queue* qu)
{
	return (queue_size(qu) == size);
}

// find the size of the queue
int queue_size(queue* qu)
{
	if(qu->rear == -1)
	{
		return 0;
	}
	if(qu->rear - qu->front >= 0)
	{
		return (qu->rear - qu->front + 1);
	}
	return (qu->rear - qu->front + size + 1);
}

// print queue element
void queue_print(queue* qu)
{
	int i;
	if(qu->front <= qu->rear)
	{
		for(i = qu->front; i <= qu->rear; i++)
		{
			printf("%d ", qu->arr[i]);
		}
	}
	else
	{
		for(i = qu->front; i < size; i++)
		{
			printf("%d ", qu->arr[i]);
		}
		for(i = 0; i <= qu->rear; i++)
		{
			printf("%d ", qu->arr[i]);
		}
	}
}