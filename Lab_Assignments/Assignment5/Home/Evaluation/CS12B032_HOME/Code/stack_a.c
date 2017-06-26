#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

// create new stack
stack* stack_new(){
	stack* st=(stack*)malloc(sizeof(stack));
	st->arr=(int*)malloc(sizeof(int)*size);
	st->top= 0;
	return st;
}

// push an element on the stack
void stack_push(stack* st, int data){
	if(!stack_is_full(st)){
		st->arr[st->top]= data;
		++(st->top);
	}
}

// pop the top element from the stack
int stack_pop(stack* st){
	int retVal=-1;
	if(!stack_is_empty(st)){
		retVal=st->arr[(st->top)-1];
		--(st->top);
	}
	return retVal;
}

// Check if stack is empty
bool stack_is_empty(stack* st){
	return st->top?false:true;
}

// bool check if stack is full
bool stack_is_full(stack* st){
	return st->top >= size?true:false;
}

// find the size of the stack
int stack_size(stack* st){
	return st->top;
}

// print stack element
void stack_print(stack* st){
	int i;
	for(i=st->top-1;i>=0;i--)
		printf("%d ",st->arr[i]);
}