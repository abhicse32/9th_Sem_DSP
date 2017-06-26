#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "stack_using_queue.h"
#include "queue.h"

queue* stack_new()										// create a new stack
{
	queue* q;
	q=(queue*)malloc(sizeof(q));
	q->front=llist_new();
	return q;
}

bool stack_is_empty(queue* q)							//Checks if stack is empty
{
	if(q->front->head==NULL) return 1;
	return 0;
}

int stack_size(queue* q)								//Returns the size of the stack
{
	return llist_size(q->front);
}

void stack_print(queue* q)								//Prints the stack
{
    LList* lst=q->front;
    Node* cur;
    cur= lst->head;
    while(cur!=NULL)                                    //Loops till last element
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
}

void ReverseRec(queue* q)								//Reverses the queue recursively
{
	int x;
	if(!queue_is_empty(q))								//When queue becomes empty the last popped out element will be appended recursively
	{
		x=dequeue(q);
		ReverseRec(q);
		enqueue(q,x);
	}
}

queue* stack_push(queue* q, int data)					// push an element to the stack
{
	ReverseRec(q);										//First reverse the queue
	enqueue(q,data);									//Then enqueue(append) the element
	ReverseRec(q);										//Now reverse the queue again
	return q;											//Now the queue will function like a stack
}

int stack_pop(queue* q)									// remove the front element from the stack
{
	if(q->front->head==NULL) 							//It doesn't make any sense to pop an element from an empty stack
	{	
		return INT_MIN;
	}
	int x=dequeue(q);									//Pop is similar to dequeue
	return x;
}
