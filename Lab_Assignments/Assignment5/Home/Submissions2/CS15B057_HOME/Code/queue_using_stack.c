/*
	Author:G.Kavitha
	Roll No.: CS15B057
	Date: 16/09/16
*/
#include "queue_using_stack.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// create a new queue
stack* queue_using_stack_new(){
	stack* temp=(stack*)malloc(sizeof(stack));
	temp->top=llist_new();
	return temp;
}

// add an element to the queue
void enqueue_using_stack(stack* q, int data){
	llist_append(q->top,data);
}

// remove the front element from the queue
int dequeue_using_stack(stack* q){
	if(queue_using_stack_is_empty(q)) return INT_MIN;
	int res=q->top->head->data;
	llist_remove_first(q->top);
	return res;
}

// Check if queue is empty
bool queue_using_stack_is_empty(stack* q){
	if(q->top->head==NULL) return true;
	return false;
}

// find the size of the queue
int queue_using_stack_size(stack* q){
	return llist_size(q->top);
}

// print queue element
void queue_using_stack_print(stack* q){
	llist_print(q->top);
}
