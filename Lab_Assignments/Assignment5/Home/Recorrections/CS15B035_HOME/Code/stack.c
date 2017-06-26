#include "stack.h"
#include "List.h"
#include<limits.h>
#include <stdio.h>
#include <stdlib.h>

stack* stack_new(){
	stack* S = (stack*)malloc(sizeof(stack));
	S->top = llist_new();
	return S;
}


void stack_push(stack* S,int data){
	llist_prepend(S->top,data);

}

int stack_pop(stack* S){
	if(stack_size(S)==0) return INT_MIN;
	int topdata = llist_get(S->top,0);
	llist_remove_first(S->top);
	return topdata;
}

bool stack_is_empty(stack* S){
	if((S->top)->head == NULL) return true;
	else return false;
}

int stack_size(stack* S){
	int size = llist_size(S->top);
	return size;
}

void stack_print(stack* S){
	llist_print(S->top);
}
