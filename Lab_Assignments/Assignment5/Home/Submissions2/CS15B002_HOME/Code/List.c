#include "List.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
Node* node_new( int data)
{
	Node* new;
	new = (Node*)malloc(sizeof(Node)); 
	new->data = data;
	new->next = NULL;
	return new;
}
LList* llist_new()
{
	LList* new;
	new = (LList*)malloc(sizeof(LList)); 
	new->head = NULL ;
	return new;
}
int llist_size( LList* lst)
{
	int c=0;
	Node* b;
	b = lst->head;
	while(b != NULL)
	{
		c++;
		b = b->next;
	}
	return c;
}
void llist_print( LList* lst )
{
	Node* c;
	c = lst->head;
	while(c != NULL)
	{
		printf("%d ",c->data);
		c = c->next;
	}
}
int llist_get( LList* lst, int idx )
{
	int c=0;
	Node* b;
	b = lst->head;
	while(b != NULL)
	{
		if(c==idx)
		return b->data;
		c++;
		b = b->next;
	}
	return INT_MIN ;
}
void llist_append( LList* lst, int data )
{
	Node* b;
	Node* c;
	b = (Node*)malloc(sizeof(Node));  
	b->data = data;
	b->next = NULL;
	c = lst->head;
	if(c == NULL) lst->head=b;
	else
	{
		while(c->next != NULL)
		{
			c = c->next;
		}
		c->next = b;
	}
}
void llist_prepend( LList* lst, int data )
{
	Node* b;
	b = (Node*)malloc(sizeof(Node)); 
	b->data = data;
	b->next = (lst->head);
	(lst->head) = b;
}
void llist_insert( LList* lst, int idx, int data )
{	
	Node* b;
	Node* c;
	b = (Node*)malloc(sizeof(Node));  
	int i;
	b->data = data;
	c = lst->head;
	if(idx==0)
	{
		b->next = c;
		(lst->head) = b;
	}
	else
	{
		for(i=0;c != NULL;i++)
		{ 
			if(i==idx-1) break;
			else c = c->next;
		}
		b->next = c->next;
		c->next = b;
	}
}
void llist_remove_last( LList* lst )
{
	Node* c; 
	c = lst->head;
	while((c->next)->next != NULL)
	{
		c = c->next;
	}
	c->next = NULL;
}
void llist_remove_first( LList* lst )
{
	lst->head = (lst->head)->next ;
}
void llist_remove( LList* lst, int idx )
{
	Node* c;
	c = lst->head;
	int i;
	if(idx==0)
	{
		lst->head = (lst->head)->next ;
	}
	else
	{
		for(i=0;c!= NULL;i++)
		{
			if(i==idx-1) break;
			else c = c->next;
		}
		c->next = (c->next)->next ;
	}
}
