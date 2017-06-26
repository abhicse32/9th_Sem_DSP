#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

// create a new stack
stack* stack_new()
{
	stack* stk = (stack*) malloc (sizeof(stack));
	stk->arr = (int*) malloc (size * sizeof(int));
	stk->top = -1;
	return stk;
}

// push an element on the stack
void stack_push(stack* stk, int data)
{
	int i = stk -> top;
	if(i >= size-1)				// 999 + 1 overflow
		return;

	stk -> arr[i+1] = data;
	stk -> top += 1;
}

// pop the top element from the stack
int stack_pop(stack* stk)
{
	int i = stk -> top;
	int val = stk -> arr[i];
	stk -> top -= 1;

	return val;
}

// Check if stack is empty
bool stack_is_empty(stack* stk)
{
	if( stk -> top == -1)
		return true;
	else
		return false;
}


// bool check if stack is full
bool stack_is_full(stack* stk)
{
	if( stk -> top == size - 1)
		return true;
	else
		return false;
}

// find the size of the stack
int stack_size(stack* stk)
{
	return ( stk -> top + 1);
}

// print stack element
void stack_print(stack* stk)
{
	int i;
	for(i = stk -> top; i >= 0 ; i--)
		printf("%d ",stk -> arr[i]);
}



