#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
// create a new queue
queue* queue_new()
{
	queue *q;
	q=(queue *)malloc(sizeof(queue*));
	q->arr=(int *)malloc(size*sizeof(int));
	q->front=0;
	q->rear=0;
	return q;	
}

// add an element in the queue
void enqueue(queue* q, int a)
{
	q->arr[q->rear]=a;
	q->rear++;
	if(q->rear>size-1)
	q->rear=0;
}

// remove the first element from the queue
int dequeue(queue* q)
{
	int a;
	a=q->arr[q->front];
	q->front++;
	if(q->front>size-1)
	q->front=0;
	return a;
}
// Check if queue is empty
bool queue_is_empty(queue *q)
{
	if(q->front==q->rear)
	return 1;
	return 0;
}

// bool check if queue is full
bool queue_is_full(queue* q)
{
	if(q->front-q->rear==1 || q->front-q->rear==1-size)
	return 1;
	return 0;
}

// find the size of the queue
int queue_size(queue* q)
{
	int a;
	a=q->front-q->rear;
	a=a*-1;
	if(a<0)
	a=a+size;
	return a;
}
// print queue element
void queue_print(queue* q)
{
	int i;
	if(q->rear<q->front)
	{
		q->rear=q->rear+size;
	}
	for(i=q->front;i<q->rear;i++)
	{
		printf("%d ",q->arr[i]);
	}
	printf("\n");
}
