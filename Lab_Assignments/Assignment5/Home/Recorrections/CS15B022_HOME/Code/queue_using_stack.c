#include<stdio.h>
#include "List.h"
#include "queue_using_stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

stack* queue_new()
{
	return stack_new();
}
void enqueue(stack *stack, int a)
{
	stack_push(stack,a);
}
int queue_size(stack *stack)
{
	return stack_size(stack);
}
int dequeue(stack *stack)
{	
	int i = stack_size(stack) - 1;
	int j = llist_get(stack->top,i);
	llist_remove_last(stack->top);
	return j;
}
bool queue_is_empty(stack *stack)
{
	bool i = stack_is_empty(stack);
	return i;
}
void queue_print(stack *stack)
{
	int j;
	int k;
	for(j = llist_size(stack -> top) - 1;j >= 0;j--)
	{
			k = llist_get(stack -> top,j);
			printf("%d ",k);
	}
	//printf("\n");
}
	
