#include "stack_using_queue.h"
#include <stdio.h>
#include <stdlib.h>

// create a new stack
stack_q* stack_new(){
	stack_q *st= (stack_q*)malloc(sizeof(stack_q));
	st->que1= queue_new();
	st->que2= queue_new();
	return st;
}

// push an element on the stack
void enqueue2(queue* front1, queue* front2, int val){
	enqueue(front1,val);
	while(!queue_is_empty(front2))
		enqueue(front1,dequeue(front2));
}

void stack_push(stack_q* st, int val){
	if(queue_is_empty(st->que1))
		enqueue2(st->que1,st->que2, val);
	else enqueue2(st->que2,st->que1, val);
}

// pop the top element from the stack
int stack_pop(stack_q* st){
	return (queue_is_empty(st->que1)? dequeue(st->que2):dequeue(st->que1));
}

// Check if stack is empty
bool stack_is_empty(stack_q* st){
	return (queue_is_empty(st->que1) && queue_is_empty(st->que2)); 
}

// find the size of the stack
int stack_size(stack_q* st){
	return (queue_size(st->que1)+queue_size(st->que2));
}

// print stack element
void stack_print(stack_q* st){
	queue_is_empty(st->que1)? queue_print(st->que2):queue_print(st->que1);
}