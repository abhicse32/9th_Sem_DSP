#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

queue* queue_new() {
	queue* new = (queue*) malloc(sizeof(queue));
	new->arr = (int*) malloc(sizeof(int) * size);
	new->front = 0;
	new->rear = -1;
	new->arr[new->rear] = -1;
	return new;
}

void enqueue(queue* qu, int data) {
	if (qu->front == (qu->rear + 1) % size && qu->arr[qu->rear] != -1) {
		return;
	}
	if (qu->rear == size - 1) {
		qu->rear = 0;
	} else {
		qu->rear++;
	}
	qu->arr[qu->rear] = data;
}

int dequeue(queue* qu) {
	if (qu->front == (qu->rear + 1) % size && qu->arr[qu->rear] == -1) {
		return -1;
	}
	int tmp = qu->arr[qu->front];
	if (qu->front == qu->rear) {
		qu->arr[qu->front] = -1;
	}
	if (qu->front == size - 1) {
		qu->front = 0;
	} else {
		qu->front++;
	}
	return tmp;
}

bool queue_is_empty(queue* qu) {
	return (qu->front == (qu->rear + 1) % size && qu->arr[qu->rear] == -1);
}

bool queue_is_full(queue* qu) {
	return (qu->front == (qu->rear + 1) % size && qu->arr[qu->rear] != -1);
}

int queue_size(queue* qu) {
	if(queue_is_full(qu)){
		return size;
	}
	return ((qu->rear - qu->front + 1 + size) % size);
}

void queue_print(queue* qu) {
	int ct = queue_size(qu);
	int i;
	for (i = 0; i < ct; i++) {
		printf("%d ", qu->arr[(i + qu->front) % size]);
	}
}
