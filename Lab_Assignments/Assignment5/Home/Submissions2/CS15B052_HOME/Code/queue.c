// Defines functions defined in queue.h
// Author : Milind Srivastava
// Date : 16 Sep 2016

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// create a new queue
queue* queue_new()
{
	queue* temp = (queue*)malloc(sizeof(queue));
	temp->front = llist_new();
	temp->rear = llist_new();
	temp->rear->head = temp->front->head;
	return temp;
}

// add an element to the queue
void enqueue(queue* qu, int x) // O(1) enqueue
{
	Node* newNode = node_new(x);
	
	if(queue_is_empty(qu)) // if queue is empty, point front to rear
	{
		qu->rear->head = newNode;
		qu->front->head = qu->rear->head;
	}
	else // else just update rear
	{
		qu->rear->head->next = newNode;
		qu->rear->head = newNode;
	}
}

// remove the front element from the queue
int dequeue(queue* qu)
{
	int temp = llist_get(qu->front, 0);
	llist_remove_first(qu->front);
	if(queue_is_empty(qu)) // updating rear pointer if queue is empty
	{
		qu->rear->head = NULL;
	}
	return temp;
}

// Check if queue is empty
bool queue_is_empty(queue* qu)
{
	return (llist_size(qu->front) == 0);
}

// find the size of the queue
int queue_size(queue* qu)
{
	return llist_size(qu->front);
}

// print queue element
void queue_print(queue* qu)
{
	llist_print(qu->front);
}