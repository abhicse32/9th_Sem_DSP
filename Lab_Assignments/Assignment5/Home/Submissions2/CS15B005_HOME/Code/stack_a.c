#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

// create a new stack
stack* stack_new()
{
	stack* S = (stack*)malloc(sizeof(stack));
	S->arr = (int*)malloc(1000*sizeof(int));
	S->top = -1;
	return S;
}

// push an element on the stack
void stack_push(stack* S, int data)
{
	(S->top)++;
	(S->arr[S->top]) = data;
	return ;
}

// pop the top element from the stack
int stack_pop(stack* S)
{
	int pop = S->arr[S->top];
	(S->top)--;
	return pop;
}

// Check if stack is empty
bool stack_is_empty(stack* S)
{
	if((S->top) == -1)	return 1;
	return 0;
}

// bool check if stack is full
bool stack_is_full(stack* S)
{
	if((S->top) == 999)	return 1;
	return 0;
}

// find the size of the stack
int stack_size(stack* S)
{
	int height = (S->top) + 1;
	return height;
}

// print stack element
void stack_print(stack* S)
{
	int i;
	for(i = (S->top) ; i>=0 ; i--)
	{
		printf("%d ",(S->arr[i]));
	}
	return ;
}

