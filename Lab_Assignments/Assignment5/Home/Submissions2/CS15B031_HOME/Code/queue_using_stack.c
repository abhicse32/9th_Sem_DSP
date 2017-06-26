//Author: Phalguna Rao Ch.
//CS15B031
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"queue_using_stack.h"

stack* queue_new(){
	stack* newstack = (stack*) malloc(sizeof(stack));
	newstack->top = llist_new();
	return newstack;
}
void enqueue(stack **st1, int data){
	stack* st2 = stack_new();
	 while(1){
		if(stack_size(*st1) <= 0) break;
		stack_push(st2, stack_pop(*st1));
	}
	stack_push(*st1, data);
	while(1){
		if(stack_size(st2) <= 0) break;
		stack_push(*st1, stack_pop(st2));
	}
}
int dequeue(stack* st){
	return stack_pop(st);
}
bool queue_is_empty(stack* st){
	return stack_is_empty(st);
}
int queue_size(stack* st){
	return stack_size(st);
}
void queue_print(stack* st){
	stack_print(st);
}

