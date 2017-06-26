/*D TEJA VARDHAN REDDY CS15B014  18/9/16*/
/* STACK_USING QUEUE FUNCTIONS*/

#include "stack_using_queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>


// create a new stack
queue* stack_new(){
	queue*que= queue_new();
}

//REVERSES THE QUEUE
void reverse_queue(queue*que){
	if(queue_is_empty(que))
		return;
	int data= dequeue(que);
	
	reverse_queue(que);
	enqueue(que,data);
}
// push an element on the stack
void stack_push(queue*que, int data){
	enqueue(que,data);
}

// pop the top element from the stack
int stack_pop(queue*que){
	reverse_queue(que);
	int data=dequeue(que);
	reverse_queue(que);
	return data;
}

// Check if stack is empty
bool stack_is_empty(queue*que){
	return queue_is_empty(que);
}


// find the size of the stack
int stack_size(queue*que){
	return queue_size(que);
}

// print stack element
void stack_print(queue*que){
	
	reverse_queue(que);
	queue_print(que);
	reverse_queue(que);
}



