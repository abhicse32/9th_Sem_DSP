#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

stack* stack_new()
{
	stack *stkarr = malloc(sizeof(stack*));
	stkarr->arr = malloc( size*sizeof(int));
	stkarr->top = -1;
	return stkarr;
}

// push an element on the stack
void stack_push(stack* stk, int elm)
{
	if( stk->top != size-1 )
	{
		stk->top++;
		stk->arr[stk->top] = elm;
	}
}

// pop the top element from the stack
int stack_pop(stack* stk)
{
	int temp = stk->arr[stk->top];
	stk->top--;
	return temp;
}

// Check if stack is empty
bool stack_is_empty(stack* stk)
{
	if( stk->top == -1)
		return true;
	return false;
}

// bool check if stack is full
bool stack_is_full(stack* stk)
{
	if( stk->top == size-1)
		return true;
	return false;
}

// find the size of the stack
int stack_size(stack* stk)
{
	return stk->top+1;
}

// print stack element
void stack_print(stack* stk)
{
	int i=stk->top;
	while( i>=0)
	{
		printf("%d ", stk->arr[i]);
		i--;
	}
}
