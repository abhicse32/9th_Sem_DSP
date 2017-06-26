#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


queue* queue_new()
{
	queue *newqueue;
	newqueue = (queue *)malloc(sizeof(queue));
	newqueue->front = (LList *)malloc(sizeof(LList));
	newqueue->front->head = NULL;
	newqueue->rear = (LList *)malloc(sizeof(LList));
	newqueue->rear->head = NULL;
	return newqueue;
}


void enqueue(queue *q, int ele)
{
	Node *newnode;
	newnode=(Node*)malloc(sizeof(Node));	
	newnode->data = ele;
	newnode->next = NULL;
	if(queue_is_empty(q))
		q->front->head = newnode;
	else
	{
		Node *current;
		current=(Node *)malloc(sizeof(Node));		
		current->next = q->front->head;

		while(current != q->rear->head)
		{
			current = current->next;
		}
		current->next = newnode;
	}
	q->rear->head = newnode;
}


int dequeue(queue *q)
{
	int x = llist_get(q->front, 0);
	llist_remove_first(q->front);
	return x;
}


bool queue_is_empty(queue *q)
{
	if(q->front->head == NULL)
		return 1;
	else
		return 0;	
}


int queue_size(queue *q)
{
	return llist_size(q->front);
}


void queue_print(queue *q)
{
	llist_print(q->front);
}


