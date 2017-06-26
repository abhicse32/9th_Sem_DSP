//Author -Sarthak pandey
//QUEUE IMPLEMENTATIONS

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new()
{
	queue *new;
	new=(queue *)malloc(sizeof(queue));
	new->front=llist_new();
	new->rear=llist_new();
	return new;
}

void enqueue(queue* q, int data)                                                                      //TO ENQUEUE , ADD ELEMENT AT LAST
{
	LList *llist;
	llist=q->front;
	llist_append(llist,data);
}

int dequeue(queue* q)                                                                                 //TO DEQUEUE , TAKE ELEMENT FROM FIRST
{
	LList *llist;
	int i;
	llist=q->front;
	i=llist->head->data;
	llist_remove_first(llist);
	return i;
}

bool queue_is_empty(queue* q)                                                                         //CHECKS IF STRING IS EMPTY
{
	LList *llist;
	llist=q->front;
	if (llist_size(llist)==0)
		return true;
	else
		return false;
}

int queue_size(queue* q)                                                                              //RETURNS SIZE
{
	LList *llist;
	llist=q->front;
	return llist_size(llist);
}

void queue_print(queue* q)                                                                            //PRINTS QUEUE
{
	LList *llist;
	llist=q->front;
	llist_print(llist);
}
