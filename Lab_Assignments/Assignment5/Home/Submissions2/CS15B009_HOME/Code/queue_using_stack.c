/*  Program to implement the queue data structure using the stack data structure

	By : Chandrashekhar D --- Roll no. CS15B009 --- 17 Sept 2016  */

#include "queue_using_stack.h"
#include <stdio.h>

/*  Returns a new stack disguised as a queue */
stack* queue_new()
{
	stack* q = stack_new();
	return q; 
}

bool queue_is_empty(stack* stk)
{
	return stack_is_empty(stk);
}

void enqueue(stack* stk, int num)
{
	stack *aux = stack_new();			// Auxillary stack to store all elements of current stack
	while (!stack_is_empty(stk))		
		stack_push(aux,stack_pop(stk));
	stack_push(stk,num);				// Pushes num into current empty stack
	while (!stack_is_empty(aux))
		stack_push(stk,stack_pop(aux));	// Pushes back all elements from aux into original stack
}

int dequeue(stack* stk)
{
	return stack_pop(stk);
}

int queue_size(stack* stk)
{
	return stack_size(stk);
}

void queue_print(stack* stk)
{
	stack_print(stk);
}