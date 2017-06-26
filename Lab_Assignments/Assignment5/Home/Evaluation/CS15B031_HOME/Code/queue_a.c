//Author: Phalguna Rao Ch.
//CS15B031
#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
queue* queue_new(){
	queue* qu = (queue*) malloc(sizeof(queue));
	qu->arr = (int*) malloc(sizeof(int) * size);
	qu->front = -1;
	qu->rear = -1;
	return qu;
}
void enqueue(queue* qu, int data){
	if(qu->rear >= size-1) return ;
	qu->rear++;
	qu->arr[qu->rear]= data;
}
int dequeue(queue* qu){
	int i;
	if(qu->rear == 0) return qu->arr[0];
	int val = qu->arr[0];
	for(i = 1; i <= qu->rear; i++){
		qu->arr[i-1] = qu->arr[i];
	}
	qu->rear--;
	return val;
}
bool queue_is_empty(queue* qu){
	if(qu->rear == -1) return true;
	else return false;
}
bool queue_is_full(queue* qu){
	if(qu->rear == size-1) return true;
	else return false;
}
int queue_size(queue* qu){
	return (qu->rear + 1);
}
void queue_print(queue* qu){
	int i;
	for(i = 0; i <= qu->rear; i++) printf("%d ", qu->arr[i]);
}




























