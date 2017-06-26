/* Program that implements basic stack functions using a linked list
	G.Pranav	CS15B015	18-9-2016	*/
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

// create a new stack
stack* stack_new(){
	stack *stackptr=malloc(sizeof(stack));
	LList *listptr=llist_new();
	stackptr->top=listptr;
	return stackptr;
}

// push an element on the stack
void stack_push(stack* stackptr, int x){
	LList *listptr=stackptr->top;
	llist_prepend(listptr,x);
}

// pop the top element from the stack
int stack_pop(stack* stackptr){
	LList *listptr=stackptr->top;
	int value=llist_get(listptr,0);
	llist_remove_first(listptr);
	return value;
}

// Check if stack is empty
bool stack_is_empty(stack* stackptr){
	LList *listptr=stackptr->top;
	bool value;
	if(llist_get(listptr,0)==INT_MIN) value=1;
	else value=0;
	return value;
}

// find the size of the stack
int stack_size(stack* stackptr){
	LList *listptr=stackptr->top;
	int size=llist_size(listptr);
	return size;
}

// print stack element
void stack_print(stack* stackptr){
	LList *listptr=stackptr->top;
	llist_print(listptr);
}