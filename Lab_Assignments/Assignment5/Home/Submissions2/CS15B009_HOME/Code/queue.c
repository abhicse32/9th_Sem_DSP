/*  Program to implement the queue data structure using linked lists 

	By : Chandrashekhar D --- Roll no. CS15B009 --- 16 Sept 2016  */

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

/*  Function to create a new queue and return a pointer to the same */
queue* queue_new()
{
	queue* q;
	q = (queue*)malloc(sizeof(queue));
	q->front = llist_new();
	q->rear = llist_new();
	return q; 
}

/*	Function to check if a given queue is empty  */
bool queue_is_empty(queue* q)
{
	return (q->front->head == NULL);
}

/*  Function to add a given integer 'num' at the tail of the queue pointed to by q  */
void enqueue(queue* q, int num)
{
	if (queue_is_empty(q))
	{
		q->rear = llist_new();
		llist_append(q->rear,num);
		q->front->head = q->rear->head;
	}

	else
	{
		llist_append(q->rear,num);
		q->rear->head = q->rear->head->next;
	}
}

/*  Function to delete first element(head) from a queue and return that element  */
int dequeue(queue* q)
{
	if (!queue_is_empty(q))
	{
		int x = q->front->head->data;
		llist_remove_first(q->front);
		return x;
	}
}

/*  Function that returns the size of the queue pointed to by q  */
int queue_size(queue* q)
{
	return llist_size(q->front);
}

/*  Function to print a queue elements from head to tail  */
void queue_print(queue* q)
{
	llist_print(q->front);
}