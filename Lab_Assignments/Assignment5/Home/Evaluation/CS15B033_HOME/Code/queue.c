#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new()
{
	queue *new = malloc(sizeof(queue));
	LList *lst = llist_new();
	new->front = new->rear = lst;
	new->front->head = new->rear->head = lst->head;
	return new;
}

// add an element to the queue
void enqueue(queue* q, int elm)
{
	llist_append(q->front, elm);
	llist_print(q->front);
	Node *temp = q->front->head;
	while( temp != NULL && temp -> next != NULL)
		temp = temp -> next;
	q->rear->head = temp;
}

// remove the front element from the queue
int dequeue(queue* q)
{
	if( q->front->head != NULL)
	{
		Node *temp;
		if( q->front->head == q->rear->head)
		{
			temp = q->front->head;
			q->front->head = q->rear->head = NULL;
		}
		else
		{
			temp = q->front->head;
			q->front->head = q->front->head->next;
		}
		int x = temp->data;
		free(temp);
		return x;
	}
	return -999;
}

// Check if queue is empty
bool queue_is_empty(queue* q)
{
	if( q->front->head == NULL)
		return true;
	return false;
}

// find the size of the queue
int queue_size(queue* q)
{
	int count = 0;
	if( q->front->head != NULL)
	{
		Node *temp = q->front->head;
		while( temp != NULL)
		{
			count++;
			temp = temp->next;
		}
	}
	return count;
}

// print queue element
void queue_print(queue* q)
{
	llist_print(q->front);
}
