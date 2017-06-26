#ifndef STACK_H
#define STACK_H
#include "List.h"
#include <stdbool.h>

typedef struct Stack{
	LList* top;
}stack;

stack* stack_new();

void stack_push(stack*, int);

int stack_pop(stack*);

bool stack_is_empty(stack*);

int stack_size(stack*);

void stack_print(stack*);

#endif
