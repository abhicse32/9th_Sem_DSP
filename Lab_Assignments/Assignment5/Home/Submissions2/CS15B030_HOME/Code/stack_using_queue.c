#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue* queue_new() {
	queue* new = (queue*) malloc(sizeof(queue));
	new->front = llist_new();
	new->rear = llist_new();
	return new;
}

void stack_push(queue* qu, int data) {
	queue* qu2 = queue_new();
	while (!queue_is_empty(qu)) {
		enqueue(qu2, dequeue(qu));
	}
	enqueue(qu, data);
	while (!queue_is_empty(qu2)) {
		enqueue(qu, dequeue(qu2));
	}
}

int stack_pop(queue* qu) {
	return dequeue(qu);
}

bool stack_is_empty(queue* qu) {
	return queue_is_empty(qu);
}

int stack_size(queue* qu) {
	return queue_size(qu);
}

void stack_print(queue* qu) {
	queue_print(qu);
}
