/*To implement various operations on a circular queue (implemented as an array)
  such as enqueue, dequeue,finding size and printing
  Author: CS15B046 Jahnvi Patel
  September 8th, 2016
*/
#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000


// create a new queue
queue* queue_new()
{
	queue* newQueue=(queue*)malloc(sizeof(queue));
	newQueue->arr=(int*)malloc(size*sizeof(int));
	newQueue->front=-1;
	newQueue->rear=-1;
	return newQueue;
}

// add an element in the queue
void enqueue(queue* q, int val)
{
	if(!queue_is_full(q))
	{
		q->rear++;
		if(q->front==-1)
			q->front++;
		q->arr[q->rear]=val;
	}
}

// remove the first element from the queue
int dequeue(queue* q)
{
	if(!queue_is_empty(q))
	{
		int num=q->arr[q->front];
		if(q->front==q->rear)
		{
			q->front=-1;
			q->rear=-1;
		}
		else
		q->front++;

		return num;
	}

}

// Check if queue is empty
bool queue_is_empty(queue* q)
{
	if(q->front==-1 && q->rear==-1)
		return true;
	return false;
}

// bool check if queue is full
bool queue_is_full(queue* q)
{
	if(q->front == q->rear + 1)
		return true;
	return false;
}

// find the size of the queue
int queue_size(queue* q)
{
	return((q->rear - q->front + 1 + size)%size);
}

// print queue element
void queue_print(queue* q)
{
	int i=q->front;
	if(q->rear<q->front)
	{
		while(i<=size-1)
		{
			printf("%d ",q->arr[i]);
			i++;
		}
		i=0;
		while(i<=q->rear)
		{
			printf("%d ",q->arr[i]);
			i++;
		}
	}
	else
	{
		while(i<=q->rear)
		{
			printf("%d ",q->arr[i]);
			i++;
		}	
	}
}