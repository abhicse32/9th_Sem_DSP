#include "stack_3.h"
#include "List_3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// push an element on the stack
stack* stack_new(){
	stack* st=(stack*) malloc(sizeof(stack));
	st->top= llist_new();
	return st;
}
void stack_push(stack* st, char* num){
	llist_prepend(st->top,strdup(num));
}

// pop the top element from the stack
char* stack_pop(stack* st){
	char* ret_val= llist_get(st->top,0);
	llist_remove_first(st->top);
	return ret_val;
}

// Check if stack is empty
bool stack_is_empty(stack* st){
	if(st->top->head)
		return false;
	return true;
}

// find the size of the stack
int stack_size(stack* st){
	return llist_size(st->top);
}

// print stack element
void stack_print(stack* st){
	llist_print(st->top);
}
char* stack_top(stack* st){
  return llist_get(st->top,0);
}
