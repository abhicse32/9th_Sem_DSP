/* Program that implements a stack using a queue
	G.Pranav 	CS15B015	18-9-2016	*/
#include "stack_using_queue.h"
#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

// create a new stack
queue* stack_new(){
	queue* queueptr=queue_new();
	return queueptr;
}

// push an element on the stack
void stack_push(queue* queueptr,int x){
	int size=stack_size(queueptr);
	enqueue(queueptr,x);
	while(size--){
		int temp=dequeue(queueptr);
     	enqueue(queueptr,temp);
	}

}

// pop the top element from the stack
int stack_pop(queue* queueptr){
	int a=dequeue(queueptr);
	return a;
}

// Check if stack is empty
bool stack_is_empty(queue* queueptr){
	return queue_is_empty(queueptr);
}

// find the size of the stack
int stack_size(queue* queueptr){
	return queue_size(queueptr);
}

// print stack element
void stack_print(queue* queueptr){
	queue_print(queueptr);
}