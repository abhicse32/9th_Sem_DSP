#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
// create a new stack
stack* stack_new()
{
	stack *s;
	s=(stack*)malloc(sizeof(stack*));
	s->arr=(int *)malloc(1000*sizeof(int));
	s->top=-1;
	return s;
}

// push an element on the stack
void stack_push(stack* s, int a)
{
	s->top++;
	s->arr[s->top]=a;
}
// pop the top element from the stack
int stack_pop(stack* s)
{
	int a;
	a=s->arr[s->top];
	s->top--;
	return a;
}
// Check if stack is empty
bool stack_is_empty(stack* s)
{
	if(s->top==-1)
	return 1;
	return 0;
}
// bool check if stack is full
bool stack_is_full(stack* s)
{
	if(s->top==size-1)
	return 1;
	return 0;
}

// find the size of the stack
int stack_size(stack* s)
{
	return s->top+1;
	
}

// print stack element
void stack_print(stack* s)
{
	int i;
	for(i=0;i<=s->top;i++)
	{
		printf("%d ",s->arr[s->top-i]);
	}
	printf("\n");
}
