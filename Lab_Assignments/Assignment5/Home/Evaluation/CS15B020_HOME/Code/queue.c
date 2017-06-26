#include "List.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new()
	{
		queue* a;
		a=(queue*)malloc(1*sizeof(queue));
		a->front=llist_new();
		a->rear=llist_new();
		return a;
		
	}

void enqueue(queue* que, int n)
	{
		llist_append(que->front,n);
		Node* a;
		a=(que->front)->head;
		while(a->next!=NULL)
		{
			a=a->next;
		}
		(que->rear)->head=a;		
	}

int dequeue(queue* que)
	{
		int x;
		Node* a;
		a=(que->front)->head;
		x=a->data;
		llist_remove_first(que->front);
		a=(que->front)->head;
		if(a==NULL) (que->rear)->head=NULL;
		return x;
		
	}

bool queue_is_empty(queue* que)
	{
		if((que->rear)->head==NULL) return 1;
		else return 0;
	}
		
int queue_size(queue* que)
	{
		return llist_size(que->front);
	}

void queue_print(queue* que)
	{
		llist_print(que->front);
	}
