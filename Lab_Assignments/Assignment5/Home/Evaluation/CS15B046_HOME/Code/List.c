/*
  To implement various insertion,deletion and creation operations on linked list
  Author:Jahnvi Patel CS15B046
  September 9th, 2016
*/
#include "List.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

// Create a new node with next set to NULL
Node* node_new( int data)
{
	Node* newNode;
	newNode=(Node*) malloc(sizeof(Node));
		if(newNode!=NULL)
		{
			newNode->data=data;
			newNode->next=NULL;
		}
	return newNode;

}

// Create an empty list (head shall be NULL)
LList* llist_new()
{
	LList* newList;
	newList=(LList*) malloc(sizeof(LList));
	if(newList!=NULL)
	newList->head=NULL;
	return newList;
	
}

// Traverse the linked list and return its size
int llist_size( LList* lst )
{
	Node* initHead;
	initHead=lst->head;
	int size=0;
	
	while(lst->head!=NULL)
	{   size++;
		lst->head=lst->head->next;
		

	}
	lst->head=initHead;
	return size;
	
}

// Traverse the linked list and print each element
void llist_print( LList* lst )
{
	Node* initHead;
	initHead=lst->head;

	while(lst->head!=NULL)
		{
			printf("%d ",lst->head->data);
			lst->head=lst->head->next;
		}

	lst->head=initHead;
}

//get the element at position @idx
int llist_get( LList* lst, int idx )
{
	Node* initHead;
	initHead=lst->head;
	int pos=0;
	while(lst->head!=NULL)
	{  
		if(pos==idx)
			{  int num=lst->head->data;
				lst->head=initHead;
			return num;
		}
		lst->head=lst->head->next;
		pos++;

	}
	if(pos<idx)
		{   lst->head=initHead;
			return INT_MIN;
        }
}

// Add a new element at the end of the list
void llist_append( LList* lst, int data )
{
	Node* newNode;
	newNode=node_new(data);
	Node* initHead;
	int flag=0;
	initHead=lst->head;
	if(newNode!=NULL)
	{
		if(lst->head==NULL)
		{
			lst->head=newNode;
			lst->head->next=NULL;
		 	flag=1;
		}
		else
		{	
			while(lst->head->next!=NULL)
			{
				lst->head=lst->head->next;
			}
			lst->head->next=newNode;
		}
	}
		if(flag==0)
			lst->head=initHead;
		
}

// Add a new element at the beginning of the list

void llist_prepend( LList* lst, int data )
{
	Node* newNode;
	newNode=node_new(data);
	if(newNode!=NULL)
	{
		newNode->next=lst->head;
	    lst->head=newNode;

	}
	
}

// Add a new element at the @idx index

void llist_insert( LList* lst, int idx, int data )
{
	Node* newNode;
	newNode=node_new(data);
	Node* initHead;
	initHead=lst->head;
	int pos=0;
	if(newNode!=NULL)
	{   
		if(idx==0)
		 llist_prepend(lst,data); //Same as prepending if idx==0
		else
		{
			while(lst->head!=NULL)
			{  
				if(pos+1==idx)
				{
					newNode->next=lst->head->next;
					lst->head->next=newNode;
					break;
				}
				lst->head=lst->head->next;
				pos++;
			}

		lst->head=initHead;
		if(pos==idx)
			llist_append(lst,data); 
		/*Works as append if idx=size of list*/
		}
	}
	
}

// Remove an element from the end of the list

void llist_remove_last( LList* lst )

{ 	Node* initHead;
	Node* prev;
	prev=(Node*) malloc(sizeof(Node));
	initHead=lst->head;
	int flag=0;
	if(lst->head!=NULL)
		if(lst->head->next==NULL)
			flag=1;
 if(lst->head!=NULL )
	{
	while(lst->head->next!=NULL)
		{  
			prev=lst->head;
			lst->head=lst->head->next;
		}
			
				Node* temp;
				temp=lst->head;
				prev->next=NULL;
				lst->head=NULL;
				free(temp);
			
		
	}

       if(flag==0)
 		lst->head=initHead;

}

// Remove an element from the beginning of the list

void llist_remove_first( LList* lst )
{
	
	if(lst->head!=NULL)
	{
		if(lst->head->next==NULL)
 		{
 				Node* temp;
				temp=lst->head;
				lst->head=NULL;
				free(temp);
 		}
 		else
 		{
 			Node* temp;
 			temp=lst->head;
 			lst->head=lst->head->next;
 			free(temp);
 		}

	}
}

// Remove an element from an arbitrary @idx position in the list

void llist_remove( LList* lst, int idx )
{
	Node* initHead;
	initHead=lst->head;
	int flag=0;
	int pos=0;
	if(lst->head!=NULL)
	{
	if(idx==0 )
		llist_remove_first(lst);//Removing first elm
	else if(lst->head->next!=NULL)
	{	flag=1;
		while(1)
		{  
			if(pos+1==idx)
			{
				Node* temp;
 			    	temp=lst->head->next;
 				lst->head->next=lst->head->next->next;
 				free(temp);
			}
			if(lst->head->next==NULL)
				break;
			lst->head=lst->head->next;
			pos++;

		}
	}
	if(flag==1)
	lst->head=initHead;
}
}
