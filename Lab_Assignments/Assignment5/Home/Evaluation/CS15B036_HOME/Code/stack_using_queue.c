#include"stack_queue.h"
#include <stdio.h>
#include <stdlib.h>

// create a new stack
queue* stack_new()
{
	queue* Q=queue_new();
	return Q;
}
// push an element on the stack
void stack_push(queue* Q, int x)
{
	enqueue(Q,x);

}

// pop the top element from the stack
int stack_pop(queue* Q)
{
	if(queue_size==0)
	return -1;
	else
	{
	int temp,i=0;
	queue* P=queue_new();
	int n=queue_size(Q)-1;
	while(i<n)
	{
		temp=dequeue(Q);
		enqueue(Q,temp);	
		i++;
	}
	temp=dequeue(Q);
	return temp;
	}
	
}
// Check if stack is empty
bool stack_is_empty(queue* Q)
{
	if(queue_is_empty(Q)==true)
	return true;
	else
	return false;
}
// find the size of the stack
int stack_size(queue* Q)
{
	int val=queue_size(Q);
	return val;
}
// print stack element
void stack_print(queue *Q)
{
	queue_print(Q);

	int n=queue_size(Q);
	int arr[n];
	int i=0;
	while(!queue_is_empty)
	{
		arr[i]=dequeue(Q);
		i++;
	}
	i=0;
	while(i<n)
	{
		enqueue(Q,arr[i]);
		i++;
	}
	i=n-1;
	while(i>=0)
	{
		printf("%d",arr[i]);
		i--;
	}
}
	
