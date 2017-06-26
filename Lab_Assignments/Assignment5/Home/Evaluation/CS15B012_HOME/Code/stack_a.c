#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

stack* stack_new()
{
	stack* new;
	/* Given that the size of the array is constant*/
	new=(stack*)malloc(sizeof(stack));
	new->arr=(int*)malloc(1000*sizeof(int));
	new->top=-1;
	
	return new; 
}

void stack_push(stack* stk, int data)
{	

	if(!stack_is_full(stk))
	{
		stk->arr[stk->top+1]=data;
		stk->top++;
	}

}

int stack_pop(stack* stk)
{
	if(!stack_is_empty(stk))
	{	int x;
		x=stk->arr[stk->top];
		stk->top--;
		return x;
	}
}

bool stack_is_empty(stack* stk)
{
	if(stk->top==-1)
	return 1;
	else
	return 0;
}

bool stack_is_full(stack* stk)
{
	if(stk->top==999)
	return 1;
	else
	return 0;
}

int stack_size(stack* stk)
{
	int i;
	i=stk->top+1;
	return i;	
}

void stack_print(stack* stk)
{
	int x=stk->top;
	int i;
	for(i=x;i>=0;i--)
	{
		printf("%d ",stk->arr[i]);		
	}	
}	
