#include "List.h"
#include<stdio.h>
#include<stdlib.h>

LList* llist_new(){

	LList* lst = (LList*)malloc(sizeof(LList));		//Allocates space for the LList in the heap and assign NULL to the head
	lst->head = NULL;
	
	return lst;
}

Node* node_new( int data1, int data2){

	Node* new;
	
	new = (Node*)malloc(sizeof(Node));
	
	new->col_ind = data1;
	new->val = data2;	
	new->next = NULL;
	
	return new;
}

int llist_size( LList* lst ){

	int size = 0;
	
	Node* a = lst->head;
	
	while(a != NULL) {				//Counter keeps incrementing till the final element is reached i.e. next = NULL
		a = a->next;
		size++;
	}
		
	return size;

}

void llist_print( LList* lst){

	Node* a = lst->head;
	
	if(a == NULL) return;	
		
	while(a != NULL){					//Goes in the loop till the final element is reached and keeps printing the value
		printf("%d ",a->val);
		a = a->next;
	}
	printf("\n");
	
	return ;
}

Node* llist_get( LList* lst, int idx ){		//Goes till the (i-1)th element and then retrieves the ith value

	int c = 0;
	Node* a = lst->head;
	
	if(a == NULL) return NULL;
	
	if(idx >= llist_size(lst)) return NULL;
	
	while(c != idx){
		a = a->next;
		c++;	
	}
	
	return a;
}

void llist_append( LList* lst, int col, int data){

	Node* a = lst->head;
	
	Node* new = node_new(col,data);
	
	if(lst->head ==  NULL){				//When the list is empty
		lst->head = new;	
		return ;
	}
		
	while(a->next != NULL) a = a->next;		//Reaches the final element and sets the next to the new node address
	
	a->next = new;
	
	return ;		

}

void llist_prepend( LList* lst, int col, int data){

	Node* a = lst->head;	
	
	Node*  new = node_new(col,data);		//Gives the head of the list the address of the new node and the next of the 
	new->next = a;					//new node the address of the previous first element			
	
	lst->head = new;
	
	return ;
}

void llist_insert( LList* lst, int idx, int col, int data){

	Node* a = lst->head;
	
	Node* new = node_new(col,data);		//give the next of (i-1)th node to the address of new node 
								//and the next of th new node to the address of the previous ith node	
	int c;
	
	if(idx == 0){
		new->next = (lst->head);	
		lst->head = new;
		return ;
	}
	
	for(c = 1; c < idx; c++) a = a->next;
	
	new->next = a->next;
	a->next = new;

	return ;
}
