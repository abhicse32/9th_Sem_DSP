#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


// create a new queue
queue* queue_new()
{
	queue *Q=(queue*)malloc(sizeof(queue));
	Q->front=(LList*)malloc(sizeof(LList));
	Q->rear=(LList*)malloc(sizeof(LList));
	
}

// add an element to the queue
void enqueue(queue *Q, int x)
{
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=x;
	if(queue_is_empty(Q)==true)
	{
	Q->front->head=temp;
	Q->rear->head=temp;
	return ;
	}
	Q->rear->head->next=temp;
	Q->rear->head=temp;
}

// remove the front element from the queue
int dequeue(queue *Q)
{
	if(queue_is_empty(Q)==true)
	{return -1;}
	else if(Q->front->head==Q->rear->head)
	{
	int temp=Q->front->head->data;
	Q->front->head=NULL;
	Q->rear->head=NULL;
	return temp;
	}
	else 
	{
	Node *temp=Q->front->head;
	Q->front->head=Q->front->head->next;
	temp->next=NULL;
	return temp->data;
	}
}

// Check if queue is empty
bool queue_is_empty(queue* Q)
{
	if(Q->front->head==NULL&&Q->rear->head==NULL)
	return true;
	else
	return false;
}

// find the size of the queue
int queue_size(queue* Q)
{
	int count=1;
	if(queue_is_empty(Q) == true)
	return 0;
	Node *p=Q->front->head;
	while(p!=Q->rear->head)
	{
	p=p->next;
	count++;
	}
	return count;
}

// print queue element
void queue_print(queue* Q)
{
	if(queue_is_empty(Q)==true)
	return ;
	Node *p=Q->front->head;
	while(p->next!=NULL)
	{
	printf("%d ",p->data);
	p=p->next;
	}
	printf("%d ",p->data);
}
