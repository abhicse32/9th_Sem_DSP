/*
Stack implementation using array

Ameet S Deshpande
CS15B001
*/

#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define size 1000


// create a new stack
stack* stack_new()
{
	stack *temp;
	temp = (stack*) malloc(sizeof(stack));
	(temp->arr) = (int*) malloc(sizeof(int)*size);
	temp->top = -1;
	return temp;
}



// push an element on the stack
void stack_push(stack *a, int data)
{
	if(a->top < size)
	{
		(a->top) = (a->top)+1;
		(a->arr)[a->top] = data;	
	}
	
}



// pop the top element from the stack
int stack_pop(stack *a)
{
	if(a-> top == -1)
	{
		return INT_MIN;
	}

	else
	{
		int value = (a->arr)[a->top];
		a->top = a->top-1;
		return value;		
	}
}



// Check if stack is empty
bool stack_is_empty(stack *a)
{
	if(a->top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



// bool check if stack is full
bool stack_is_full(stack *a)
{
	if(a->top == size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}




// find the size of the stack
int stack_size(stack *a)
{
	return a->top+1;
}




// print stack element
void stack_print(stack *a)
{
	for(int i = a->top;i >= 0;--i)
	{
		printf("%d ",(a->arr)[i]);
	}
}

