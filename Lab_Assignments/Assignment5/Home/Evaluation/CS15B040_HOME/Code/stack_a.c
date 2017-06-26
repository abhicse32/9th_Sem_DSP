#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define size 1000

// create a new stack
stack* stack_new(){

	stack* sstack=(stack*)malloc(sizeof(stack));
	sstack->arr=(int*)malloc(size*sizeof(int));
	(sstack->top)=-1;
	return sstack;
}

// push an element on the stack
void stack_push(stack* S, int data){
	if(!(stack_is_full(S))){
		S->top++;
		S->arr[S->top]=data;
	}
}

// pop the top element from the stack
int stack_pop(stack* S){
	int ret_val;
	if(!(stack_is_empty(S))){
		ret_val=S->arr[S->top];
		S->top--;
		return ret_val;
	}
}

// Check if stack is empty
bool stack_is_empty(stack* S){
	if((S->top)==-1){
		return true;
	}
	else{
		return false;
	}
}

// bool check if stack is full
bool stack_is_full(stack* S){
	if(S->top==size-1){
		return true;
	}
	else{
		return false;
	}
}

// find the size of the stack
int stack_size(stack* S){
	int x;
	x=S->top;
	return x+1;
}

// print stack element
void stack_print(stack* S){
	int i;
	for(i=(S->top);i>=0;i--){
		printf("%d ",S->arr[i]);
	}
}	
