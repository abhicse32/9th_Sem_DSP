#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

queue* stack_new(){
	queue* S = queue_new();
	return S;
}


void stack_push(queue* S,int data){
	queue* q2 = queue_new();
	queue_enqueue(q2,data);
	while(!queue_is_empty(S)){
		queue_enqueue(q2,queue_dequeue(S));
	}
	queue* temp;
	temp=S;
	S=q2;
	q2=temp;
}

int stack_pop(stack* S){
	return queue_dequeue(S);
}

bool stack_is_empty(stack* S){
	if((S->front)->head == NULL) return true;
	else return false;
}

int stack_size(stack* S){
	int size = llist_size(S->front);
	return size;
}

void stack_print(stack* S){
	llist_print(S->front);}
