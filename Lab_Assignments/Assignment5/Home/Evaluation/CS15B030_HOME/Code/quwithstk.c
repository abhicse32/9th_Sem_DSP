#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack* stack_new() {
	stack* new = (stack*) malloc(sizeof(stack));
	new->top = llist_new();
	return new;
}

void enqueue(stack* stk, int data) {
	stack* stk2 = stack_new();
	while (!stack_is_empty(stk)) {
		stack_push(stk2, stack_pop(stk));
	}
	stack_push(stk, data);
	while (!stack_is_empty(stk2)) {
		stack_push(stk, stack_pop(stk2));
	}
	free(stk2);
}

int dequeue(stack* stk) {
	return stack_pop(stk);
}

bool queue_is_empty(stack* stk) {
	return stack_is_empty(stk);
}

int queue_size(stack* stk) {
	return stack_size(stk);
}

void queue_print(stack* stk) {
	stack_print(stk);
}
