/*To implement various operations on a queue such as enqueue, dequeue,finding size and printing
  Author: CS15B046 Jahnvi Patel
  September 8th, 2016
*/
#include "queue.h"
#include <stdio.h>
#include "List.h"
#include <stdlib.h>

// create a new queue
queue* queue_new()
{
	queue* newQueue=(queue*)malloc(sizeof(queue));
	if(newQueue!=NULL)
	{
		newQueue->front=llist_new();
		newQueue->rear=llist_new();
	}
	return newQueue;
}

// add an element to the queue
void enqueue(queue* q, int val)
{	
	llist_append(q->rear,val);
	
	if(q->front->head==NULL)
	{
		q->front->head=q->rear->head;
	}
	else
	q->rear->head=q->rear->head->next;

}

// remove the front element from the queue
int dequeue(queue* q)
{
	if(!queue_is_empty(q))
	{
		Node* temp=q->front->head;
		int num=q->front->head->data;
		q->front->head=q->front->head->next;
		free(temp);
		return num;
	}
}

// Check if queue is empty
bool queue_is_empty(queue* q)
{
	if(q->front->head==NULL)
		return true;
	return false;
}

// find the size of the queue
int queue_size(queue* q)
{
	return(llist_size(q->front));

}

// print queue element
void queue_print(queue* q)
{
	llist_print(q->front);
}
