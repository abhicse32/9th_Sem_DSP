#include "q4_stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

queue* stack_new(){
	queue* S = queue_new();
	return S;
}


void stack_push(queue** S,int data){
	queue* q2 = queue_new();
	enqueue(q2,data);
	while(!queue_is_empty(*S)){
		enqueue(q2,dequeue(*S));
	}
	//queue* temp;
	*S=q2;
	//q2=temp;
}

int stack_pop(queue* S){
	return dequeue(S);
}

bool stack_is_empty(queue* S){
	if((S->front)->head == NULL) return true;
	else return false;
}

int stack_size(queue* S){
	int size = llist_size(S->front);
	return size;
}

void stack_print(queue* S){
	llist_print(S->front);}
