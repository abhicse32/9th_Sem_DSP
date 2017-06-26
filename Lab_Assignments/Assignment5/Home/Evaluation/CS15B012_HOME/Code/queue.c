#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new()
{
	queue* new;
	new=(queue*)malloc(sizeof(queue));
	/*creating new linked lists to both front and rear*/
	new->front=llist_new();
	new->rear=llist_new();	
	
	return new;
}

void enqueue(queue* que, int data)
{
	Node* cur;
	cur=(Node*)malloc(sizeof(Node));
	cur->data=data;
	if(queue_is_empty(que))
	{
	/* if the queue is empty then both the rear and front points to the same node*/
		que->front->head=cur;
		que->rear->head=cur;
		cur->next=NULL;
	}
	else
	{
		Node* temp;
		/* new node is appended to the list*/
		temp=que->rear->head;
		temp->next=cur;
		que->rear->head=cur;
		cur->next=NULL;
	}	
}

int dequeue(queue* que)
{
	if(!queue_is_empty(que))
	{
		Node* temp;
		temp=que->front->head;
		/* to return the value*/
		int x;
		x=temp->data;
		que->front->head=temp->next;
		return x;
	}
}

bool queue_is_empty(queue* que)
{
	if(que->front->head==NULL)
	{
		return 1;
	}
	else
	return 0;	
}

int queue_size(queue* que)
{
	int count;
	count=0;
	Node* cur;
	cur=que->front->head;
	while(cur!=NULL)
	{
		cur=cur->next;
		count++;
	}	
	return count;
}

void queue_print(queue* que)
{
// create a temp pointer 
	Node* cur;
	cur=que->front->head;
	while(cur!=NULL)
	{
		printf("%d ",cur->data);
		cur=cur->next;
	}
}

