#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

// create a new queue
queue* queue_new()
{
	queue* Q = (queue*)malloc(sizeof(queue));
	Q->arr = (int*)malloc(1000*sizeof(int));
	Q->front = 0;
	Q->rear = -1;
	return Q;
}

// add an element in the queue
void enqueue(queue* Q, int data)
{
	Q->rear ++;
	if(Q->rear == 1000)	Q->rear = 0;
	(Q->arr[Q->rear]) = data;
	return ;
}

// remove the first element from the queue
int dequeue(queue* Q)
{
	int temp = Q->arr[Q->front];
	(Q->front)++;
	if(Q->front == 1000)	Q->front = 0;
	return temp;
}

// Check if queue is empty
bool queue_is_empty(queue* Q)
{
	if((Q->front) == (Q->rear))	return 1;
	return 0;
}

// bool check if queue is full
bool queue_is_full(queue* Q)
{
	if(((Q->front) == 0 ) && ((Q->rear) == 999 ))	return 1;
	if((Q->front) == ((Q->rear) + 1))	return 1;
	return 0;
}

// find the size of the queue
int queue_size(queue* Q)
{
	int i, length=0;
	for( i = (Q->front) ; i <= (Q->rear) ; i++)
	{
		length++;
		if((i==999) && (i==(Q->rear)))	return length ;
		if(i==999)	i = -1;
	}
	return length;
}

// print queue element
void queue_print(queue* Q)
{
	int i;
	for( i = (Q->front) ; i <= (Q->rear) ; i++)
	{
		printf("%d ", Q->arr[i]);
		if((i==999) && (i==(Q->rear)))	return ;
		if(i==999)	i=-1;
	}
	return ;
}
