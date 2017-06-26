#ifndef QUEUE_USING_STACK_H
#define QUEUE_USING_STACK_H
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
stack* queue_new();

bool queue_is_empty(stack* stk);

int queue_size(stack* stk);

void queue_print(stack* stk);

stack* enqueue(stack* stk,int data);

int dequeue(stack* stk);

#endif
