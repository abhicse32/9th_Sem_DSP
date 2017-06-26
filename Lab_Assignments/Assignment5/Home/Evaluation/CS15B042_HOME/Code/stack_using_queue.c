/*Implements all funtions listed in stack_using_queue.h
Y BHARGAVA SAI CS15B042 18-Sep-2016*/
#include <stdio.h>
#include <stdlib.h>
#include "stack_using_queue.h"
#include "List.h"
#include "queue.h"

// create a new stack
queue * stack_new(){
	queue * q = (queue *)malloc(sizeof(queue));
	q -> front = llist_new();
	q -> rear = llist_new();
}

// push an element on the stack
void stack_push(queue* q1,int x){
	queue* q2 = queue_new();	
	enqueue(q2,x);
	while(!queue_is_empty(q1)){
		enqueue(q2,dequeue(q1));
	}	
	while(!queue_is_empty(q2)){
		enqueue(q1,dequeue(q2));
	}
}

// pop the top element from the stack
int stack_pop(queue* q){
	return dequeue(q);
}

// Check if stack is empty
bool stack_is_empty(queue *q){
	return queue_is_empty(q);
}

// find the size of the stack
int stack_size(queue *q){
	return queue_size(q);
}

// print stack element
void stack_print(queue *q){
	queue_print(q);
}	
	
