/*
	Author:G.Kavitha
	Roll No.: CS15B057
	Date: 16/09/16
*/
#include "stack_using_queue.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// create a new stack
queue* stack_using_queue_new(){
	queue* temp=(queue*)malloc(sizeof(queue));
	temp->front=llist_new();
	temp->rear=temp->front;
	return temp;
}

// push an element on the stack
void stack_using_queue_push(queue* s, int data){
	llist_prepend(s->front,data);
}

// pop the top element from the stack
int stack_using_queue_pop(queue* s){
	int sz=llist_size(s->front);
	if(sz==0) return INT_MIN;
	Node* save=s->front->head;
	s->front->head=save->next;
	int res=save->data;
	free(save);	
	return res;
}

// Check if stack is empty
bool stack_using_queue_is_empty(queue* s){
	if(s->front->head==NULL) return true;
	return false;
}

// find the size of the stack
int stack_using_queue_size(queue* s){
	int res=0;
	Node* temp=s->front->head;
	while(temp!=NULL){
		res++;
		temp=temp->next;
	}
	return res;
}

// print stack element
void stack_using_queue_print(queue* s){
	llist_print(s->front);
}
