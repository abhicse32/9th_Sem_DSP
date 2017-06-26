#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

stack* stack_new(){

	stack *stk = (stack*)malloc(sizeof(stack));
	stk->arr = (int*)malloc(size*sizeof(int));

	stk->top = -1;

	return stk;
}

void stack_push(stack* stk, int data){

	stk->top++;
	stk->arr[stk->top] = data;

	return;
}

int stack_pop(stack* stk){

	int top = stk->arr[stk->top];
	stk->top--;

	return top;
}

bool stack_is_empty(stack* stk){

	if(stk->top == -1) return 1;
	return 0;
}

bool stack_is_full(stack* stk){

	if(stk->top == size-1) return 1;
	return 0;	
}

int stack_size(stack* stk){

	return stk->top + 1;
}

void stack_print(stack* stk){

	if(stk->top == -1) return;

	int i;

	for(i = stk->top; i > -1; i--) printf("%d ",stk->arr[i]);

	return ;	
}
