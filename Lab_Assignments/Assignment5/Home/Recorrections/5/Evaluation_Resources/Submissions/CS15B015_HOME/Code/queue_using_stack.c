/* Program that implements a queue using a stack
	G.Pranav	CS15B015	18-9-2016	*/
#include "queue_using_stack.h"
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
void reverse_stack(stack *stackptr);		//defining a function to reverse a stack
void reverse_list(LList *listptr);

void reverse_stack(stack *stackptr){
 	LList *listptr=stackptr->top;
 	Node *startptr=listptr->head;
 	if(startptr!=NULL) reverse_list(listptr);
}

void reverse_list(LList *listptr){
 	Node *startptr=listptr->head;
 	if((startptr==NULL)||((startptr->next)==NULL)){	//when startptr is NULL enters the loop else enters
 		listptr->head=startptr;							//the loop when startptr->next==NULL 
 	}
 	else{
		int temp=startptr->data;
		llist_remove_first(listptr);
		reverse_list(listptr);
		llist_append(listptr,temp);		
 	}
}

// create a new queue
stack* queue_new(){
	stack *stackptr=stack_new();
	return stackptr;
}

// add an element to the queue
void enqueue(stack *stackptr,int x){
	reverse_stack(stackptr);
	stack_push(stackptr,x);
	reverse_stack(stackptr);
}

// remove the front element from the queue
int dequeue(stack *stackptr){
	int a=stack_pop(stackptr);
	return a;
}

// Check if queue is empty
bool queue_is_empty(stack *stackptr){
	return stack_is_empty(stackptr);
}

// find the size of the queue
int queue_size(stack *stackptr){
	return stack_size(stackptr);
}

// print queue element
void queue_print(stack *stackptr){
	stack_print(stackptr);
}