/*D TEJA VARDHAN REDDY CS15B014  18/9/16*/
/* STACK USING LINKED LIST FUNCTIONS*/
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>


// create a new stack
stack* stack_new(){
	stack*a=(stack*)malloc(sizeof(stack));
	a->top=llist_new();
}


// push an element on the stack
void stack_push(stack*a, int data){
	llist_prepend( a->top, data );
}

// pop the top element from the stack
int stack_pop(stack*a){
	if(!(stack_is_empty(a))){
		int data =llist_get(a->top,0);
		llist_remove_first( a->top );
		return data;
	}
}

// Check if stack is empty
bool stack_is_empty(stack*a){
	if(llist_size( a->top )==0)
		return 1;
	else 
		return 0;
}

// find the size of the stack
int stack_size(stack*a){
	return llist_size(a->top);
}
// print stack element
void stack_print(stack*a){
	llist_print( a->top);	
}

