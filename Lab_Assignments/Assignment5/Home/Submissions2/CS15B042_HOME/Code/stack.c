/*Implements all funtions listed in stack.h
Y BHARGAVA SAI CS15B042 18-Sep-2016*/
#include "stack.h"
//#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// create a new stack
stack* stack_new(){
	stack* new = (stack*)malloc(sizeof(stack));
	new -> top = llist_new();
	return new;
}

// push an element on the stack
void stack_push(stack* s, int d){
	llist_prepend(s -> top,d);
	return;
}

// pop the top element from the stack
int stack_pop(stack* s){
	if(s -> top -> head == NULL) return INT_MIN;
	int x = s -> top -> head -> data;
	s -> top -> head = s -> top -> head -> next;
	return x;
}

// Check if stack is empty
bool stack_is_empty(stack* s){
	if(s -> top -> head == NULL) return 1;
	else return 0;
}

// find the size of the stack
int stack_size(stack* s){
	return llist_size(s -> top);
}

// print stack element
void stack_print(stack* s){
	llist_print(s -> top);
}