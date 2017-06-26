#include "stack_using_queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

// create a new stack
queue* stack_new()
{
	queue* st = (queue*) malloc(sizeof(queue));
	st -> front = llist_new();
	st -> rear  = llist_new();
	return st;
}

// Check if stack is empty
bool stack_is_empty(queue* st)
{
	if(st -> rear -> head)	return 0;
	else			return 1;
}

// push an element on the stack
void stack_push(queue* st, int num)
{
	if (queue_is_empty(st))
    	{
		llist_prepend(st -> front, num);
		llist_prepend(st -> rear, num);
	}

    	else
    	{
		llist_prepend(st -> rear, num);
	}  
}

// find the size of the stack
int stack_size(queue* st)
{
	return llist_size(st -> rear);
}

// pop the top element from the stack
int stack_pop(queue* st)
{

	int l = stack_size(st);
	if(stack_is_empty(st));
	else if(l == 1)	printf("\n");
	else
	{
		int pop = llist_get(st -> rear, 0);
		llist_remove_first(st -> rear);
		return pop;
	}
}

// print stack element
void stack_print(queue* st)
{
	llist_print(st -> rear);
}
