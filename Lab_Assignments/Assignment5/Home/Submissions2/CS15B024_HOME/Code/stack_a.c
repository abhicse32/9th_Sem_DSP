#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

// create a new stack
stack* stack_new()
{
	stack *s=(stack*)malloc(sizeof(stack));
	s->arr=(int *)malloc(size*sizeof(int));
	s->top=-1;
	return s;
}
// push an element on the stack
void stack_push(stack* s, int n)
{
	if(stack_is_full(s))
	{
		return;
	}
	else
	{
		s->top=s->top+1;
		s->arr[s->top]=n;
	}
}
// pop the top element from the stack
int stack_pop(stack* s)
{
	if(stack_is_empty(s)!=1)
	{
		return s->arr[s->top--] ;
	}
		
}
// Check if stack is empty
bool stack_is_empty(stack* s)
{
	if(s->top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// bool check if stack is full
bool stack_is_full(stack* s)
{
	if(s->top==size-1)
	{
		return true;
	}
	else return false;
}
// find the size of the stack
int stack_size(stack* s)
{
	return s->top+1;
}
// print stack element
void stack_print(stack* s)
{
	int i=0;
	int si=stack_size(s);
	for(i=si-1;i>=0;i--)
	{
		printf("%d ",s->arr[i]);
	}
}

