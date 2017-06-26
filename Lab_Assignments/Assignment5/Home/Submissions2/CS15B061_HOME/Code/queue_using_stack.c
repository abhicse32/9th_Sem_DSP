/*-----------------------------------------------------------------------------
 *  Program to implement queue ADT using stack
 *  Name: Harshavardhan.P.K.
 *  RollNo: CS15B061
 *  Date: 17 Sept,2016
 *-----------------------------------------------------------------------------*/
#include "queue_using_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <stdbool.h>

// create a new queue
queue* queue_new(){
	queue* newQ = (queue*)malloc(sizeof(queue));
	newQ->s=stack_new();
	return newQ;
}

// add an element to the queue
void enqueue(queue* q, int n){
	stack_push(q->s,n);
}

// remove the front element from the queue
int dequeue(queue* q){
	stack* t = stack_new();
	int n;
	//if stack is empty return
	if(stack_is_empty(q->s)) return stack_pop(q->s);
	//pop all elements of s into t
	n=stack_pop(q->s);
	stack_push(t,n);
	while(!stack_is_empty(q->s)){
		n=stack_pop(q->s);
		stack_push(t,n);
	}
	// note that n contains last element

	//now pop the last element of s which is at top of t
	stack_pop(t);
	int n2;
	//next push in rest of elements back to s
	if(stack_is_empty(t)) return n;
	n2=stack_pop(t);
	stack_push(q->s,n2);
	while(!stack_is_empty(t)){
		n2=stack_pop(t);
		stack_push(q->s,n2);
	}
	//return n
	return n;
}

// Check if queue is empty
bool queue_is_empty(queue* q){
	return (stack_is_empty(q->s));
}

// find the size of the queue
int queue_size(queue* q){
	return(stack_size(q->s));
}

// print queue element
void queue_print(queue* q){
	//stack t to temporirily stoe and print from reverse
	stack* t = stack_new();
	while(!stack_is_empty(q->s)){
		stack_push(t,stack_pop(q->s));
	}
	//print from front to rear
	stack_print(t);
	//push all elements back to s
	while(!stack_is_empty(t))
		stack_push(q->s,stack_pop(t));
}

