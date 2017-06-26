#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
stack* stack_new()									// create a new stack
{
	stack* stk;
	stk=(stack*)malloc(sizeof(stack));
	stk->arr=(int*)malloc(sizeof(int));
	stk->top=-1;									//stack->top is the index of the last pushed element in to the stack
	return stk;
}

void stack_push(stack* stk, int data)				//add an element in to the stack
{
	stk->top=stk->top + 1;							//stack->top is the index of the last pushed element in to the stack
	stk->arr[stk->top]=data;						//store the element in arr
}

int stack_pop(stack* stk)							// pop the top element from the stack
{
	int element=stk->arr[stk->top];
	stk->top=stk->top - 1;							//Decrement stk->top
	return element;
}

bool stack_is_empty(stack* stk)						// Check if stack is empty
{
	if(stk->top==-1) return 1;
	return 0;
}

bool stack_is_full(stack* stk)						// Check if stack is full
{
	if(stk->top==size-1) return 1;
	return 0;
}

int stack_size(stack* stk)							//Returns the size of the stack
{
	return (stk->top + 1);
}

void stack_print(stack* stk)						//Prints the stack
{
	int i;
	for(i=stk->top;i>=0;i--) 
	        printf("%d ",stk->arr[i]);
}
