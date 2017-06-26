#include "List.h"
#include<stdlib.h>
#include <stdio.h>
/*
 * Author:Abhishek Yadav
 * Linked list data structure
 */

// Node for the link list
#include <stdlib.h>

// Create a new node with next set to NULL
Node* node_new( int data)
{
	Node *newnode;
	newnode=(Node*)malloc(sizeof(Node));
		
	newnode->data= data;
	newnode->next=NULL;
	return newnode;
}

// Create an empty list (head shall be NULL)
LList* llist_new()
{
	LList *empty_list=(LList*)malloc(sizeof(LList));
	empty_list->head=NULL;
	return empty_list;
}

// Traverse the linked list and return its size
int llist_size( LList* lst )
{
	if ( !lst->head ) return 0 ; 	
	Node *ptr;
	int count=0;
	ptr=lst->head;
	while(ptr != NULL)
	{
		count++;
	ptr=ptr->next;
	}
	return count;
}

// Traverse the linked list and print each element
void llist_print( LList* lst )
{
	Node *ptr;
	ptr=lst->head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	
	fflush(stdout);
	
}

//get the element at position @idx
int llist_get( LList* lst, int idx )
{
	 Node *ptr;
	ptr=lst->head;
	int i;
	for(i=0;i<idx;i++)
	{
		ptr=ptr->next;
	}
	return (ptr->data);
}

// Add a new element at the end of the list
void llist_append( LList* lst, int data )
{
    Node* temp = node_new (data) ;
	Node *ptr;
	ptr =lst->head;
	
	while( ptr->next !=NULL )
	{
		ptr=ptr->next;
	}
	ptr->next = temp;
	
}

// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int data )
{
	Node *ptr = node_new(data);
	
	ptr->next = lst->head ;	
	lst->head =  ptr;
}
	

// Add a new element at the @idx index
void llist_insert( LList* lst, int idx, int data )
{
	
	if ( llist_size(lst) < idx )  return ;
    if ( idx == 0){
        llist_prepend(lst , data) ;
        return;	
	}
	if ( idx == llist_size(lst) ) {
	    llist_append(lst , data) ;
	    return ;
	}
	
	Node *ptr;
	ptr=lst->head;
	Node *q = node_new(data);
	
	Node *temp ;
	
	int  i;
	
    for(i=0;i<idx;i++)   {
	    temp = ptr ;
	    ptr=ptr->next;
	}

	temp->next = q ;
	q->next = ptr;
}
	
	
	
// Remove an element from the end of the list
void llist_remove_last( LList* lst )
{
    if(lst->head==NULL)
    return;
    if(llist_size(lst)==1)
       {
        lst->head==NULL;
        return ;
        }
	Node *ptr;
	
	ptr=lst->head;
    Node* prev;
	while( ptr->next != NULL)
	{   prev= ptr;
		ptr=ptr->next;
	}
	prev->next=NULL;
}

// Remove an element from the beginning of the list
void llist_remove_first( LList* lst )
{
	lst->head=(lst->head)->next;
}

// Remove an element from an arbitrary @idx position in the list
void llist_remove( LList* lst, int idx )
{
    if(idx==0)
    {
    llist_remove_first(lst);
    }
    else if(llist_size(lst) < idx)
    {
    return ;
    }
    else if(llist_size(lst)== idx)
    {
    llist_remove_last(lst);
    }
    else
    {
	Node *ptr;
	ptr=lst->head;
	int i;
	Node* temp;
	for(i=0;i<idx;i++)
	{   temp=ptr;
		ptr=ptr->next;
	}
	temp->next=ptr->next;
	}
}
