#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include"List.h"

stack* queue_new(){
	stack* Q=stack_new();
	return Q;
}

void enqueue(stack* Q,int data){
	stack_push(Q,data);
}

int dequeue(stack* Q){
	stack S=stack_new();
	while(stack_is_empty(Q)==false){
			stack_push(S,stack_pop(Q));
	}
	return stack_pop(S);
		while(stack_is_empty(S)==false){
			stack_push(Q,stack_pop(S));
	}
}

bool queue_is_empty(stack* Q){
	if(Q->top==NULL) return true;
	else return false;	
}

int queue_size(stack* Q){
	int size=llist_size(Q->top);
	return size;
}

void queue_print(queue* Q){
	llist_print(Q->top);
}

