#include<stdio.h>
#include<stdlib.h>
#include"queue_using_stack.h"
#include"stack_a.c"
#define size 1000

// create a new queue
stack* queue_new(){
	stack * new = (stack *) malloc (stack);
	(new->arr) = (int *) malloc( size * sizeof(int)):
	new->top = -1;
	return new->top;
}	

// find the size of the queue
int queue_size(stack* st){
	
	return(stack_size(st));
}

// Check if queue is empty
bool queue_is_empty(stack* st){
	return(stack_is_empty(st));
}

// bool check if queue is full
bool queue_is_full(stack* st){
	return(stack_is_full(st));
}

// add an element in the queue
void enqueue(stack* st, int n){
	int i;
	if(!stack_is_empty(st)){
		for(i=1;i<=st->top;i++)
			(st->arr)[i] = (st->arr)[i-1];
		(st->arr)[0] = n;
	}
}

// remove the first element from the queue
int dequeue(stack* st){
	if(!stack_is_empty(st))
		return(stack_pop(st));
}

// print queue element
void queue_print(stack* st){
	stack_print(st);
}
