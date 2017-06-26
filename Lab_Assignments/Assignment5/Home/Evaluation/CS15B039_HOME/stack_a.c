#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define size 1000

// create a new stack
stack* stack_new(){
	
	stack* new_stack = (stack*) malloc(sizeof(stack));
	new_stack->arr = (int *) malloc(sizeof(int)*size);
	new_stack->top = -1;
	return new_stack;
}

// Check if stack is empty
bool stack_is_empty(stack* stkArr){
	return (stkArr->top == -1);
}

// bool check if stack is full
bool stack_is_full(stack* stkArr){
	return (stkArr->top == (size-1));
}

// push an element on the stack
void stack_push(stack* stkArr, int n){
	
	if(!stack_is_full(stkArr)){
		stkArr->top++;
		(stkArr->arr)[stkArr->top] = n;
	}
}

// pop the top element from the stack
int stack_pop(stack* stkArr){
	
	int x;
	if(!stack_is_empty(stkArr)){
		x = (stkArr->arr)[stkArr->top];
		stkArr->top--;
		return x;
	}
	else
		return INT_MAX;
}

// find the size of the stack
int stack_size(stack* s){
	return (s->top + 1);
}

// print stack element
void stack_print(stack* s){
	stack *s2 = stack_new();
	int x;
	while(!stack_is_empty(s)){
		x = stack_pop(s);
		printf("%d ", x);
		stack_push(s2, x);
		}
	//printf("\n");
	while(!stack_is_empty(s2))
		stack_push(s, stack_pop(s2));
}
