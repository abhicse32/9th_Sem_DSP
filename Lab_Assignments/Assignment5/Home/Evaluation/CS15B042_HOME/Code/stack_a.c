/*Implements all funtions listed in stack_a.h
Y BHARGAVA SAI CS15B042 18-Sep-2016*/
#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

// create a new stack
stack* stack_new(){
	stack* s = (stack*)malloc(sizeof(stack));
	s -> arr = (int*)malloc(sizeof(int)*size);
	s -> top = 0;
}

// push an element on the stack
void stack_push(stack* s, int x){
	if(!stack_is_full(s)){
		s -> top ++;
		s -> arr[s -> top] = x;
	}	
}

// pop the top element from the stack
int stack_pop(stack* s){
	if(!stack_is_empty(s)){
		return s -> arr[s -> top--];
	}
}

// Check if stack is empty
bool stack_is_empty(stack* s){
	if(s -> top == 0) return 1;
	return 0;
}

// bool check if stack is full
bool stack_is_full(stack* s){
	if(s -> top == 999) return 1;
	return 0;
}

// find the size of the stack
int stack_size(stack* s){
	return (s -> top);
}

// print stack element
void stack_print(stack* s){
	stack* temp = stack_new();
	int x;
	while(!stack_is_empty(s)){
		x = stack_pop(s);
		printf("%d ",x);
		stack_push(temp,x);
	}
	while(!stack_is_empty(temp)){
		x = stack_pop(temp);
		stack_push(s,x);
	}
}