#include "stack_using_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 



// create a new queue
queue* queue_new()
{
	queue *temp;
	temp = (queue*) malloc(sizeof(queue));
	temp->front = llist_new();
	temp->rear = llist_new();

	return temp;
}




//reverses the given queue
void queue_reverse(queue *a)
{
	(a->rear)->head = (a->front)->head;

	Node *prev,*temp1,*temp2;
	prev = NULL;

	temp1=(a->front)->head;

	if(temp1 == NULL)
	{
		return;
	}

	temp2=temp1->next;

	if(temp2 == NULL)
	{
		return;
	}

	while(temp2 != NULL)
	{
		temp1->next = prev;
		prev=temp1;
		temp1=temp2;
		temp2=temp2->next;
	} 

	temp1->next=prev;
	(a->front)->head = temp1;
	return;
}




// add an element to the queue
void enqueue(queue *a, int data)
{	

	if((a->front)->head==NULL)
	{
		//llist_append( a->front, data );
		Node *temp;
		temp = (Node*) malloc(sizeof(Node));
		temp->data = data;
		temp->next = NULL;

		//(a->rear)->head = (a->front)->head;	
		((a->rear)->head)= temp;
		(a->front)->head = temp;

	}
	else
	{
		//llist_append( a->front, data );
		Node *temp;
		temp = (Node*) malloc(sizeof(Node));
		temp->data = data;
		temp->next = NULL;

		//(a->rear)->head = ((a->rear)->head)->next;	
		((a->rear)->head)->next = temp;
		(a->rear)->head = temp;
	}

	
}



// remove the front element from the queue
int dequeue(queue *a)
{	
	queue_reverse(a);

	LList *lst = a->front;
	Node *temp;
	int value;

    temp=lst->head;

    if(temp==NULL)
    {
        return INT_MIN;
    }

    lst->head=temp->next;

    if(lst->head==NULL)
    {
    	(a->rear)->head = NULL;
    	(a->front)->head = NULL;
    	value = temp->data;
    	return value;
    }

    value = temp->data;
    (a->front)->head = temp->next;
    free(temp);

    queue_reverse(a);
    return value;	//Return the element deleted

    
}




// Check if queue is empty
bool queue_is_empty(queue *a)
{
	int ans = llist_size( a->front );

	if(ans > 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}




// find the size of the queue
int queue_size(queue *a)
{
	return llist_size( a->front );
}



// print queue element
void queue_print(queue *a)
{	
	queue_reverse(a);
	llist_print( a->front );
	queue_reverse(a);
}