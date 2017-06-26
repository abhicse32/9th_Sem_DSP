#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

stack* stack_new()
	{
		stack *a;
		a=(stack*)malloc(1*sizeof(stack));
		a->arr=(int*)malloc(size*sizeof(int));
		a->top=-1;
		return a;
	}

void stack_push(stack* stk, int x)
	{
			int* a;
			a=stk->arr;
		if(stk->top==-1) { stk->top=0; a[stk->top]=x;}
		else
			{
				stk->top=stk->top+1;
				a[stk->top]=x;
			}
	}

int stack_pop(stack* stk)
	{
		int* a;
		a=stk->arr;		
		stk->top=stk->top-1;
		return a[stk->top+1];
		
	}

bool stack_is_empty(stack* stk)
	{
		if(stk->top==-1) return 1;
		else return 0;
	}

bool stack_is_full(stack* stk)
	{
		if(stk->top==999) return 1;
		else return 0;
	}

int stack_size(stack* stk)
	{
		return stk->top+1;
	}

void stack_print(stack* stk)
	{
		int y;
		int *a;
		a=stk->arr;
		y=stk->top;		
		while(y>=0)
		{
			printf("%d ",a[y]);
			y=y-1;
		}
		//printf("\n");
	}
		



