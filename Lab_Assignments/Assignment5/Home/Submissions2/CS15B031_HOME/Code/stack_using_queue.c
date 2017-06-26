//Author: Phalguna Rao Ch.
//CS15B031
#include<stdio.h>
#include<stdlib.h>
//#include"stack.h"
#include"queue.h"
#include"stack_using_queue.h"

queue* stack_new(){
	queue* new = (queue*) malloc(sizeof(queue));
	new->front = llist_new();
	new->rear = NULL;
	return new;
}
void stack_push(queue **qu1, int data){
	queue* qu2 = queue_new();
	enqueue(qu2, data);
	while(1){
		if(queue_size(*qu1) <= 0) break;
		enqueue(qu2, dequeue(*qu1));
	}
	*qu1 = qu2;
}
int stack_pop(queue* qu){
	return dequeue(qu);
}
bool stack_is_empty(queue* qu){
	return queue_is_empty(qu);
}
int stack_size(queue* qu){
	return queue_size(qu);
}
void stack_print(queue* qu){
	queue_print(qu);
}
	









