#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "List.h"

stack* queue_new();

void enqueue(stack* Q,int data);

int dequeue(stack* Q);

bool queue_is_empty(stack* Q);

int queue_size(stack* Q);

void queue_print(stack* Q);
