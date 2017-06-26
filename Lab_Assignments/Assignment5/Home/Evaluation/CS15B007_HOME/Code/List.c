#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


Node* node_new( int dat){
	Node *new;
	new=(Node *)malloc(sizeof(Node));
	new->data=dat;
	new->next=NULL;
	
	return new;
}

LList* llist_new(){
	LList *new;
	new=(LList *)malloc(sizeof(LList));
	new->head=NULL;
	
	return new;
}

int llist_size( LList* lst ){
	
	if (lst->head==NULL){
		return 0;	
	}
	int cnt=1;
	Node* pin=lst->head;
	for(; pin->next != NULL ;){
		cnt++;
		pin=pin->next;
	}
	return cnt;	
}


void llist_print( LList* lst ){
	
	if (lst->head==NULL){
		return;	
	}
	Node* pin=lst->head;
	for(; pin != NULL ;){
		printf("%d ",pin->data);
		pin=pin->next;
	}
	printf("\n");
	return;
}

int llist_get( LList* lst, int idx ){
	
	if (lst->head==NULL){
		return INT_MIN;	
	}
	int cnt=0;
	Node* pin=lst->head;
	for(; pin != NULL ;){
		if(idx==cnt){
			return pin->data; 
		}		
		cnt++;
		pin=pin->next;
	}
	return INT_MIN;	
}

void llist_append( LList* lst, int dat ){


	if(lst->head==NULL){
		Node* new=(Node *)malloc(sizeof(Node));
		lst->head=new;
		new->data=dat;
		new->next=NULL;	
		return;
	}
	
	Node* pin=lst->head;
	for(; pin->next!=NULL ;){
		pin=pin->next;
	}
	
	Node* new=(Node *)malloc(sizeof(Node));
	pin->next=new;
	new->data=dat;
	new->next=NULL;	
	return;	
}

void llist_prepend( LList* lst, int dat ){
		
	if(lst->head==NULL){
		Node* new=(Node *)malloc(sizeof(Node));
		lst->head=new;
		new->data=dat;
		new->next=NULL;	
		return;
	}
	Node* pin=lst->head;

	Node* new=(Node *)malloc(sizeof(Node));
	lst->head=new;
	new->data=dat;
	new->next=pin;
	return;
}

void llist_insert( LList* lst, int idx, int dat ){
	
	if(idx==0){
		llist_prepend( lst, dat );
		return;
	}
	
	int pre = llist_size(lst);
	if(idx>pre){return;}
	
	pre=1;
	Node* pin=lst->head;
	
	for( ; pin->next !=NULL ; ){
		if(pre==idx){
			Node* new=(Node *)malloc(sizeof(Node));
			new->data=dat;
			new->next=pin->next;
			pin->next=new;
			return;				
		}
		pre++;
		pin=pin->next;
	}
	llist_append(lst,dat);
	return;
}


void llist_remove_last( LList* lst ){

	if(lst->head==NULL) return;

	Node* pin=lst->head;
	Node* prev=lst->head;

	for(;pin->next!=NULL;){
		prev=pin;
		pin=pin->next;
	}
	prev->next=NULL;
	return;
}

void llist_remove_first( LList* lst ){

	if(lst->head==NULL) return;
	
	Node* pin=lst->head;

	lst->head=pin->next;
	return;

}

void llist_remove( LList* lst, int idx ){

	if(idx==0){
		llist_remove_first( lst );
		return;
	}
	
	int pre = llist_size(lst);
	if(idx>=pre){return;}
	
	pre=0;
	Node* pin=lst->head;
	Node* prev=lst->head;	

	for( ; pin!=NULL ; ){
		if(pre==idx){
			prev->next=pin->next;
			return;				
		}
		pre++;
		prev=pin;
		pin=pin->next;
	}
}






