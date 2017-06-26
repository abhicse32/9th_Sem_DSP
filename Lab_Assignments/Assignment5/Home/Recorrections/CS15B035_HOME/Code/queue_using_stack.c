#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "List.h"
#include "q4_queue.h"

stack* queue_new(){
	stack* Q=stack_new();
	return Q;
}

void enqueue(stack* Q,int data){
	stack_push(Q,data);
}

int dequeue(stack* Q){
	stack* S=stack_new();
	while(stack_is_empty(Q)==false){
			stack_push(S,stack_pop(Q));
	}
	int s = stack_pop(S);
		while(stack_is_empty(S)==false){
			stack_push(Q,stack_pop(S));
	}
	return s;
}

bool queue_is_empty(stack* Q){
	return stack_is_empty(Q);	
}

int queue_size(stack* Q){
	int size=llist_size(Q->top);
	return size;
}

void queue_print(stack* Q){
	if(stack_size(Q)==0){
		return;
	}
	int s = stack_pop(Q);
	queue_print(Q);
	printf("%d ",s);
	stack_push(Q,s);
	//printf("\n");
}

