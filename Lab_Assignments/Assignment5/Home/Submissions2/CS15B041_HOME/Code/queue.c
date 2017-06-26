#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new()
{	queue* q;
	q=(queue*)malloc(sizeof(queue));
	q->front=(LList*)malloc(sizeof(LList));
	q->rear=(LList*)malloc(sizeof(LList));

	return q;
}
	
void enqueue(queue* q, int n )
{
	Node* a;
	a=(Node*)malloc(sizeof(Node));
	a->data=n;
	
	if(q->rear->head=NULL && q->front->head=NULL)
	{	
	
	q->front->head=a;
	q->rear->head=a;
	
	
	return;
	}
	q->rear->head->next=a;
	q->rear->head=q->rear->head->next;
	
	
	
	
}


bool queue_is_empty(queue* q)
{
	if( queue_size(q)==0)
	return 1;
	else
	return 0;
}

int dequeue(queue* q)
{
	
	Node* temp;
	temp=q->front->head;
	if(queue_is_empty(q))
	{
	return -1;
	}
	else if(q->front->head==q->rear->head)
	{
	
	q->front->head=NULL;
	q->rear->head=NULL;
	return temp;
	}	
	else
	{
	temp->data=q->front->head->data;
	q->front->head=q->front->head->next;
	free(temp);
	return x;
	}
	 
	
	
}

int queue_size(queue* q)
{ 
	int c=0;
	Node* a;
	a=q->front->head;
	if(q->front->head ==NULL && q->rear->head ==NULL)
		return 0;
	else
	{
		while(a->next!=q->rear->head)
		{
			a=a->next;
			c++;
		}
	}
	return c;
	
}

void queue_print(queue* q)
{	
	Node* a;
	a=q->front->head;
	if(q->front->head!=NULL && q->rear->head!=NULL)
	{
		return ;
	}

		while(a->next!=NULL)
		{
			printf("%d",a->data);
			a=a->next;
		}
	}
}
