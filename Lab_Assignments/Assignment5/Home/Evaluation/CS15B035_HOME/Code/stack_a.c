#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

stack* stack_new(){
	stack* S = (stack*)malloc(sizeof(stack));
	S->top = -1;
	S->arr = (int*)malloc(size*sizeof(int));
	return S;
}

void stack_push(stack* S,int data){
	if(!stack_is_full(S)){
		(S->top)++;
		S->arr[S->top]=data;
	}
	else return;
}

int stack_pop(stack*S){
	if(!stack_is_empty(S)){
		int element = S->arr[S->top];
		(S->top)--;
		return element;
	}
	else return;
}

bool stack_is_full(stack* S){
	if(S->top == size-1) return true; 
	else return false;
}

bool stack_is_empty(stack* S){
	if(S->top==-1) return true;
	else return false;
}

int stack_size(stack* S){
	return (S->top)+1;
}

void stack_print(stack* S){
	int i = S->top;
	while(i!=-1){
		printf("%d ",S->arr[i]);
		i--;
	}
	//printf("\n");
}



