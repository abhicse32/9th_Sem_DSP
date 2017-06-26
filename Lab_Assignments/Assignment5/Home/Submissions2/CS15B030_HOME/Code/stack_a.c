#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

stack* stack_new() {
	stack* new = (stack*) malloc(sizeof(stack));
	new->top = -1;
	new->arr = (int*) malloc(sizeof(int) * size);
	return new;
}

void stack_push(stack* stk, int data) {
	if (stk->top < 999) {
		stk->top++;
		stk->arr[stk->top] = data;
	}
}

int stack_pop(stack* stk) {
	if (stk->top != -1) {
		int tmp = stk->arr[stk->top];
		stk->arr[stk->top] = 0;
		stk->top--;
		return tmp;
	}
	return -1;
}

bool stack_is_empty(stack* stk) {
	if (stk->top == -1) {
		return true;
	} else {
		return false;
	}
}

bool stack_is_full(stack* stk) {
	if (stk->top == 999) {
		return true;
	} else {
		return false;
	}
}

int stack_size(stack* stk) {
	return (stk->top + 1);
}

void stack_print(stack* stk) {
	int i;
	for (i = stk->top; i >= 0; i--) {
		printf("%d ", stk->arr[i]);
	}
}
