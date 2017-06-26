#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

#include <stdbool.h>
#include <limits.h>


/*
typedef struct Stack_a{
	int *arr;
	int top;
}stack;
*/

// create a new stack
stack* stack_new(){
	stack* s;
	s=(stack*)malloc(sizeof(stack));
	s->arr=(int*)malloc(sizeof(int)*size);
	s->top=-1;
	return s;
}

// push an element on the stack
void stack_push(stack* s, int dat){
	if(s->top==size-1)
		return;
	else{
		(s->top)++;
		s->arr[s->top]=dat;
	}
}

// pop the top element from the stack
int stack_pop(stack* s){
	if(s->top==-1)
		return INT_MIN;
	else
		s->top--;
		return s->arr[(s->top)+1];
}

// Check if stack is empty
bool stack_is_empty(stack* s){
	return(s->top==-1);
}

// bool check if stack is full
bool stack_is_full(stack* s){
	return (s->top==size-1);
}

// find the size of the stack
int stack_size(stack* s){
	return (s->top+1);
}

// print stack element
void stack_print(stack* s){
	int i;
	if(s->top!=-1){
		for(i=s->top;i>=0;i--){
			printf("%d ",s->arr[i]);
		}
//		printf("\n");
	}
}
