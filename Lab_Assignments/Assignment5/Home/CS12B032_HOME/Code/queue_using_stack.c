#include "queue_using_stack.h"
#include <stdio.h>
#include <stdlib.h>

// create a new queue
queue_s* queue_new(){
	queue_s* que= (queue_s*)malloc(sizeof(queue_s));
	que->st1= stack_new();
	que->st2= stack_new();
	return que;
}	

// add an element to the queue
void enqueue(queue_s* que, int val){
	while(!stack_is_empty(que->st1))
		stack_push(que->st2,stack_pop(que->st1));
	stack_push(que->st2,val);
	while(!stack_is_empty(que->st2))
		stack_push(que->st1,stack_pop(que->st2));
}

// remove the front element from the queue
int dequeue(queue_s* que){
	return stack_pop(que->st1);
}

// Check if queue is empty
bool queue_is_empty(queue_s* que){
	return stack_is_empty(que->st1);
}

// find the size of the queue
int queue_size(queue_s* que){
	return stack_size(que->st1);
}

// print queue element
void queue_print(queue_s* que){
	stack_print(que->st1);
}