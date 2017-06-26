/*D TEJA VARDHAN REDDY CS15B014  18/9/16*/
/* QUEUE_USING_STACK FUNCTIONS*/


#include "queue_using_stack.h"
#include <stdio.h>
#include <stdlib.h>



// add an element to the queue
void enqueue(stack*st, int data){
	stack_push(st,data);

}


// remove the front element from the queue
int dequeue(stack*st){
	stack *st1= stack_new();
	while(!stack_is_empty(st)){
		stack_push(st1,stack_pop(st));
	}
	int data=stack_pop(st1);
	while(!stack_is_empty(st1)){
		int data=stack_pop(st1);
		stack_push(st,data);
	}
	return data;
}


// Check if queue is empty
bool queue_is_empty(stack*st){
	return stack_is_empty(st);

}

// find the size of the queue
int queue_size(stack*st){
	return stack_size(st);
}

// print queue element
void queue_print(stack*st){
	stack *st1= stack_new();
	while(!stack_is_empty(st)){
		stack_push(st1,stack_pop(st));
	}
	stack_print(st1);
	while(!stack_is_empty(st1)){
		int data=stack_pop(st1);
		stack_push(st,data);
	}
}