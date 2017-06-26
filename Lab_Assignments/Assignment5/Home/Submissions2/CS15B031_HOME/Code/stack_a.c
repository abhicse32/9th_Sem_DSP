//Author: Phalguna Rao Ch.
//CS15B031
#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define size 1000
stack* stack_new(){
	stack* st = (stack*) malloc(sizeof(stack));
	st->arr = (int*) malloc(sizeof(int) * size);
	st->top = -1;
	return st;
}
void stack_push(stack* st, int data){
	if(st->top >= size-1) return ;
	st->top++;
	st->arr[st->top]= data;
}
int stack_pop(stack* st){
	if(st->top == -1) return INT_MIN;
	if(st->top == 0){
		st->top = -1;
		return st->arr[0];
	}
	int val = st->arr[st->top];
	st->top--;
	return val;
}
bool stack_is_empty(stack* st){
	if(st->top == -1) return true;
	else return false;
}
bool stack_is_full(stack* st){
	if(st->top >= size-1) return true;
	else return false;
}
int stack_size(stack* st){
	return (st->top + 1);
}
void stack_print(stack* st){
	int i;
	for(i = st->top; i >= 0; i--){
		printf("%d ", st->arr[i]);
	}
	//printf("\n");
	fflush(stdout);
}































