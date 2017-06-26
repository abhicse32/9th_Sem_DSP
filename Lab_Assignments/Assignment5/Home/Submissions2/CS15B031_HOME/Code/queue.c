//Author: Phalguna Rao Ch.
//CS15B031
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

queue* queue_new(){
	queue* new = (queue*) malloc(sizeof(queue));
	new->front = llist_new();
	new->rear = NULL;
	return new;
}
void enqueue(queue* qu, int data){
	llist_append(qu->front, data);
}
int dequeue(queue* qu){
	if(qu->front->head == NULL) return INT_MIN ;
	int val = qu->front->head->data;
	llist_remove_first(qu->front);
	return val;
}
bool queue_is_empty(queue* qu){
	if(qu->front->head == NULL) return true;
	else return false;
}
int queue_size(queue* qu){
	return llist_size(qu->front);
}
void queue_print(queue* qu){
	llist_print(qu->front);
}
































