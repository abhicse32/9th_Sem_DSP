
#include "queue.h"
#include <stdbool.h>
#include <stdlib.h>



// create a new stack
stack* stack_new(){
	stack *s;
	s=(stack*)malloc(sizeof(stack));
	s->top=queue_new();
	return s;
}

// push an element on the stack
void stack_push(stack* s, int dat){
	queue *q2=queue_new();
	int x;
	//reverse s->top, store in q2
	reverse(s->top, q2);

	//enqueue data
	enqueue(q2, dat);

	//reverse q2, store in s->top
	reverse(q2, s->top);
}



void reverse(queue* q1, queue* q2){
	int x;
	x=dequeue(q1);
	if(!queue_is_empty(q1))
		reverse(q1, q2);
	enqueue(q2, x);
}


// pop the top element from the stack
int stack_pop(stack* s){
	int val=dequeue(s->top);
	return val;

}

// Check if stack is empty
bool stack_is_empty(stack* s){
	return queue_is_empty(s->top);
}

// find the size of the stack
int stack_size(stack* s){
	return queue_size(s->top);
}

// print stack element
void stack_print(stack* s){
	queue_print(s->top);
}

