//STACK USING ARRAY
//AUTHOR -SARTHAK PANDEY
#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

stack* stack_new()            //MAKES A NEW STACK
{
	stack *new;
	new=(stack *)malloc(sizeof(stack));
	new->arr=(int *)malloc(sizeof(int)*size);
	new->top=-1;
	return new;
}

void stack_push(stack* stk, int data)         //ADDS ELEMENT TO LAST OF ARRAY
{
	if(stk->top<size-1)
	{
		stk->top++;
		int i=stk->top;
		stk->arr[i]=data;
	}	
}

int stack_pop(stack* stk)                     //RETURNS ELEMENT FROM LAST OF ARRAY
{
	if(stk->top>=0)
	{
		int i=stk->top;
		stk->top--;
		return stk->arr[i];
	}
}

bool stack_is_empty(stack* stk)              //CHECKS IF STACK EMPTY
{
	if (stk->top==-1)
		return true;
	else if(stk->top>=0)
		return false;
}

bool stack_is_full(stack* stk)
{
	if(stk->top==size-1)
		return true;
	else
		return false;
}

int stack_size(stack* stk)             //RETURNS STACK SIZE
{
	return stk->top+1;
}

void stack_print(stack* stk)           //PRINTS STACK
{
	int i;
	for (i=stk->top;i>=0;i--)
		printf ("%d ",stk->arr[i]);
}
	
	

	
	

