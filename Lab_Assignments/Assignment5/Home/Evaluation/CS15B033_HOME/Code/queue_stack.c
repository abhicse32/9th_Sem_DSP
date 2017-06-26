#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h"

stack* queue_new()
{
	stack *new = malloc(sizeof(stack));
	new->top = malloc( sizeof(LList));
	new->top->head = NULL;
	return new;
}

// add an element to the queue
void enqueue(stack* stk, int elm)
{
	llist_append(stk->top, elm );

}

// remove the front element from the queue
int dequeue(stack* stk)
{
	return llist_remove_first(stk->top);
}

// Check if queue is empty
bool queue_is_empty(stack* stk)
{
	if( llist_size(stk->top) != 0)
		return false;
	return true;
}

// find the size of the queue
int queue_size(stack* stk)
{
	return llist_size(stk->top);
}

// print queue element
void queue_print(stack* stk)
{
	llist_print(stk->top);
}
