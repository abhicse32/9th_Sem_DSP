#ifndef STACK_USING_QUEUE_H
#define STACK_USING_QUEUE_H
#include "List.h"
#include <stdbool.h>



int stack_pop(queue *q);
int stack_pop1(queue *q);
void stack_push(queue *q,int data);
bool stack_is_empty(queue* q);
void stack_print(queue* q);

#endif