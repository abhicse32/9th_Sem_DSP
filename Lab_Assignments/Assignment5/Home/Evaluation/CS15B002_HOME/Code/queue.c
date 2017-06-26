#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
queue* queue_new()
{
	queue* q;
	q= (queue*)malloc(sizeof(queue));
	q->front = (LList*)malloc(sizeof(LList));
	q->rear = (LList*)malloc(sizeof(LList));	
	return q;
}
void enqueue(queue* q, int n)
{
	llist_append(q->front,n);
	Node* a=q->front->head;
	while(a->next != NULL)
	{
		a = a->next;
	}
	q->rear->head = a;
}
int dequeue(queue* q)
{
	Node* a=q->front->head;
	int x =a->data;
	q->front->head = q->front->head->next;
	return x;
}
bool queue_is_empty(queue* q)
{
	if((q->rear->head == NULL) || (q->front->head == NULL))  return true;
	else return false;
}
int queue_size(queue* q)
{
	return llist_size(q->front);
}
void queue_print(queue* q)
{
	llist_print(q->front);
}

