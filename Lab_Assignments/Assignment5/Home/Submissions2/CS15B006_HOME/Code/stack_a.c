#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
#include <limits.h>
#include <string.h>

stack* stack_new(){
	stack* new = malloc(sizeof(stack));
	new->arr = (int*)malloc(sizeof(int)*size);
	new->top = -1;
	return new;
}

void stack_push(stack* stk, int data){
	if(stack_is_full(stk) == 1) return;
	stk->top++;
	stk->arr[stk->top] = data;
	return;
}

int stack_pop(stack* stk){
	if(stack_is_empty(stk) == 1) return INT_MIN;
	int p = stk->arr[stk->top];
	stk->top--;
	return p;
}

bool stack_is_empty(stack* stk){
	if(stk->top == -1) return 1;
	else
		return 0;
}

bool stack_is_full(stack* stk){
	if(stk->top == size-1) return 1;
	else return 0;
}

int stack_size(stack* stk){
	//if(stack_is_empty == 1) return 0;
	int n = stk->top + 1;
	return n;
}

void stack_print(stack* stk){
	int i = stk->top;
	int *a = stk->arr;

	for(; i >= 0; i--){
		printf("%d ", a[i]);
	}
	//printf("\n");
	return;
}


