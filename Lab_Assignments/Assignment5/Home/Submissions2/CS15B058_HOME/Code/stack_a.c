#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define size 1000

// create a new stack
stack* stack_new()
{
	stack* stck=(stack*)malloc(sizeof(stack));
	stck->arr=(int*)malloc(size*sizeof(int));
	stck->top=-1;
	return stck;
}

// push an element on the stack
void stack_push(stack* stck, int data)
{
	if(!stack_is_full(stck))
		stck->arr[++stck->top]=data;
}

// pop the top element from the stack
int stack_pop(stack* stck)
{
	if(!stack_is_empty(stck))
	{
		int x=stck->arr[stck->top];
		stck->top--;
		return x;
	}
	return INT_MIN;
}

// Check if stack is empty
bool stack_is_empty(stack* stck)
{
	if(stck->top==-1)
		return 1;
	else 
		return 0;
}

// bool check if stack is full
bool stack_is_full(stack* stck)
{
	if(stck->top==size-1)
		return 1;
	else
		return 0;
}

// find the size of the stack
int stack_size(stack* stck)
{
	return stck->top+1;
}

// print stack element
void stack_print(stack* stck)
{
	int i;
	for(i=stck->top;i>=0;i--)
		printf("%d ",stck->arr[i]);
}