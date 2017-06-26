#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// create a new queue
queue* queue_new()
{
	queue* que=(queue*)malloc(sizeof(queue));
	que->front=llist_new();
	que->rear=llist_new();
	return que;
}

// Check if queue is empty
bool queue_is_empty(queue* que)
{
	if(que->front->head==NULL)
		return 1;
	else 
		return 0;
}

// add an element to the queue
void enqueue(queue* que, Node* data)
{
	list* np=node_new(data);
	if(!queue_is_empty(que))
	{
		que->rear->head->next=np;
		que->rear->head=que->rear->head->next;
	}
	else
	{
		que->front->head=np;
		que->rear->head=np;
	}
}

// remove the front element from the queue
Node* dequeue(queue* que)
{
	if(!queue_is_empty(que))
	{
		list* np=que->front->head;
		Node* val=np->data;
		if(que->front->head==que->rear->head)
		{
			que->front->head=NULL;
			que->rear->head=NULL;
			free(np);
		}
		else
		{
			que->front->head=que->front->head->next;
			free(np);
		}
		return val;
	}
	return NULL;
}



// find the size of the queue
int queue_size(queue* que)
{
	return llist_size(que->front);
	
}

// print queue element
void queue_print(queue* que)
{
	llist_print(que->front);
}