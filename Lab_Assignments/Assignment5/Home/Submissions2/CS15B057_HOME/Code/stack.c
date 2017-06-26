/*
	Author:G.Kavitha
	Roll No.: CS15B057
	Date: 16/09/16
*/
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// create a new stack
stack* stack_new(){
	stack* temp=(stack*)malloc(sizeof(stack));
	temp->top=llist_new();
	return temp;
}

// push an element on the stack
void stack_push(stack* s, int data){
	llist_prepend(s->top,data);
}

// pop the top element from the stack
int stack_pop(stack* s){
	if(llist_size(s->top)==0) return INT_MIN;
	int save=s->top->head->data;
	llist_remove_first(s->top);
	return save;
}

// Check if stack is empty
bool stack_is_empty(stack* s){
	if(llist_size(s->top)==0) return true;
	return false;
}

// find the size of the stack
int stack_size(stack* s){
	return (llist_size(s->top));
}

// print stack element
void stack_print(stack* s){
	llist_print(s->top);
}
