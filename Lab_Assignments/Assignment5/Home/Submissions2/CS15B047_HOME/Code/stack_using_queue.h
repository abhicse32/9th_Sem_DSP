#ifndef SUQ_H
#define SUQ_H
#include"queue.h"

queue *stack_new();

int stack_size(queue *Q);

void stack_print(queue *Q);

void reverse_Q(queue *Q);

bool stack_is_empty(queue *Q);

void *stack_push(queue *Q,int element);

int stack_pop(queue *Q);

#endif

