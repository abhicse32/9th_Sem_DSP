/*
	Author:G.Kavitha
	Roll No.: CS15B057
	Date: 16/09/16
*/
#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
#include <limits.h>
// create a new stack
stack* stack_new(){
	stack* temp=(stack*)malloc(sizeof(stack));
	temp->arr=(int*)malloc(sizeof(int));
	temp->top=-1;
	return temp;
}

// push an element on the stack
void stack_push(stack* s, int data){
	if(stack_is_full(s)) return ;
	(s->arr)[++(s->top)]=data;
}

// pop the top element from the stack
int stack_pop(stack* s){
	if(stack_is_empty(s)) return INT_MIN;
	int save=(s->arr)[s->top];	
	(s->top)--;
	return save;
}

// Check if stack is empty
bool stack_is_empty(stack* s){
	if(s->top==-1) return true;
	return false;
}

// bool check if stack is full
bool stack_is_full(stack* s){
	if(s->top==size-1) return true;
	return false;
}

// find the size of the stack
int stack_size(stack* s){
	return(s->top+1);
}

// print stack element
void stack_print(stack* s){
	int t=s->top;
	while(t>=0){
		printf("%d ",(s->arr)[t]);
		t--;
	}
}
