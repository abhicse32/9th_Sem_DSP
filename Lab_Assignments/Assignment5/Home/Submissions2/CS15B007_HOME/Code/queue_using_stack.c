#include "queue_using_stack.h"
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

stack* queue_new(){
	stack *new=stack_new();

	return new;
}

void enqueue(stack *s, int elm){
	stack *alt=stack_new();

	for( ; !stack_is_empty(s) ; ){
		stack_push(alt,stack_pop(s));
	}
	stack_push(s,elm);
	for( ; !stack_is_empty(alt) ; ){
		stack_push(s,stack_pop(alt));
	}
}

int dequeue(stack *s){
	return stack_pop(s);
}

bool queue_is_empty(stack *s){
	return stack_is_empty(s);
}

int queue_size(stack *s){
	return stack_size(s);
}

void queue_print(stack *s){
	stack_print(s);
}
