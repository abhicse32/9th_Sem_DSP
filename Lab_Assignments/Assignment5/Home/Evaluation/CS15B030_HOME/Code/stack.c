#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

stack* stack_new() {
	stack* new = (stack*) malloc(sizeof(stack));
	new->top = llist_new();
	return new;
}

void stack_push(stack* stk, int data) {
	llist_prepend(stk->top, data);
}

int stack_pop(stack* stk) {
	int pop = stk->top->head->data;
	llist_remove_first(stk->top);
	return pop;
}

bool stack_is_empty(stack* stk) {
	return stk->top->head == NULL;
}

int stack_size(stack* stk) {
	return llist_size(stk->top);
}

void stack_print(stack* stk) {
	llist_print(stk->top);
}
