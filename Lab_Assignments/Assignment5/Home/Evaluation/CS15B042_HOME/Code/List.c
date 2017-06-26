/*Implements all functions Listed in List.h
Y BHARGAVA SAI CS15B042 29th Aug 2016*/

#include "List.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Create a new node with next set to NULL
Node* node_new( int data){
	Node * new = (Node *)malloc(sizeof(Node));
	new -> data = data;
	new -> next = NULL;
	return new;
}

// Create an empty list (head shall be NULL)
LList* llist_new(){
	LList* new = (LList*)malloc(sizeof(LList));
	new -> head = NULL;	
	return new;
}

// Traverse the linked list and return its size
int llist_size( LList* lst ){
	Node *x = lst -> head;
	if(x == NULL) return 0;
	int count = 1;
	while(x->next != NULL){
		count++;
		x = x->next;
	}
	return count;
}

// Traverse the linked list and print each element
void llist_print( LList* lst ){
	Node * x = lst -> head;
	if(x == NULL) return ;
	while(x != NULL){
		printf("%d ",x -> data);
		x = x -> next;
	}
	fflush(stdout);
	return;
}

//get the element at position @idx
int llist_get( LList* lst, int idx ){
	Node *x = lst -> head;
	if(x == NULL) return INT_MIN;
	int i;	
	for(i = 0;i < idx;i++){
		x = x -> next;
		if(x == NULL) return INT_MIN;
	}
	return x -> data;
}

// Add a new element at the end of the list
void llist_append( LList* lst, int data ){
	Node* new = node_new(data);
	Node *x = lst -> head;
	if(x == NULL) {
		lst -> head = new;
		return;
	}	
	while(x -> next != NULL) x = x -> next;
	x -> next = new;
	return;
}

// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int data ){
	Node* new = node_new(data);
	new -> next = lst -> head;
	lst -> head = new;
	return;
}

// Add a new element at the @idx index
void llist_insert( LList* lst, int idx, int data ){
	Node *x = lst -> head;
	Node* new = node_new(data);
	if(x == NULL && idx == 0){
		lst -> head = new;
		return;
	}	
	if(idx == 0){
		llist_prepend(lst,data);
		return;
	}
	int i;
	for(i = 1;i < idx;i++){
		x = x -> next;
		if(x == NULL) return;
	}
	new -> next = x -> next;
	x -> next = new;
	return;
}

// Remove an element from the end of the list
void llist_remove_last( LList* lst ){
	Node *x = lst -> head;
	if(x == NULL) return;
	if(x -> next == NULL) {
		lst -> head = NULL;
		return;
	}	
	while(x -> next -> next != NULL){
		x = x -> next;
	}		
	x -> next = NULL;
	return;
}

// Remove an element from the beginning of the list
void llist_remove_first( LList* lst ){
	if(lst -> head == NULL) return;
	lst -> head = lst -> head -> next;
	return;
}

// Remove an element from an arbitrary @idx position in the list
void llist_remove( LList* lst, int idx ){
	if(lst -> head == NULL) return;
	if(idx == 0){
		llist_remove_first( lst );
		return;
	}
	Node *x = lst -> head;
	int i;	
	for(i = 1;i < idx;i++){
		x = x -> next;
		if(x == NULL) return;
	}
	if(x -> next == NULL) return;
	x -> next = x -> next -> next;
	return;
}