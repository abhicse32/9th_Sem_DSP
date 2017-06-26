#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// create a new queue
queue* queue_new()
{
	queue* Q = (queue*)malloc(sizeof(queue));
	Q->front = llist_new();
	Q->rear = llist_new();
	Q->rear->head = Q->front->head;
	return Q;
}

// add an element to the queue
void enqueue(queue* Q, int data)
{
	llist_append( Q->front, data);
	Q->rear->head = Q->front->head;
	while( Q->rear->head->next != NULL)
	{
		Q->rear->head = Q->rear->head->next;
	}
	return ;
}

// remove the front element from the queue
int dequeue(queue* Q)
{
	int temp = Q->front->head->data;
	llist_remove_first(Q->front);
	return temp;
}

// Check if queue is empty
bool queue_is_empty(queue* Q)
{
	if(Q->front->head == NULL)	return 1;
	return 0;
}

// find the size of the queue
int queue_size(queue* Q)
{
	int size;
	size = llist_size( Q->front );
	return size;
}

// print queue element
void queue_print(queue* Q)
{
	llist_print( Q->front );
	return;
}

