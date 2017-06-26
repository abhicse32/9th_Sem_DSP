#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

stack* stack_new(){

	stack *stk = (stack*)malloc(sizeof(stack));
	stk->top = llist_new();
	return stk;
}

void stack_push(stack* stk, int data){

	llist_prepend(stk->top,data); 
	return ;
}

int stack_pop(stack* stk){
	
	int top = stk->top->head->data;
	
	llist_remove_first(stk->top);
	
	return top;
}

bool stack_is_empty(stack* stk){

	if(stk->top->head == NULL) return 1;
	return 0;
}

int stack_size(stack* stk){

	return llist_size(stk->top);
}

void stack_print(stack* stk){

	llist_print(stk->top);

	return ;
}
