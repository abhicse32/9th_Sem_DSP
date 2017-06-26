#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
queue* queue_new()
{
	queue *queue = malloc(sizeof(queue));
	queue->front = (LList*)malloc(sizeof(LList));
	queue->rear = (LList*)malloc(sizeof(LList));
	(queue->front)->head = NULL;
	(queue->rear)->head = NULL;
	return queue;
}
void enqueue(queue *queue, int a)
{
	llist_append(queue->front,a);
	llist_prepend(queue->rear,a);
}
int dequeue(queue *queue)
{
	int a = llist_get(queue->front,0);
	llist_remove_first(queue->front);
	llist_remove_last(queue->rear);
	return a;
}
bool queue_is_empty(queue *queue)
{
	bool i;
	if(((queue->front)->head) == NULL && ((queue->rear)->head) == NULL)
	{
		i = true;
	}
	else
	{
		i =false;
	}
	return i;
}
int queue_size(queue *queue)
{
	return llist_size(queue->front);
}
void queue_print(queue *queue)
{
	llist_print(queue->front);
}

