#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define size 1000
// create a new stack
stack* stack_new()
{
	stack* a;
	a= (stack*)malloc(sizeof(stack));
	a->top = -1;
	a->arr = (int*)malloc(sizeof(int)*size);
	return a;
}
void stack_push(stack* a, int n)
{
	int i=a->top+1;
	a->arr[i] = n;
	a->top = a->top+1;
}
int stack_pop(stack* a)
{
	if(stack_is_empty(a)) return INT_MIN;
	int i=a->top;
	int x=a->arr[i];
	a->top = a->top-1;
	return x;
}
bool stack_is_empty(stack* a)
{
	if(a->top==-1) return true;
	else return false;
}
bool stack_is_full(stack* a)
{
	if(a->top == size) return true;
	else return false;
}
int stack_size(stack* a)
{
	return a->top+1;
}
void stack_print(stack* a)
{
	int i;
	for(i=a->top;i>=0;i--)
	{
		printf("%d ",a->arr[i]);
	}
}
