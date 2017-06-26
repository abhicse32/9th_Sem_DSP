#include "stack_using_queue.h"
#include "queue.h"
#include <stdbool.h>
#include <stdlib.h>
//#include "queue.c"
//#include "List.h"
//#include "List.c"



// create a new stack
queue* stack_new(){
	queue *top;
//	s=(stack*)malloc(sizeof(stack));
	top=queue_new();
	return top;
}



void reverse(queue* q1, queue* q2){
	int x;
	x=dequeue(q1);
	if(!queue_is_empty(q1))
		reverse(q1, q2);
	enqueue(q2, x);
}



// push an element on the stack
void stack_push(queue* top, int dat){
	if(queue_is_empty(top)){
		enqueue(top, dat);
		return;
	}

	queue *q2=queue_new();
	int x;
	//reverse s->top, store in q2
	reverse(top, q2);

	//enqueue data
	enqueue(q2, dat);

	//reverse q2, store in s->top
	reverse(q2, top);
}






// pop the top element from the stack
int stack_pop(queue* top){
	int val=dequeue(top);
	return val;

}

// Check if stack is empty
bool stack_is_empty(queue* top){
	return queue_is_empty(top);
}

// find the size of the stack
int stack_size(queue* top){
	return queue_size(top);
}

// print stack element
void stack_print(queue* top){
	queue_print(top);
}

