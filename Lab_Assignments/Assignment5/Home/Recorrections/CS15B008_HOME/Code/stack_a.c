/* Program that implements basic stack functions using an array
	G.Pranav	CS15B015	18-9-2016	*/
#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define size 1000

// create a new stack
stack* stack_new(){
	stack *stackptr=malloc(sizeof(stack));
	int *array=malloc(size*sizeof(int));
	stackptr->arr=array;
	stackptr->top=-1;
	return stackptr;
}

// push an element on the stack
void stack_push(stack* stackptr, int x){
	if(!stack_is_full(stackptr)){
		int num=stackptr->top;
		int *array=stackptr->arr;
		array[num+1]=x;
		(stackptr->top)++;
	}
}

// pop the top element from the stack
int stack_pop(stack* stackptr){
	int ans;
	if(!stack_is_empty(stackptr)){
		int num=stackptr->top;
		int *array=stackptr->arr;
		ans=array[num];
		(stackptr->top)--;
	}
	return ans;
}

// Check if stack is empty
bool stack_is_empty(stack* stackptr){
	if(stack_size(stackptr)==0) return 1;
	else return 0;
}

// bool check if stack is full
bool stack_is_full(stack* stackptr){
	if(stack_size(stackptr)==size) return 1;
	else return 0;
}

// find the size of the stack
int stack_size(stack* stackptr){
	return ((stackptr->top)+1);
}

// print stack element
void stack_print(stack* stackptr){
	int *array=stackptr->arr;
	int num=stackptr->top;
	int i;
	for(i=num;i>=0;i--){
		printf("%d ",array[i]);
	}
	//printf("\n");
}