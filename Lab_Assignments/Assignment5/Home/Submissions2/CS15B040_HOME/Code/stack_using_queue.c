#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

queue* stack_new(){

	queue* Q=(queue*)malloc(sizeof(queue));
	Q->front=llist_new();
	Q->rear=llist_new();
	return Q;
   
}
void stack_push(queue* P, int x){
	llist_prepend(P->front);
}
int stack_pop(queue* P){
	int x=((P->front)->head)->data;
        llist_remove_first(P->front);
        return x;
}
bool stack_is_empty(queue*p){
        return queue_is_empty(p);
}
int stack_size(queue*p){
        return queue_size(p);
}
void stack_print(queue*p){
        queue_print(p);
}
