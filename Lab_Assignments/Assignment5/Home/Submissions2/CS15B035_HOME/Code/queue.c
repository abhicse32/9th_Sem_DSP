#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include"List.h"
#include<limits.h>

queue* queue_new(){
	queue* Q=(queue*)malloc(sizeof(queue));
	Q->front=llist_new();
	Q->rear=llist_new();
	return Q;
}

void enqueue(queue* Q,int data){
	if(Q->front->head==NULL){
		Node* new=node_new(data);
		Q->front->head=new;
		Q->rear->head=new;
		//printf("%d\n",data);
	}
	else{
			Node* new=node_new(data);
			Q->rear->head->next=new;
			Q->rear->head=new;
			//printf("%d\n",data);
	}		
}

int dequeue(queue* Q){
	if(!queue_is_empty(Q)){
		int item=Q->front->head->data;
		Node* temp=Q->front->head;
		if(Q->front->head->next == NULL) Q->rear->head=NULL;
		Q->front->head=Q->front->head->next;
		free(temp);
		return item;	
	}
	else return INT_MIN;
}

bool queue_is_empty(queue* Q){
	if(Q->front->head==NULL) return true;
	else return false;	
}

int queue_size(queue* Q){
	int size=llist_size(Q->front);
	return size;
}

void queue_print(queue* Q){
	llist_print(Q->front);
}

