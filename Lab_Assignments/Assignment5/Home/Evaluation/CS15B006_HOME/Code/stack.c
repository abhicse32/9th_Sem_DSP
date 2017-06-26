#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>


stack* stack_new(){
	stack* new = malloc(sizeof(stack));						// Allocating memory for new stack variable
	new->top = llist_new();									// Memory for llist variable in stack structure		
	return new;
}

void stack_push(stack* stk, int data){
	llist_prepend(stk->top, data);
	return;
}

int stack_pop(stack* stk){
	int p = stk->top->head->data;
	llist_remove_first(stk->top);
	return (p);
}

bool stack_is_empty(stack* stk){
	if(stk->top->head == NULL)
		return true;
	else 
		return false;
}
int stack_size(stack* stk){
	int p = llist_size(stk->top);
	return p;
}
void stack_print(stack* stk){
	llist_print(stk->top);
	return;
}


