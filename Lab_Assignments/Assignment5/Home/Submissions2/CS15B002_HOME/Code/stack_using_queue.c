#include "stack_using_queue.h"
#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<limits.h>
void push(queue* q,int n)
{
	queue* q1=queue_new();
	enqueue(q,n);
	Node* b=q->front->head;
	while(b!=NULL)
	{
		llist_prepend(q1->front,b->data);
		Node* a=q1->front->head;
		while(a->next != NULL)
		{
			a = a->next;
		}
		q1->rear->head = a;
		b=b->next;
	}
	queue_print(q1);
}
void pop(queue* q)
{
	if(q->front->head ==NULL) printf("%d",INT_MIN);
	else
	{
		queue* q1=queue_new();
		Node* b=q->front->head;
		while(b!=NULL)
		{
			llist_prepend(q1->front,b->data);
			Node* a=q1->front->head;
			while(a->next != NULL)
			{
				a = a->next;
			}
			q1->rear->head = a;
			b=b->next;
		}
		b=q->front->head;
		if(b->next == NULL)
		{
			int x=dequeue(q1);
			printf("%d",x);
			q->front->head = NULL;
			q->rear->head = NULL;
		}
		else
		{	
			while(b->next->next != NULL) { b= b->next;}
			b->next = b->next->next;
			q->rear->head = b;
			int x=dequeue(q1);
			printf("%d",x);
		}
	}
}
void size(queue* q)
{
	printf("%d",queue_size(q));
}
void empty(queue* q)
{
	printf("%d",queue_is_empty(q));
}
