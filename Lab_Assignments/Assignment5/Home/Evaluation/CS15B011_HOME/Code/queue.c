#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new()
{
	queue* q = (queue*) malloc(sizeof(queue));
	q->front = llist_new();
	q->rear = llist_new();
	return q;
}

void enqueue(queue* q, int data)
{
	Node *n = node_new(data);
	if(q->front->head == NULL)
	{
		q->front->head = n;
		q->rear->head = n;
		return;
	}
	(q->rear->head)->next = n;
	q->rear->head = n;
}

int dequeue(queue* q)
{
	int a = q->front->head->data;
	q->front->head = q->front->head->next;
	return a;
}

bool queue_is_empty(queue* q)
{
	if(q->front->head == NULL)
		return true;
	else 
		return false;
}

int queue_size(queue* q)
{
	LList * lst = q->front;
	llist_size(lst );
}

void queue_print(queue* q)
{
	LList * lst = q->front;
	llist_print(lst );
}