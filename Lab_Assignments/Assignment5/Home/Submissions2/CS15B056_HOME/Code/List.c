/*VARIOUS LIST FUNCTION IMPLEMENTATIONS
AUTHOR -SARTHAK PANDEY CS15B056
*/
#include "List.h"
#include <stdio.h>
#include <stdlib.h>


Node* node_new( int data)
{
	Node *node;
	node=(Node *)malloc(sizeof (Node));
	node->data=data;
	node->next=NULL;
	return node;
}

LList* llist_new()
{
	LList *llist;
	llist=(LList *)malloc (sizeof (LList));              //MALLOC ALLOCATES MEMORY TO LList POINTER
	llist->head=NULL;                                    //makes the head pointer null
	return llist;
}

int llist_size( LList* lst )
{
	int i=0;
	Node *curr;
	curr=lst->head;
	for(;curr!=NULL;)
	{
		i++;
		curr=curr->next;                          //stops when null is reached
	}
	return i;
}

void llist_print( LList* lst )
{
	if (lst->head==NULL)
		;
	else
	{
	Node *curr;
	curr=lst->head;
	for (;curr!=NULL;curr=curr->next)
		printf("%d ",curr->data);                   //prints elements till list end is reached
	
	}
}

int llist_get( LList* lst, int idx )
{
	int i;
	Node *curr;
	curr=lst->head;
	if (idx>llist_size(lst)-1)
	return -1;
	curr=lst->head;
	for (i=0;i<idx;i++)
		curr=curr->next;                            //finds the element at idx index
	return curr->data;
}

void llist_append( LList* lst, int data )
{
	Node *curr;
	curr=lst->head;
	if (curr==NULL)
		lst->head=node_new(data);                   //if initially no element present
	else
	{	
	for (;curr->next!=NULL;curr=curr->next)              //places an element at list end
		;
	curr->next=node_new(data);
	}
}

void llist_prepend( LList* lst, int data )                   //places an element in the front
{
	Node *new;
	new=node_new(data);
	new->next=lst->head;
	lst->head=new;
}

void llist_insert( LList* lst, int idx, int data )             //inserts element at idx index
{
	Node *curr;
	int i;
	Node *new;
	new=node_new(data);
	curr=lst->head;
	if (idx==llist_size(lst))
		llist_append (lst,data);                      //if insertion point is at the end
	else if (idx>llist_size(lst))
	 return;
	else if (idx==0)
		llist_prepend(lst,data);                    // if insertion point is the start
	else {
		
	for(i=0;i<idx-1;i++)
		curr=curr->next;
	new->next=curr->next;
	curr->next=new;
	}
}
void llist_remove_last( LList* lst )                           //removes an element from last
{
	Node *curr;
	
	Node *a;
	curr=lst->head;
	if (curr==NULL)
	 return ;
	else if (curr->next==NULL)
		lst->head==NULL;
	else 
	{
	for (;(curr->next)->next!=NULL;curr=curr->next)
	;
	a=curr->next;	
	curr->next=NULL;
	free (a);
	}
}

void llist_remove_first( LList* lst )                            //removes first element
{
	Node *curr;
	curr=lst->head;
	if (curr==NULL)
		;
	lst->head=curr->next;
	free (curr);
}
void llist_remove( LList* lst, int idx )                         //removes element at index i
{
	if (idx>llist_size(lst)-1)
		return;
	Node *curr;
	int i;
	Node *a;
	curr=lst->head;
	if (idx==0)
		llist_remove_first(lst);
	else if (idx==llist_size(lst)-1)
		llist_remove_last(lst);
	else
	{
		for (i=0;i<idx-1;i++)
			curr=curr->next;
		a=curr->next;
		curr->next=curr->next->next;
		free (a);
	}
}

			



	
































	













































	


