#include "List.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


Node* node_new(int data)
{
	Node *newnode;
	newnode=(Node*)malloc(sizeof(Node));	
	newnode->data = data;
	newnode->next = NULL;
	
	return newnode;
}


LList* llist_new()
{
	LList *newhead;
	newhead=(LList *)malloc(sizeof(LList));
	newhead->head = NULL;
	
	return newhead;
}


int llist_size( LList* lst )
{
	Node *current;
	current=(Node *)malloc(sizeof(Node));		
	current->next = lst->head;
	
	int length=0;
	while(current->next!=NULL)
	{
		length++;
		current = current->next;
	}
	return length;

}


void llist_print( LList* lst )
{
	Node *current;
	current=(Node *)malloc(sizeof(Node));		
	current->next = lst->head;
	
	while(current->next!=NULL)
	{
		current = current->next;	
		printf("%d ", current->data);
	}
	//printf("\n");
}


int llist_get( LList* lst, int idx )
{
	Node *current;
	current=(Node *)malloc(sizeof(Node));		
	current->next = lst->head;
	
	if(current->next == NULL || idx>(llist_size(lst)-1))
		return INT_MIN;
		
	int i;
	for(i=0; i<=idx; i++)
		current = current->next;		
	return current->data;
}


void llist_append( LList* lst, int data )
{
	Node *current;
	current=(Node *)malloc(sizeof(Node));		
	current->next = lst->head;
	Node *newnode;
	newnode=(Node *)malloc(sizeof(Node));	
	newnode->data = data;
	newnode->next = NULL;
	
	if(lst->head==NULL)
		lst->head = newnode;
	else
	{
		while(current->next!=NULL)
			current = current->next;
		current->next = newnode;
	}
}


void llist_prepend( LList* lst, int data )
{
	Node *newnode;
	newnode=(Node *)malloc(sizeof(Node));		
	newnode->data = data;
	newnode->next = lst->head;	
	lst->head = newnode;
}


void llist_insert( LList* lst, int idx, int data )
{
	Node *current;
	current=(Node *)malloc(sizeof(Node));		
	current->next = lst->head;	
	Node *newnode;
	newnode=(Node *)malloc(sizeof(Node));		
	newnode->data = data;
	
	int i;
	if(idx==0)
	{
		if(lst->head==NULL)
			lst->head=newnode;
		else
		{
			newnode->next=lst->head;
			lst->head=newnode;
		}
	}
	else if(lst->head!=NULL)
	{
		for(i=0; i<idx; i++)
			current = current->next;
		newnode->next = current->next;
		current->next= newnode;
	}
}


void llist_remove_last( LList* lst )
{
	Node *current;
	current=(Node *)malloc(sizeof(Node));		
	current->next = lst->head;
	
	if(lst->head!=NULL)
	{
		
		if(current->next->next==NULL)
			lst->head=NULL;
		else
		{
			while(current->next->next!=NULL)
				current = current->next;
			current->next=NULL;
		}
	}
}


void llist_remove_first( LList* lst )
{
	lst->head=lst->head->next;
}


void llist_remove( LList* lst, int idx )
{
	Node *current;
	current=(Node *)malloc(sizeof(Node));		
	current->next = lst->head;
	
	int i;
	if(lst->head!=NULL)
	{
		
		if(idx==0)
			lst->head=lst->head->next;	
		else
		{
			for(i=0; i<idx; i++)
				current = current->next;
			current->next = current->next->next;
		}
	}
}
	
		
	
	










			
	
	