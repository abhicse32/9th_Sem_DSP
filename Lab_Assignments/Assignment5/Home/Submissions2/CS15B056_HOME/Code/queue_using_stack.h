#ifndef QUEUE_USING_STACK_H
#define QUEUE_USING_STACK_H
#include "List.h"
#include <stdbool.h>


void enqueue (stack *q,int data);
int dequeue (stack *q);
int queue_size(stack *q);
bool queue_is_empty(stack* q);
void queue_print(stack* q);
void queue_print1(stack* q);

#endif