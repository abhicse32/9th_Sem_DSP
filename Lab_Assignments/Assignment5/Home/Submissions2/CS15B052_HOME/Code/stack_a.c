// Defines functions defined in stack_a.h
// Author : Milind Srivastava
// Date : 16 Sep 2016

#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define size 1000

// create a new stack
stack* stack_new()
{
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->arr = (int*)malloc(size*sizeof(int));
	temp->top = -1;
	return temp;
}

// push an element on the stack
void stack_push(stack* st, int x)
{
	if(st->top == (size - 1))
	{
		return;
	}
	st->top++;
	st->arr[st->top] = x;
}

// pop the top element from the stack
int stack_pop(stack* st)
{
	if(st->top == -1)
	{
		return INT_MIN;
	}
	int temp = st->arr[st->top];
	st->top--;
	return temp;
}

// Check if stack is empty
bool stack_is_empty(stack* st)
{
	return (st->top == -1);
}

// bool check if stack is full
bool stack_is_full(stack* st)
{
	return (st->top == (size - 1));
}

// find the size of the stack
int stack_size(stack* st)
{
	return (st->top + 1);
}

// print stack element
void stack_print(stack* st)
{
	int i;
	for(i = st->top; i >= 0; i--)
	{
		printf("%d ", st->arr[i]);
	}
}