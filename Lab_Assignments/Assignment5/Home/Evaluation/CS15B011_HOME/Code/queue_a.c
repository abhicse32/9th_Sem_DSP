#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

queue* queue_new()
{
	queue* q = (queue*) malloc(sizeof(queue));
	q->arr = (int*) malloc(sizeof(int)*size);
	q->rear = -1;
	q->front = 0;
	return q;
}

void enqueue(queue* q, int data)
{
	q->rear ++;
	(q->arr)[q->rear] = data;
}

int dequeue(queue* q)
{
	int a = (q->arr)[q->front];
	q->front ++;
	return a;
}

bool queue_is_empty(queue* q)
{
	if(q->front == q->rear)
		return true;
	else
		return false;
}

bool queue_is_full(queue* q)
{
	if(q->rear == size-1)
		return true;
	else
		return false;
}

int queue_size(queue* q)
{
	return q->rear - q->front + 1;
}

void queue_print(queue* q)
{
	int i;
	for(i = q->front; i <= q->rear; i++)
		printf("%d ",(q->arr)[i] );
}