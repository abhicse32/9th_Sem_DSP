/*
	Author:G.Kavitha
	Roll No.: CS15B057
	Date: 16/09/16
*/
#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
// Create a new node with next set to NULL
Node* node_new( int data){
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->next=NULL;
	return temp; 
}

// Create an empty list (head shall be NULL)
LList* llist_new(){
	LList* temp=(LList*)malloc(sizeof(LList));
	temp->head=NULL;
	return temp;
}

// Traverse the linked list and return its size
int llist_size( LList* lst ){
	Node* head=lst->head;
	int len=0;
	while(head!=NULL){
		len++;
		head=head->next;
	}
	return len;	
}

// Traverse the linked list and print each element
void llist_print( LList* lst ){
	if(lst==NULL) return;
	Node* head=lst->head;
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
}

//get the element at position @idx
int llist_get( LList* lst, int idx ){
	if(llist_size(lst)-1<idx||idx<0) return INT_MIN;
	Node* head=lst->head;
	while(idx--){	
		head=head->next;
	}
	return head->data;	
}

// Add a new element at the end of the list
void llist_append( LList* lst, int data ){
	Node* head=NULL;	
	if(lst!=NULL)
		head=lst->head;
	Node* temp=node_new(data);
	if(head==NULL){
		lst->head=temp;
	}
	else{		
		while(head->next!=NULL){
			head=head->next;
		}
		head->next=temp;
	}
}
// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int data ){
	Node* head=lst->head;
	Node* temp=node_new(data);
	if(head==NULL){
		lst->head=temp;
	}
	else{
		lst->head=temp;
		temp->next=head;
	}	
}
// Add a new element at the @idx index
void llist_insert( LList* lst, int idx, int data ){
	if(llist_size(lst)<idx||idx<0) return;
	Node* temp=node_new(data);
	Node* head=lst->head;
	if(idx==0){
		lst->head=temp;
		temp->next=head;
	}
	else{
		idx--;
		while(idx--){
			head=head->next;
		}
		Node* save=head->next;
		head->next=temp;
		temp->next=save;
	}
}
// Remove an element from the end of the list
void llist_remove_last( LList* lst ){
	int s=llist_size(lst);	
	if(s==0) return ;
	Node* head=lst->head;
	if(s==1) {
		Node* save=lst->head;
		free(save);
		lst->head=NULL;
		return ;
	}	
	while(head->next->next!=NULL){
		head=head->next;
	}
	Node* save=head->next;	
	head->next=NULL;
	free(save);
}

// Remove an element from the beginning of the list
void llist_remove_first( LList* lst ){
	int s=llist_size(lst);	
	if(s==0) return ;
	Node* save=lst->head;
	lst->head=save->next;	
	free(save);
}

// Remove an element from an arbitrary @idx position in the list
void llist_remove( LList* lst, int idx ){
	if(llist_size(lst)-1<idx||idx<0) return;
	if(idx==0){
		Node* head=lst->head;
		lst->head=head->next;
		free(head);
		return;
	}
	idx--;
	Node* head=lst->head;
	while(idx--){
		head=head->next;
	}
	Node* save=head->next;
	head->next=save->next;
	free(save);
}
