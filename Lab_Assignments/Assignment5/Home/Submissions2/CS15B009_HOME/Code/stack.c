/*  Program to implement the stack data structure using linked lists 

	By : Chandrashekhar D --- Roll no. CS15B009 --- 16 Sept 2016  */

#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

/*  Function to create a new stack and return a pointer to the same */
stack* stack_new()
{
	stack* stk;
	stk = (stack*)malloc(sizeof(stack));
	stk->top = llist_new();
	return stk;
}

/*	Function to check if a given stack is empty  */
bool stack_is_empty(stack* stk)
{
	return (stk->top->head == NULL);
}

/*  Function to push a given integer 'num' into the stack pointed to by stk  */
void stack_push(stack* stk,int num)
{
	llist_prepend(stk->top,num);
}

/*  Function to delete/pop the last inserted element from a stack and return that element  */
int stack_pop(stack* stk)
{
	int x = stk->top->head->data;
	llist_remove_first(stk->top);
	return x;
}

/*  Function that returns the size of the stack pointed to by stk  */
int stack_size(stack* stk)
{
	return llist_size(stk->top);
}

/*  Function to print a stack elements from top to bottom  */
void stack_print(stack* stk)
{
	llist_print(stk->top);
}