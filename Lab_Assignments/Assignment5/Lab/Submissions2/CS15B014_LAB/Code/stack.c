#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>



stack* stack_new(){
	stack*a=(stack*)malloc(sizeof(stack));
	a->top=llist_new();
}



void stack_push(stack*a, int data){
	llist_prepend( a->top, data );
}


int stack_pop(stack*a){
	if(!(stack_is_empty(a))){
		int data =llist_get(a->top,0);
		llist_remove_first( a->top );
		return data;
	}
}


bool stack_is_empty(stack*a){
	if(llist_size( a->top )==0)
		return 1;
	else 
		return 0;
}


int stack_size(stack*a){
	return llist_size(a->top);
}

void stack_print(stack*a){
	llist_print( a->top);
	
}

