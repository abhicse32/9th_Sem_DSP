#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

stack* stack_new()
	{
		stack *a;
		a=(stack*)malloc(1*(sizeof(stack)));
		a->top=llist_new();
		return a;
	}

void stack_push(stack* stk, int x)
	{
		LList* a;
		a=stk->top;
		llist_prepend(a,x);
		stk->top=a;
	}
	
int stack_pop(stack* stk)
	{
		int x;		
		LList* a;
		a=stk->top;
		x=llist_get(a,0);
		llist_remove_first(a);
		return x;
	}

bool stack_is_empty(stack* stk)
	{
		LList*a;
		a=stk->top;
		if(a->head==NULL) return 1;
		else return 0;
	}
	
int stack_size(stack* stk)
	{
		LList*a;
		a=stk->top;
		return llist_size(a);
	}

void stack_print(stack* stk)
	{
		LList*a;
		a=stk->top;
		llist_print(a);
	}
		
	

