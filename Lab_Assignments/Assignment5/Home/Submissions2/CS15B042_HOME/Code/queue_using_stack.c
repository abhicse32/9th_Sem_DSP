/*Implements all funtions listed in queue_using_stack.h
Y BHARGAVA SAI CS15B042 18-Sep-2016*/
#include "queue_using_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "stack.h"

// create a {new queue
stack* queue_new(){
	stack* new = (stack*)malloc(sizeof(stack));
	new -> top = llist_new();
	return new;
}

void enqueue(stack* s1,int x){
	stack* s2 = stack_new();
	while(!stack_is_empty(s1)){
		stack_push(s2,stack_pop(s1));
	}
	stack_push(s1,x);
	while(!stack_is_empty(s2)){
		stack_push(s1,stack_pop(s2));
	}
	return;
}

int dequeue(stack *s){
	return stack_pop(s);
}

// Check if queue is empty
bool queue_is_empty(stack* s){
	return stack_is_empty(s);
}

// find the size of the queue
int queue_size(stack* s){
	return stack_size(s);
}

// print queue element
void queue_print(stack* s){
	stack_print(s);
}