#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000


stack* stack_new(){
	stack* st=(stack*) malloc(sizeof(stack));
	st->top=0;
	int* A=malloc(sizeof(int)*size);
	st->arr=A;
	return st;
}

// push an element on the stack
void stack_push(stack* st, int num){
	if(!stack_is_full)
	{
	st->arr[top]=num;
	st->top++;
	}
}

// pop the top element from the stack
int stack_pop(stack* st){
	if(!stack_is_empty)
	st->top--;
}

// Check if stack is empty
bool stack_is_empty(stack* st){
	if(st->top==0)
		return false;
	return true;
}

// bool check if stack is full
bool stack_is_full(stack*)
{
if(st->top==size)
return true;
else
return false;
}


// find the size of the stack
int stack_size(stack* st){
	return st->top;
}

// print stack element
void stack_print(stack* st){
	for(i=0;i<st->top;i++)
	printf("%d ",st->arr[i]);
}
