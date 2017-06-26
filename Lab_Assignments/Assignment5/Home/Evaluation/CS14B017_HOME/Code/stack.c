#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

stack* stack_new(){
	stack* st=(stack*) malloc(sizeof(stack));
	st->top= llist_new();
	return st;
}
void stack_push(stack* st, int num){
	llist_prepend(st->top,num);
}

int stack_pop(stack* st){
	int ret_val= llist_get(st->top,0);
	llist_remove_first(st->top);
	return ret_val;
}

bool stack_is_empty(stack* st){
	if(st->top->head)
		return false;
	return true;
}

int stack_size(stack* st){
	return llist_size(st->top);
}

void stack_print(stack* st){
	llist_print(st->top);
}
