#include "List.h"
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

Node* recR(Node* head)
{
	Node* temp;
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	else
	{
		temp = recR(head->next);
		(head->next)->next = head;
		head->next = NULL;
	}	
	
	return temp;
}


void rev(queue* q)
{
	if(queue_is_empty(q)==false)
	{
		(q->front)->head = recR( (q->front)->head );
	}
	
}

void stack_push(queue* q, int data)
{
	if(queue_is_empty(q)==true)
	{
		llist_append(q->front,data);
		(q->rear)->head = (q->front)->head;
	}
	else
	{
		rev(q);
		enqueue(q,data);
		rev(q);
		(q->rear)->head = ( (q->rear)->head)->next;
	}

}


int stack_pop(queue* q)
{
	return dequeue(q);		
}

int stack_size(queue* q)
{
	return queue_size(q);
}

void stack_print(queue* q)
{
	queue_print(q);
}

bool stack_is_empty(queue* q)
{
	return queue_is_empty(q);
}
