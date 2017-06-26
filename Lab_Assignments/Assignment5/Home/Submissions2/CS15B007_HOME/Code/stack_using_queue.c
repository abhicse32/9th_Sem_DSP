#include "stack_using_queue.h"
#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

queue* stack_new(){
	queue *new=queue_new();
	return new;
}

void stack_push(queue *q, int elm){
	queue *alt=queue_new();
	for( ; !queue_is_empty(q) ; ){
		enqueue(alt,dequeue(q));
	}
	enqueue(q,elm);
	for( ; !queue_is_empty(alt) ; ){
		enqueue(q,dequeue(alt));
	}	
}

int stack_pop(queue *q){
	return dequeue(q);
}

bool stack_is_empty(queue *q){
	return queue_is_empty(q); 
}

int stack_size(queue *q){
	return queue_size(q);
}

void stack_print(queue *q){
	queue_print(q);
}
