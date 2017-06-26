#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
Node* node_new(int data)
{
	Node *new;
    new = (Node*)malloc(sizeof(Node));
	new->data=data;
	new->next= NULL;
	return new;
}

LList* llist_new()
{
	LList *list;
    list = (LList*)malloc(sizeof(LList));
	list->head= NULL;
	return list;
}

int llist_size( LList* lst )
{
	int length=0;
	Node* current;
   	current = (Node*)malloc(sizeof(Node));
	current=lst->head;
	while(current!=NULL)
	{
		length++;
		current=current->next;
	}
	free(current);
	return length;
}

void llist_print( LList* lst )
{
	Node* current;
	current=(Node*)malloc(sizeof(Node));
	current=lst->head;
	while(current!=NULL)
	{
		printf("%d ", current->data);
		current=current->next;
	}
	fflush(stdout);
	free(current);
	return;
}

int llist_get( LList* lst, int idx )
{
	int i=0;
	Node* current;
   	current = (Node*)malloc(sizeof(Node));
	current=lst->head;
	while(i!=idx)
	{
		i++;
		current=current->next;
	}
	return (current->data);
}

void llist_append( LList* lst, int data )
{
	Node* current;
	Node* new;
   	current = (Node*)malloc(sizeof(Node));
	current = lst->head;
	new = node_new(data);
	if(current==NULL)
	{
		lst->head=new;
		return;
	}
	while(current->next!=NULL)
	{
		current=current->next;
	}
	current->next=new;
	return;     
}

void llist_prepend( LList* lst, int data )
{
	Node* current;
	Node* new;
    current = (Node*)malloc(sizeof(Node));
	current = lst->head;
	new = node_new(data);
	new->next=current;
	lst->head=new;
	return;
}

void llist_insert( LList* lst, int idx, int data )
{
   	idx = idx+1;
   	int i;
   	Node* current;
   	current = lst->head;
   	Node* new = node_new(data);
   	if(idx == 1)
   	{
       new->next = (lst->head);   
       lst->head = new;
       return ;
   	}   
   	for(i=1; i<idx-1; i++)
   	{
		current = current->next;
   	}
    new->next = current->next;
    current->next = new;
   	return;   
}

void llist_remove_last( LList* lst )
{
	Node* current;
	Node* previous;
	current=lst->head;
	if(current->next==NULL)	return;
	while((current->next)!=NULL)
	{
		previous=current;
		current=current->next;
	}
	previous->next=NULL;
	return;	         
}

void llist_remove_first( LList* lst )
{
	if(lst->head==NULL)	return;
	lst->head=(lst->head)->next;
	return; 
}

void llist_remove( LList* lst, int idx )
{
	Node* current;
	Node* previous;
	int i;
	current=lst->head;
	if(idx==0)
	{
		llist_remove_first( lst );
		return;
	}
	for(i=0;i<idx;i++)
	{
		previous=current;
		current=current->next;	
	}
	if((current->next)==NULL)
	{
		llist_remove_last( lst );
		return;
	}
	previous->next=current->next;

	return;
}

