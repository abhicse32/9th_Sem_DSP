#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new(){
	queue *new=(queue *)malloc(sizeof(queue));
	new->front=llist_new();
	new->rear=llist_new();

	return new;

}

void enqueue(queue* q, int elm){
	if((q->front)->head == NULL){
		(q->front)->head=node_new(elm);
		(q->rear)->head=(q->front)->head;
	}
	else{
		Node *temp=(q->rear)->head;
		(q->rear)->head=node_new(elm);
		temp->next=(q->rear)->head;
	}
	return;
}

int dequeue(queue* q){
	int x=queue_size(q);
	if(x==0)	return -1;
	else if(x==1){
		int a=((q->front)->head)->data;
		(q->rear)->head=NULL;
		(q->front)->head=NULL;	
		return a;
	} 
	Node *pin=(q->front)->head;
	int a=pin->data;
	(q->front)->head=pin->next;
	return a;
}

int queue_size(queue* q){
	return llist_size(q->front);
}

bool queue_is_empty(queue* q){
	return ((q->front)->head == NULL);
}

void queue_print(queue* q){
	LList *lst=q->front;
	if (lst->head==NULL){
		return;	
	}
	Node* pin=lst->head;
	for(; pin != NULL ;){
		printf("%d ",pin->data);
		pin=pin->next;
	}
	return;
}