#include "List.h"
#include<stdlib.h>
#include<stdio.h>

Node* node_new(int data){

	Node* new;
	
	new = (Node*)malloc(sizeof(Node));
	
	new->data = data;
	new->next = NULL;
	
	return new;
}

LList* llist_new(){

	LList* lst;
	
	lst = (LList*)malloc(sizeof(LList));	
	
	lst->head = NULL;
	
	return lst;
}

int llist_size( LList* lst ){

	int size = 0;
	
	Node* a = lst->head;
	
	while(a != NULL) {
		a = a->next;
		size++;
	}
		
	return size;
}

void llist_print( LList* lst ){

	Node* a = lst->head;
	
	while(a != NULL){
		printf("%d ",a->data);
		a = a->next;
	}
//	printf("\n");
	
	return ;
}

int llist_get( LList* lst, int idx ){
	int c = 0;
	Node* a = lst->head;
	
	while(c != idx){
		a = a->next;
		c++;	
	}
	
	return a->data;
}

void llist_append( LList* lst, int data ){

	Node* a = lst->head;
	
	Node* new = node_new(data);
	
	if(lst->head ==  NULL){
		lst->head = new;	
		return ;
	}
		
	while(a->next != NULL) a = a->next;
	
	a->next = new;
	
	return ;		
}

void llist_prepend( LList* lst, int data ){

	Node* a = lst->head;	
	
	Node*  new = node_new(data);
	new->next = a;
	
	lst->head = new;
	
	return ;
}

void llist_insert( LList* lst, int f, int data ){
	
	int idx = f+1;
	
	Node* a = lst->head;
	
	Node* new = node_new(data);
	
	int c;
	
	if(idx == 1){
		new->next = (lst->head);	
		lst->head = new;
		return ;
	}
	
	for(c = 1; c < idx-1; c++) a = a->next;
	
	new->next = a->next;
	a->next = new;
	
	
}

void llist_remove_last( LList* lst ){

	Node* a = lst->head;
	if(a != NULL){
	
		if(a->next == NULL) {
			lst->head = NULL;
			return ;
			}
			
		while((a->next)->next != NULL) a = a->next;
	
		Node* prev = a;
		prev->next  = NULL;
	}

	return ;			
}

void llist_remove_first( LList* lst ){
		
	if(lst->head == NULL) return ;
	
	lst->head = (lst->head)->next;
	
	return ;
}

void llist_remove( LList* lst, int f ){

	int idx = f+1;

	Node* a = lst->head;
	
	int c;
	
	if(idx == 1){
		lst->head = a->next;
		return ;
	}
	
	for(c = 1; c < idx-1; c++) a = a->next;
	
	a->next = (a->next)->next; 	
	
	return ;
}
