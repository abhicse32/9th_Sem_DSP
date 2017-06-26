#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new() {
	queue* new = (queue*) malloc(sizeof(queue));
	new->front = llist_new();
	new->rear = llist_new();
	return new;
}

void enqueue(queue* qu, int data) {
	Node *new = node_new(data);
	if (qu->front->head != NULL) {
		qu->rear->head->next = new;
		qu->rear->head = new;
	} else {
		qu->front->head = new;
		qu->rear->head = new;
	}
}

int dequeue(queue* qu) {
	if (qu->front->head != NULL && qu->front->head != qu->rear->head) {
		int tmp = llist_get(qu->front, 0);
		llist_remove_first(qu->front);
		return tmp;
	} else if (qu->front->head != NULL && qu->front->head == qu->rear->head) {
		qu->rear->head = NULL;
		int tmp = llist_get(qu->front, 0);
		llist_remove_first(qu->front);
		return tmp;
	} else {
		return -1;
	}
}

bool queue_is_empty(queue* qu) {
	return (qu->front->head == NULL);
}

int queue_size(queue* qu) {
	return llist_size(qu->front);
}

void queue_print(queue* qu) {
	llist_print(qu->front);
}
