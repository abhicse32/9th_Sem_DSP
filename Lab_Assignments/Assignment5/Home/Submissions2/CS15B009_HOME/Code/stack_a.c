/*  Program to implement the stack data structure using arrays 

	By : Chandrashekhar D --- Roll no. CS15B009 --- 16 Sept 2016  */

#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

/*  Function to create a new stack and return a pointer to the same */
stack* stack_new()
{
	stack* stk;
	stk = (stack*)malloc(sizeof(stack));
	stk->arr = (int *)malloc(size*sizeof(int));
	stk->top = -1;
	return stk;
}

/*	Function to check if a given stack is empty  */
bool stack_is_empty(stack* stk)
{
	return (stk->top == -1);
}

/*  Function to check if a given stack is full up to the maximum capacity  */
bool stack_is_full(stack* stk)
{
	return (stk->top == size-1);
}

/*  Function to push a given integer 'num' into the stack pointed to by stk  */
void stack_push(stack* stk, int num)
{
	if(!stack_is_full(stk))
	{
		stk->top = stk->top + 1;
		stk->arr[stk->top] = num;
	}
}

/*  Function to delete/pop the last inserted element from a stack and return that element  */
int stack_pop(stack* stk)
{
	int x = 0;
	if(!stack_is_empty(stk))
	{
		x = stk->arr[stk->top];
		stk->top = stk->top - 1;
	}
	return x;
}

/*  Function that returns the size of the stack pointed to by stk  */
int stack_size(stack* stk)
{
	return (stk->top + 1);
}

/*  Function to print a stack elements from top to bottom  */
void stack_print(stack* stk)
{
	int x;
	if (!stack_is_empty(stk))
	{
		x = stack_pop(stk);
		printf("%d ",x);
		stack_print(stk);
		stack_push(stk,x);
	}
}