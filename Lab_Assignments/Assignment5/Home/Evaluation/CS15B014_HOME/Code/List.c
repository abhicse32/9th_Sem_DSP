/*D TEJA VARDHAN REDDY CS15B014  18/9/16*/
/* LIST FUNCTIONS*/
#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include<limits.h>
#include<math.h>
// creates new node
Node* node_new( int data){
	Node *start;
	start=(Node*)malloc(sizeof(Node));
	start->data=data;
	start->next=NULL;
	return start;
}
// creates new list
LList* llist_new(){
	LList *list;
	list=(LList*)malloc(sizeof(LList));
	list->head=NULL;
	return list;
}
// return size of list
int llist_size( LList* lst ){
	int i=0;
	Node*next=lst->head;
	while(next!=NULL){
		i++;
		next=next->next;
	}
	return i;
}
// to print list
void llist_print( LList* lst ){
	//printf("hii  ");
	Node*next=lst->head;
	while(next!=NULL){
		printf("%d ",next->data);
		next=next->next;
	}
	fflush(stdout);
	//printf("\n");
	
}
// to get element at idx
int llist_get( LList* lst, int idx ){
	Node*next=lst->head;
	int i=0;
	while(i!=idx && next!=NULL){
		
		i++;
		next=next->next;
	}
	if(i==idx)
		return next->data;
	else
		return INT_MIN;
	
}	
// to insert at last
void llist_append( LList* lst, int data ){
	Node*node= node_new( data);
	Node*next=lst->head;
	Node*next1;
	next1=lst->head;
	if(next==NULL){
		lst->head=node;
		return ;
	}
	while(next!=NULL){
		next1=next;
		next=next->next;
	}
	
	next1->next=node;
}
// to insert at first
void llist_prepend( LList* lst, int data ){
	Node*node= node_new( data);
	node->next=lst->head;
	lst->head=node;
}
// to insert at idx
void llist_insert( LList* lst, int idx, int data ){
	if(idx==0){
		llist_prepend(  lst, data );
		return;
	}

	Node*node= node_new( data);
	Node*next1;
	Node*next=lst->head;
	int i=0;
	while(i!=idx && next!=NULL ){
		
		i++;
		next1=next;
		next=next->next;
		
	}
	node->next=next;
	if(lst->head!=NULL)
	if(idx==0)
		lst->head=node;
	else if(idx==i)
		next1->next=node;
	
	
}
// to remove at last
void llist_remove_last( LList* lst ){
	Node*next=lst->head;
	Node*next1,*next2;
	if(lst->head!=NULL){
		next2=lst->head;
		next=next->next;
		next1=next;
		if(next==NULL)
			{
				lst->head=NULL;
				return ;
			}
		
		while(next!=NULL){
			next2=next1;
			next1=next;
			next=next->next;
			
		}
		next2->next=NULL;
	}
	
	
}

// to remove first
void llist_remove_first( LList* lst ){
	if(lst->head==NULL)
		return;
	Node*next=lst->head;
	lst->head=next->next;
}
// to remove at idx
void llist_remove( LList* lst, int idx ){
	int i=0;
	Node*next=lst->head;
	Node*next1,*next2;
	next2=lst->head;
	if(lst->head!=NULL){
		
		next=next->next;
		next1=next;
		if(idx==0)
			{
				lst->head=next;
				return ;
			}
		next=next->next;
		next2=next;
		i++;
		while(i!=idx && next!=NULL){
			next2=next1;
			next1=next;
			next=next->next;
			i++;
			
		}
		if(i==idx)
			next2->next=next;
		
	}
}
