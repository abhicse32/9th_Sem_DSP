#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000


// create a new stack
stack* stack_new()
{
	stack *temp=(stack*)malloc(sizeof(stack));
	temp->arr=(int*)malloc(100*sizeof(int));
	temp->top=-1;
}

// push an element on the stack
void stack_push(stack *S, int x)
{
	if(stack_is_full(S)==true)
	{
	return ;
	}
	if(stack_is_empty(S)==true)
	{
	S->top=0;
	S->arr[S->top]=x;
	return ;
	}
	S->arr[S->top+1]=x;
	S->top=S->top+1;
}

// pop the top element from the stack
int stack_pop(stack *S)
{
	if(stack_size(S)==0)
	return ;
	else 
	{
	int x=S->arr[S->top];
	S->top=S->top-1;
	return x;
	}
}

// Check if stack is empty
bool stack_is_empty(stack *S)
{
	if(S->top>=0)
	return false;
	else
	return true;
}

// bool check if stack is full
bool stack_is_full(stack *S)
{
	if(S->top>=size-1)
	return true;
	else
	return false;
}
	

// find the size of the stack
int stack_size(stack *S)
{
	if(S->top>=0)
	return S->top+1;
	else
	return -1;
}

// print stack element
void stack_print(stack *Stk)
{
	if(stack_is_empty(Stk)==true)
	return;
	int i=Stk->top;
	while(i>=0)
	{
	printf("%d ",Stk->arr[i]);
	i--;
	}
	
}
