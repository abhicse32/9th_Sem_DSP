#include<stdio.h>
#include<stdlib.h>
#include"List.h"
#include"stack_using_queue.h"
#include<stdbool.h>
queue* stack_new()
{
	queue *queue = malloc(sizeof(queue));
	queue->front = (LList*)malloc(sizeof(LList));
	queue->rear = (LList*)malloc(sizeof(LList));
	(queue->front)->head = NULL;
	(queue->rear)->head = NULL;
	return queue;
}
void stack_push(queue *queue, int a)
{
	llist_append(queue->front,a);
	llist_prepend(queue->rear,a);
}
int stack_pop(queue *queue)
{
	int a = llist_get(queue->rear,0);
	llist_remove_last(queue->front);
	llist_remove_first(queue->rear);
	return a;
}
bool stack_is_empty(queue *queue)
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
int stack_size(queue *queue)
{
	return llist_size(queue->front);
}
void stack_print(queue *queue)
{
	llist_print(queue->rear);
}
