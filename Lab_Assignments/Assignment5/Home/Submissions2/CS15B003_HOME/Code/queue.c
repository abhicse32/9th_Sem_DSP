#include "List.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new(){

	queue* que = (queue*)malloc(sizeof(queue));

	que->front = llist_new();
	que->rear = llist_new();
}

void enqueue(queue* que, int data){

	Node *new = node_new(data);

	if(que->front->head == NULL){
		que->front->head = new;
		que->rear->head = new;
		return ;
	}	
	que->rear->head->next = new;
	que->rear->head = new;
	void queue_print(queue*);
	return ;
}

int dequeue(queue* que){

	int element = que->front->head->data;

	if(que->front->head == que->rear->head) que->rear->head = NULL;

	llist_remove_first(que->front);

	return element;
}

bool queue_is_empty(queue* que){

	if(que->front->head == NULL) return 1;
	return 0;
}

int queue_size(queue* que){
	
	return llist_size(que->front);
}

void queue_print(queue* que){

	llist_print(que->front);

	return;
}
