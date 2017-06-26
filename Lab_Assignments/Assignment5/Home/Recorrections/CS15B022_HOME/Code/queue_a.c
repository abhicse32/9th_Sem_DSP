#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
queue* queue_new()
{
	queue *queue = malloc(sizeof(queue));
	queue->arr = (int*)malloc(size*sizeof(int));
	queue->front = -1;
	queue->rear = -1;
	return queue;
}
bool queue_is_empty(queue *queue)
{
	bool i;
	if(queue->front == -1 && queue->rear == -1)
	{
		i = true;
	}
	else
	{
		i = false;
	}
	return i;
}
int queue_size(queue *queue)
{
	if(queue_is_empty(queue) == true)
	{
		return 0;
	}
	if(queue->rear >= queue->front)
	{
		return (queue->rear - queue->front)+1;
	}
	if(queue->rear < queue->front)
	{
		int x = (queue->front - queue->rear)-1;
		return size-x;
	}
}
bool queue_is_full(queue *queue)
{
	bool i;
	if(queue_size(queue) == size - 1)
	{
		i = true;
	}
	else
	{
		i = false;
	}
	return i;
}
void enqueue(queue *queue, int a)
{
	if(queue_is_empty(queue) == true)
	{
		queue->front = 0;
		queue->rear = 0;
		(queue->arr)[queue->rear] = a;
		return;
	}
	if(queue_is_full(queue) == true)
	{
		return;
	}
	queue->rear = (queue->rear + 1)%size;
	(queue->arr)[queue->rear] = a;
}
int dequeue(queue *queue)
{
	if(queue_is_empty(queue) == true)
	{
		return -1;
	}
	if(queue->front == 0 && queue->rear == 0)
	{
		int i = (queue->arr)[queue->front];
		queue->front = -1;
		queue->rear = -1;
		return -1;
	}
	int i = (queue->arr)[queue->front];
	queue->front = (queue->front + 1)%size;
	return i;
}
void queue_print(queue *queue)
{
	
	if(queue_is_empty(queue) == true)
	{
		return;
	}
	int front = queue->front;
	int rear = queue->rear;
	do{
		printf("%d ",(queue->arr)[front]);
		front = (front + 1)%size;
	}while(front != queue->rear + 1);
	
}

