#include<stdio.h>
#include<stdlib.h>
#include "stack_a.h"
#include<stdbool.h>
#define size 1000
stack* queue_new()
{
 stack *s1=stack_new();
 return s1;
}
bool queue_is_empty(stack *s1)
{
	return stack_is_empty(s1);
}
bool queue_is_full(stack *s1)
{
	return stack_is_full(s1);
}
void enqueue(stack *s1,int n)
{
	stack *s2=stack_new();
	while(stack_is_empty(s1)!=1)
	{
		int x;
		x=stack_pop(s1);
		stack_push(s2,x);
	}
	stack_push(s1,n);
	while(stack_is_empty(s2)!=1)
	{
		int y;
		y=stack_pop(s2);
		stack_push(s1,y);
	}
		
}
int dequeue(stack *s1)
{
	return stack_pop(s1);
}
int queue_size(stack *s1)
{
	return stack_size(s1);
}
void queue_print(stack *s1)
{
	stack_print(s1);
}
