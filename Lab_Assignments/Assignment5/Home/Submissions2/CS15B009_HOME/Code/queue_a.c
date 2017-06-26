/*  Program to implement the queue data structure using arrays 

	By : Chandrashekhar D --- Roll no. CS15B009 --- 16 Sept 2016  */

#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

/*  Function to create a new queue and return a pointer to the same */
queue* queue_new()
{
	queue* q;
	q = (queue*)malloc(sizeof(queue));
	q->arr = (int*)malloc(size*sizeof(int));
	q->front = 0;
	q->rear = size - 1;
	return q;
}

/*	Function to check if a given queue is empty  */
bool queue_is_empty(queue* q)
{
	int count = (q->rear - q->front + 1 + size) % size;
	return (count == 0);
}

/*	Function to check if a given queue is full to capacity */
bool queue_is_full(queue* q)
{
	int count = (q->rear - q->front + 1 + size) % size;
	return (count == size);
}

/*  Function to add a given integer 'num' at the tail of the queue pointed to by q  */
void enqueue(queue* q, int num)
{
	if (!queue_is_full(q))
	{
		q->rear = (q->rear + 1) % size;
		q->arr[q->rear]  = num;
	}
	return;
}

/*  Function to delete first element(head) from a queue and return that element  */
int dequeue(queue* q)
{
	if (!queue_is_empty(q))
	{
		int x = q->arr[q->front];
		q->front = (q->front + 1) % size;
		return x;
	}
	return;
}

/*  Function that returns the size of the queue pointed to by q  */
int queue_size(queue* q)
{
	return ((q->rear - q->front + 1 + size) % size);
}

/*  Function to print a queue elements from head to tail  */
void queue_print(queue* q)
{
	int i;
	int count = queue_size(q);
	for (i = 0; i < count; i++)
		printf("%d ",q->arr[(q->front+i)%size]);
}