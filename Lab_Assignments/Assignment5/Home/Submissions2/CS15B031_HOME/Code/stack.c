//Author: Phalguna Rao Ch.
//CS15B031
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
stack* stack_new(){
	stack* newstack = (stack*) malloc(sizeof(stack));
	newstack->top = llist_new();
	return newstack;
}
void stack_push(stack* st, int data){
	llist_prepend(st->top, data);
}
int stack_pop(stack* st){
	if(st->top->head == NULL) return INT_MIN;
	int val = st->top->head->data;
	llist_remove_first(st->top);
	return val;
}
bool stack_is_empty(stack* st){
	if(st->top->head == NULL) return true;
	else return false;
}
int stack_size(stack* st){
	return llist_size(st->top);
}
void stack_print(stack* st){
	llist_print(st->top);
	fflush(stdout);
}

































