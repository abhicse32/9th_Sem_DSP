#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

stack* stack_new(){
	stack *new=(stack *)malloc(sizeof(stack));
	new->top=llist_new();

	return new;
}

void stack_push(stack* s, int elm){
	llist_prepend(s->top,elm);
	return;
}

int stack_pop(stack* s){
	
	LList *lst=s->top;
	if(lst->head==NULL) return INT_MIN;
	
	Node* pin=lst->head;

	lst->head=pin->next;
	return pin->data;
}

bool stack_is_empty(stack* s){
	LList *lst=s->top;

	if(lst->head==NULL){
		return true;
	}
	else return false;
}

int stack_size(stack* s){
	return llist_size(s->top);
}

void stack_print(stack* s){
	LList *lst=s->top;
	Node* q=lst->head;
	
	for(; q!=NULL ;){
		printf("%d ",q->data);
		q=q->next;
	}
}
