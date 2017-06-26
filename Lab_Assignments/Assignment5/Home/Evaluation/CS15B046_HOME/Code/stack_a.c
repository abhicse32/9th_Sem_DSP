/*To implement various operations on a circular queue (implemented as an array)
  such as enqueue, dequeue,finding size and printing
  Author: CS15B046 Jahnvi Patel
  September 8th, 2016
*/
#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
//create a new stack
stack* stack_new()
{
	stack* newStack=(stack*)malloc(sizeof(stack));
	newStack->arr=(int*)malloc(size*sizeof(int));
	newStack->top=-1;
	return newStack;

}

// push an element on the stack
void stack_push(stack* s, int val)
{
	if(!stack_is_full(s))
	{
		s->top++;
		s->arr[s->top]=val;
	}
}

// pop the top element from the stack
int stack_pop(stack* s)
{
	if(!stack_is_empty(s))
	{
		int num=s->arr[s->top];
		s->top--;
		return num;
	}

}

// Check if stack is empty
bool stack_is_empty(stack* s)
{
	if(s->top==-1)
		return true;
	return false;
}

// bool check if stack is full
bool stack_is_full(stack* s)
{
	if(s->top==size-1)
		return true;
	return false;
}

// find the size of the stack
int stack_size(stack* s)
{
	return(s->top + 1);
}

// print stack element
void stack_print(stack* s)
{
	int i=s->top;
	while(i>=0)
	{
		printf("%d ",s->arr[i] );
		i--;
	}
}
