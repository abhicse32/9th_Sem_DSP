#include "queue.h"
#include "List.h"
#include "stack_using_queue.h"
#include <stdio.h>
#include <stdlib.h>

// create a new stack
stack* stack_new()
	{
		stack* a;
		a=(stack*)malloc(1*sizeof(stack));
		a->que=queue_new();
	}

// push an element on the stack
void stack_push(stack* stk, int n)
	{
		int x;
		if(queue_is_empty(stk->que)) {enqueue(stk->que,n); return;}
		enqueue(stk->que,n);
		while(1)
		{
			x=dequeue(stk->que);
			enqueue(stk->que,x);
			if(stk->que->front->head->data==n) break;
		}	
	}

// pop the top element from the stack
int stack_pop(stack* stk)
	{
		return dequeue(stk->que);
	}

// Check if stack is empty
bool stack_is_empty(stack* stk)
	{
		return queue_is_empty(stk->que);
	}

// find the size of the stack
int stack_size(stack* stk)
	{
		return queue_size(stk->que);
	}

// print stack element
void stack_print(stack* stk)
	{
		queue_print(stk->que);
	}

