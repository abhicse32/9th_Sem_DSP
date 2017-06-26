#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

queue* queue_new(){
	queue *new=(queue *)malloc(sizeof(queue));
	new->arr=(int *)malloc(sizeof(int) * (size));
	new->front=0;
	new->rear=0;

	return new;
}

bool queue_is_empty(queue* q){
	int count;
	count=(q->rear-q->front);

	if(count==0) return true;
	else return false;
}

bool queue_is_full(queue* q){
	int count;
	count=(q->rear-q->front+1+size)%size;

	if(count==0) return true;
	else return false;

}

void enqueue(queue* q, int elm){
	if(!queue_is_full(q)){
		q->rear++;
		q->arr[q->rear-1]=elm;
		if(q->rear==size){
			q->rear=0;
		}
	}
	return;
}

int dequeue(queue* q){
	int x;
	if(!queue_is_empty(q)){
		x=q->arr[q->front];
		q->front++;
	}
	return x;
}

int queue_size(queue* q){
	int count;
	if(q->rear < q->front)
		count=q->rear - q->front + size;
	else count = q->rear - q->front;

	return count;
}

void queue_print(queue* q){
	int i=q->front;

	for(;i< q->rear ; i++){
		printf("%d ",q->arr[i]);
	}
}