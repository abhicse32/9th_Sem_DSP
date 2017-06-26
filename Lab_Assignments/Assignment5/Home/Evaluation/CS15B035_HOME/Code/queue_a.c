#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

queue* queue_new(){
	queue* Q=(queue*)malloc(sizeof(queue));
	Q->arr= (int*) malloc(size*sizeof(int));
	Q->front=0;
	Q->rear=-1;
	return Q;
}

void enqueue(queue* Q,int data){
		if(queue_is_full(Q)==true) return;
		Q->rear=(Q->rear+1);
		Q->arr[Q->rear]=data;
}

int dequeue(queue* Q){
	if(!queue_is_empty(Q)){
		int value=Q->arr[Q->front];
		Q->front=(Q->front+1);
	    return value;
	}
	else return;
}

bool queue_is_empty(queue* Q){
		int number=(Q->rear-Q->front)+1;
		if(number==0) return true;
		else return false;
}

bool queue_is_full(queue* Q){
		int number=((Q->rear) - (Q->front))+1;
		if(number==size) return true;
		else return false;
}

int queue_size(queue* Q){
		int number=(Q->rear-Q->front)+1;
		return number;
}

void queue_print(queue* Q){
	int i;
	for(i=Q->front;i<=Q->rear;i++){
		printf("%d ",Q->arr[i]);
}
}






