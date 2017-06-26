#ifndef STACK_USING_QUEUE_H
#define STACK_USING_QUEUE_H
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* stack_new();

bool stack_is_empty(queue* q);

int stack_size(queue* q);

void stack_print(queue* q);

void ReverseRec(queue* q);

queue* stack_push(queue* q, int data);

int stack_pop(queue* q);

#endif
