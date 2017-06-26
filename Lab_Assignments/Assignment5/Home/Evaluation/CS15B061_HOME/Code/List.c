/*-----------------------------------------------------------------------------
 *  Title: Program to implement operations on linked list ADT
 *  Author: Harshavardhan.P.K.
 *  Roll No.: CS15B061
 *  Date: 30 August, 2016.	   
 *-----------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include <limits.h>
/*
node_new- creates a new node and returns a poniter to it.
If allcation not possible returns NULL

*/
Node* node_new(int data){
	Node* new = (Node*)malloc(sizeof(Node));
	if(new==NULL) return NULL;
	new->next=NULL;
	new->data=data;
	return new;
}
/*
llist_new - create a new LList and returns pointer to it else returns NULL.
*/
LList* llist_new(){
	LList* lst=(LList*)malloc(sizeof(LList));
	if(lst==NULL) return NULL;
	lst->head=NULL;
	return lst;
}

/*
llist_size - to check size
*/
int llist_size( LList* lst ){
	if(lst->head == NULL) return 0;
	Node* cur = lst->head;
	int ct=0;
	while(cur!=NULL){
		ct++;
		cur=cur->next;
	}
	return ct;
}
/*
llist_print to print a Given LList
Input: LList* lst: the list to be printed.
Output: prints lst and return nothing.
*/
void llist_print(LList* lst){
	if(lst-> head == NULL) return;
	Node *cur = lst->head;
	//Transeverse the lst and prints cur->data till it reaches end
	do{
	printf("%d ",cur->data);
	cur=cur->next;
	}while(cur!=NULL);
}


/*
llist_get : to get a specific elment of index idx in list
Input: LList* lst: the list to find elemet
int idx: input index
Output: Returns the element in given index.
*/
int llist_get( LList* lst, int idx ){
	Node* cur=lst->head;
	if(idx<0) return INT_MIN;//Invalid index
	if(cur==NULL) return INT_MIN;//if head is NULL
	int i;
	for(i=0;i<idx;i++){
		if(cur->next!=NULL)
		cur=cur->next;
		else
		return INT_MIN;// reached end of list
	}
	return (cur->data);
}
/*
function llist_append - append to end of list
Input: LList* lst - the to append to
int data - the elemnt to append
*/
void llist_append( LList* lst, int data ){
	Node* cur=lst->head;
	Node *new_node(int);
	if(cur!=NULL){
	while(cur->next!=NULL){//find end of list
		cur=cur->next;	
	}
	Node* new = node_new(data);//create new node
	cur->next=new;
	cur->next->next=NULL;//insert new node
	}
	else{
		Node** ptr = &(lst->head);
		Node *new = node_new(data);//is initial list is empty
		*ptr = new;
	}
	
}

/*
llist_prepend - to prepend an element to list
Input: LList* lst - the list to prepend to
int data - the data of prepend node
*/
void llist_prepend( LList* lst, int data ){
	
	Node* node_new(int);
	Node* new = node_new(data);//create new node
	new->next=lst->head;//insert new in beginning
	lst->head=new;//change value of head to point to new.
}


/*
llist_insert - to insert given element in index idx
Input: LList* lst - the to append to
int data - the elemnt to append
int idx - index of inserted element

*/
void llist_insert( LList* lst, int idx, int data){
	void llist_prepend(LList*, int);
	if(idx == 0) {llist_prepend(lst,data); return;}//if element is to be prepended
	int ct=0;
	Node* cur=lst->head;
	Node* node_new(int);
	Node* new=node_new(data);//create new node
	for(;ct<idx-1;ct++){
		if(cur!=NULL){
			cur=cur->next;//find the idx-1 node
		}
		else{return;}//if out of bound return from function.
	}
	new->next=cur->next;
	cur->next=new;//insert the node.
}


/*
llist_remove_last - to remove last elemnt of list
Input LList* lst - the list input.
*/
void llist_remove_last( LList* lst){
	Node* cur=lst->head;
	if(lst->head == NULL) return;
	if(cur->next == NULL) {Node* temp=lst->head; lst->head=NULL; free(temp);return;}//if list of length 1.
	
	
	while((cur->next)->next!=NULL){
		cur=cur->next;					// find last - 1 node.
	}
	Node* temp=cur->next;//delete the last node
	cur->next=NULL;
	free(temp);

}


/*
llist_remove_first - to remove first element of list
Input: LList* lst
*/
void llist_remove_first( LList* lst){
	if(lst->head==NULL) return;
	Node* temp=lst->head;
	lst->head=(lst->head)->next;		//change pointer head to head->next
	free(temp);							//delete head
}


/*
llist_remove - to remove element of index idx of list.
Input: LList* lst - the to append to
int idx - index of delete element
*/
void llist_remove( LList* lst, int idx){
	void llist_remove_first(LList*);
	if(idx==0) {llist_remove_first(lst); return;} // if idx =0 call llist_remove_first
	Node * cur=lst->head;
	int i;
	for(i=0;i<idx-1;i++){      						//Transeverse array to idx-1 element
		if(cur!=NULL)
		cur=cur->next;
		else return;
	}
		if(cur!=NULL){								//delete the idx node
		Node* temp= cur->next;
		cur->next=(cur->next)->next;
		free(temp);
	}
	
}
