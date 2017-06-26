/*-----------------------------------------------------------------------------
 *  Title: Program to implement operations on linked list ADT
 *  Author: GIRIDHAR S
 *  Roll No.: CS15B016
 *  Date: 13 September, 2016.	   
 *-----------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include <limits.h>


//node_new- creates a new node and returns a poniter to it.
//If allcation not possible returns NULL

Node* node_new(int data){
	Node* node;
	node=(Node*)malloc(sizeof(struct Node_));
	if(node==NULL){
//		printf("eror! out of memory!!");
	}
	else{	
	node->data=data;
	node->next=NULL;}
	return node;
}


//llist_new - create a new LList and returns pointer to it else returns NULL.

LList* llist_new(){
	LList *llist;
	llist=(LList*)malloc(sizeof(LList));

	if(llist==NULL){
//		printf("error! out of memory!!");
	}
	else{	
	llist->head=NULL;}
	return llist;
}


//llist_size - to return size of Linked List ADT

int llist_size( LList* lst ){
//	printf("here ");
	if(lst->head==NULL)
		return 0;
	else{
		int count=1;
		Node* tmp;
		tmp=lst->head;
		while(tmp->next!=NULL){
		//	printf("to infinity ");
			count++;
			tmp=tmp->next;
			
			}
		return count;
	}
}
/*
llist_print to print a Given LList
Input: LList* lst: the list to be printed.
Output: prints lst and return nothing.
*/
void llist_print(LList* lst){
	if(lst->head==NULL);
	//	printf("list is empty!!!");
	else{
		Node* cur=lst->head;
		while(1){
			printf("%d ",cur->data);
			if(cur->next!=NULL){
				cur=cur->next;
			}
			else
				break;
		}
	}
//printf("\n");
}


/*
llist_get : to get the element of index idx in list
Input: LList* lst: the list to find element
int idx: index
Output: Returns the element in given index.
*/
int llist_get( LList* lst, int idx ){

	int length=llist_size(lst);
	if((idx>=length)||(idx<0))
		return INT_MIN;
	else{
		int i=0;
		Node* cur=lst->head;
		while(i!=idx){
			cur=cur->next;
			i++;
		}

		return cur->data;
	}
}
/*
llist_append - append to end of list
Input: LList* lst - the list to append to
int data - the value that data variable of the node to be appended has
*/
void llist_append( LList* lst, int data ){

	if(lst->head==NULL){
		Node* target=node_new(data);
		lst->head=target;
	}
	

	else{
		Node* cur=lst->head;
		Node* target=node_new(data);
		while(cur->next!=NULL){
			cur=cur->next;
		}
		cur->next=target;
	}
}

/*
llist_prepend - to prepend an element to list
Input: LList* lst - the list to prepend to
int data - the value that data variable of the node to be prepended has
*/
void llist_prepend( LList* lst, int data ){
		
	if(lst->head==NULL){
		Node* target=node_new(data);
		lst->head=target;
	}
	else{
		Node* target=node_new(data);
		target->next=lst->head;
		lst->head=target;
	}
}


/*
llist_insert - to insert given element in index idx
Input: LList* lst - the list to append to
int data - the value that data variable of the node to be prepended has
int idx - index of inserted element

*/
void llist_insert( LList* lst, int idx, int data){

	int length=llist_size(lst);
	if((idx>length)||(idx<0));
	//	printf("Error");

	else if(idx==0){
		Node* target=node_new(data);
		target->next=lst->head;
		lst->head=target;}

	else{
		int i=1;
		Node* cur=lst->head;
		Node* target=node_new(data);
		while(i!=idx){
			cur=cur->next;
			i++;
		}

		target->next=cur->next;
		cur->next=target;
	}
}


/*
llist_remove_last - to remove last elemnt of list
Input LList* lst - the list input.
*/
void llist_remove_last( LList* lst){
	if(lst->head==NULL){
	//	printf("List is empty");
	}
	
	else if(lst->head->next==NULL){
		lst->head=NULL;
	}
	else{
		Node* cur=lst->head;
		Node* nx=cur->next;
		while(nx->next!=NULL){
			cur=cur->next;
			nx=nx->next;
		}
		cur->next=NULL;
	}
}


/*
llist_remove_first - to remove first element of list
Input: LList* lst
*/
void llist_remove_first( LList* lst){
	if(lst->head==NULL){
	//	printf("List is empty");
	}
	
	else if(lst->head->next==NULL){
		lst->head=NULL;
	}
	else{
		Node *tmp;
		tmp=lst->head;
		lst->head=lst->head->next;
	}

}

/*
llist_remove - to remove element of index idx of list.
Input: LList* lst - the List to append to
int idx - index of delete element
*/
void llist_remove( LList* lst, int idx){

	int length=llist_size(lst);
	if((idx>length)||(idx<0));
	//	printf("Error");
	
	if(idx==0){
		Node* temp;
		temp=lst->head;
		lst->head=lst->head->next;
	}

	else{
		int i=1;
		Node* cur=lst->head;
		Node* tmp;
		while(i!=idx){
			cur=cur->next;
			i++;
		}

		tmp=cur->next;
		cur->next=tmp->next;
		//delete tmp
	}
}
