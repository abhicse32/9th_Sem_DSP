#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// create a new stack
stack* stack_new()
{
	stack* st=(stack*)malloc(sizeof(stack));
	st->top=llist_new();
	return st;
}

// push an element on the stack
void stack_push(stack* stck, int data)
{
	Node* np=node_new(data);
	np->next=stck->top->head;
	stck->top->head=np;
}

// pop the top element from the stack
int stack_pop(stack* stck)
{
	if(!stack_is_empty(stck))
	{
		Node* pop=stck->top->head;
		stck->top->head=stck->top->head->next;
		int val=pop->data;
		free(pop);
		return val;
	}
	else
		return INT_MIN;

}

// Check if stack is empty
bool stack_is_empty(stack* stck)
{
	if(stck->top->head==NULL)
		return 1;
	else 
		return 0;
}

// find the size of the stack
int stack_size(stack* stck)
{
	return llist_size(stck->top);
}

// print stack element
void stack_print(stack* stck)
{
	stack* stck2=stack_new();
	while(!stack_is_empty(stck))
	{
		int x=stack_pop(stck);
		printf("%d ",x);
		stack_push(stck2,x);
	}
	while(!stack_is_empty(stck2))
	{
		stack_push(stck,stack_pop(stck2));
	}
	free(stck2);
	
}