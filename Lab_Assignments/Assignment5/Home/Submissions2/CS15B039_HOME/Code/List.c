#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include<ctype.h>
#include<limits.h>

// Create a new node with next set to NULL
Node* node_new( int data){
	
	Node *node;
	node = (Node *)malloc( sizeof(Node));
	if (node==NULL)
		printf("Malloc Error");
	else{
		node->data = data;
		node->next = NULL;
	}
	return node;
}

// Create an empty list (head shall be NULL)
LList* llist_new(){
	
	LList * lst;
	lst = (LList *)malloc(sizeof(LList));
	lst->head = NULL;
	return lst;
}

// Traverse the linked list and return its size
int llist_size( LList* lst ){

	Node * cur;
	int count = 0;
	cur = lst->head;
	while(cur !=NULL){
		count++;
		cur=cur->next;
		}
	return count;
}

// Traverse the linked list and print each element
void llist_print( LList* lst ){

	Node * cur;
	cur = lst->head;
	while(cur!=NULL){
		printf("%d ", cur->data);
		cur=cur->next;
		}
	//printf("\n");
}		

//get the element at position @idx
int llist_get( LList* lst, int idx ){

	int n, count;
	count = 0;
	Node * cur;
	
	n=llist_size(lst);
	cur = lst->head;
	if(idx>=0 && idx<n){
		while(count!=idx){
			cur = cur->next;
			count ++;
			}
		return cur->data;
	}
	else
		return (INT_MIN);
	
}

// Add a new element at the end of the list
void llist_append( LList* lst, int data){

	Node *cur;
	Node *new_node;
	new_node = node_new( data);
	cur=lst->head;
	if (lst->head != NULL){
		while(cur->next != NULL){
			cur=cur->next;
		}
		cur->next = new_node;
	}
	else 
		lst->head = new_node;
}

// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int data ){

	Node * new_node;
	new_node = node_new(data);
	new_node->next = lst->head;
	lst->head = new_node;
}

// Add a new element at the @idx index
void llist_insert( LList* lst, int idx, int data){

	int n, count;
	Node * cur;
	Node * new_node;
	new_node = node_new(data);
	
	n = llist_size(lst);
	count = 1;

	if (lst->head!=NULL){
		cur = lst->head;
		if(idx>=0 && idx<n){
			if(idx!=0){
				while(count!=idx){
					cur = cur->next;
					count ++;	
				}
			new_node->next = cur->next;
			cur->next = new_node;
			}
			else
				llist_prepend(lst, data);
		}
		if(idx==n)	
			llist_append(lst, data);
		
		
	}
	else{
		lst->head = new_node;
		new_node->next = NULL;
	}
}


// Remove an element from the end of the list
void llist_remove_last( LList* lst ){

	Node * cur1, * cur2;
	cur1 = lst->head;
	
	if(cur1 != NULL){
		cur2 = cur1->next;
		if(cur2 != NULL){
			while(cur2->next != NULL){
				cur1 = cur1->next;
				cur2=cur2->next;
				}
			cur1->next = NULL;
			free(cur2);
			}
			
		else{
			lst->head=NULL;
			free(cur1);
			}
	}
}	

// Remove an element from the beginning of the list
void llist_remove_first( LList* lst ){
	Node * cur1, * cur2;
	cur1 = lst->head;
	
	if(cur1 != NULL){
		lst->head = (lst->head)->next;
		free(cur1);
		}
}

// Remove an element from an arbitrary @idx position in the list
void llist_remove( LList* lst, int idx ){

	Node *cur, *p;
	int count = 1;
	int n;
	
	n = llist_size(lst);
	
	cur = lst->head;
	if(idx>=0 && idx<n){
		if(cur!=NULL){
			if(idx!=0){
				while(count!=idx){
					cur = cur->next;
					count ++;
					}
				p = cur->next;
				cur->next = (cur->next)->next;
				free(p);
			}
			else{
				lst->head=(lst->head)->next;
				free(cur);
			}
		}
	}
}
