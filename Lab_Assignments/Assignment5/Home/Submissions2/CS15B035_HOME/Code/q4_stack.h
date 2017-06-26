#include "queue.h"
queue* stack_new();
void stack_push(queue** S,int data);
int stack_pop(queue* S);
bool stack_is_empty(queue* S);
int stack_size(queue* S);
void stack_print(queue* S);
