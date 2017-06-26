/*-----------------------------------------------------------------------------
 *  Program to implement stack ADT using queues
 *  Name: Harshavardhan.P.K.
 *  RollNo: CS15B061
 *  Date: 17 Sept,2016
 *-----------------------------------------------------------------------------*/
#include "stack_using_queue.h"
#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// create a new stack
stack* stack_new(){
	stack* newS = (stack*)malloc(sizeof(stack));
	newS->top= queue_new();
	return newS;
}

// push an element on the stack
void stack_push(stack* s, int n){
	int sz = queue_size(s->top);
	//enqueue to rear
	enqueue(s->top,n);
	int i;
	//now place the next sz elements before n, to n gets to top
	for(i=0;i<sz;i++){
		int nu = dequeue(s->top);
		enqueue(s->top,nu);
	}
}

// pop the top element from the stack
int stack_pop(stack* s){
	return dequeue(s->top);
}

// Check if stack is empty
bool stack_is_empty(stack* s){
	return(queue_is_empty(s->top));
}

// find the size of the stack
int stack_size(stack* s){
	return (queue_size(s->top));
}

// print stack element
void stack_print(stack* s){
	queue_print(s->top);
}

