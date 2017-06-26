#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

queue* queue_new()
{
	queue *new = malloc( sizeof( queue*));
	new->front = new->rear = -1;
	new->arr = malloc( size*sizeof(int));
	return new;
}

// add an element in the queue
void enqueue(queue* q, int elm)
{
	if( !queue_is_full(q))
	{
		if( q->front == -1)
			q->front = q->rear = 0;
		else if (q->rear == size-1)
			q->rear = 0;
		else
			q->rear++;
		q->arr[q->rear] = elm;
	}
}

// remove the first element from the queue
int dequeue(queue* q)
{
	if( q->front != -1)
	{
		int x;
		x = q->arr[q->front];
		if( q->front == q->rear)
		{
			q->front = q->rear = -1;
		}
		else if( q->front == size-1)
			q->front = 0;
		else
			q->front++;
		return x;
	}
	return -1;
}

// Check if queue is empty
bool queue_is_empty(queue* q)
{
	if( q->front == -1)
		return true;
	return false;
}

// bool check if queue is full
bool queue_is_full(queue* q)
{
	if( q->front == q->rear + 1 || q->rear == size-1 && q->front == 0)
		return true;
	return false;
}

// find the size of the queue
int queue_size(queue* q)
{
	if( q->front == -1)
		return 0;
	return ( size + q->rear - q->front +1)%size;
}

// print queue element
void queue_print(queue* q)
{
	int l = queue_size(q);
	int i=q->front;
	while( i< q->front + queue_size(q))
	{
		printf("%d ", q->arr[i]);
		i++;
	}
}