/*To implement various operations on a stack
  such as push, pop, finding size and printing
  Author: CS15B046 Jahnvi Patel
  September 8th, 2016
*/
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

//create a new stack
stack* stack_new()
{	
	stack* newStack=(stack*)malloc(sizeof(stack));
	if(newStack!=NULL)
		newStack->top=llist_new();
	return newStack;
}

// push an element on the stack

void stack_push(stack* s, int val)
{
	llist_prepend(s->top,val);
}

// pop the top element from the stack
int stack_pop(stack* s)
{
	if(s->top->head!=NULL)
	{
		Node* temp=s->top->head;
		int num=s->top->head->data;
		s->top->head=s->top->head->next;
		free(temp);
		return num;
	}
		
}


// Check if stack is empty
bool stack_is_empty(stack* s)
{
	if(s->top->head==NULL)
		return true;
	return false;
}


// find the size of the stack

int stack_size(stack* s)
{
	return(llist_size(s->top));
}

// print stack element
void stack_print(stack* s)
{
	llist_print(s->top);
	
}

