//List.c by Raghavan S CS15B034 Home Assignment 5
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -2147483648
// Create a new Node with next set to NULL
Node* node_new( int data)
{
	Node *n;
	n = (Node*)malloc(sizeof(Node));
	if(n==NULL)
	{
		printf("overflow");
		return NULL;
	}
	n->next=NULL;
	n->data=data;
	return n;
}

// Create an empty list (head shall be NULL)
LList* 	llist_new()
{
	LList *l=(LList*)malloc(sizeof(LList));
	l->head=NULL;
	return l;
}

//Creates new node in an empty LL
void llist_crfirstnode(LList *l,int data)
{
	Node *n = node_new(data);
	l->head=n;
}

// Traverse the linked list and return its size
int llist_size( LList* lst )
{
	int i=0;
	if(lst->head==NULL)
		return 0;
	else
	{
		Node *n;
		for(n=lst->head;n!=NULL;n=n->next)
		{
			i++;
		}
		free(n);
		return i;
	}
}

// Traverse the linked list and print each element
void llist_print( LList* lst )
{
	if(lst->head==NULL)
	{
		return;
	}
	else
	{
		Node *n=(Node*)malloc(sizeof(Node));
		for(n=lst->head;n!=NULL;n=n->next)
		{
			printf("%d ",n->data);
		}
		free(n);
	}
}

//get the element at position @idx
int llist_get( LList* lst, int idx )
{
	int t;
	if(idx<0||lst->head==NULL)
		return INT_MIN;
	int i=0;
	Node *n;
	n=lst->head;
	while(i<idx&&n!=NULL)
	{
		n=n->next;
		i++;
	}
	if(n==NULL)
		return INT_MIN;
	else
		return(n->data);
}

// Add a new element at the end of the list
void llist_append( LList* lst, int data )
{
	if(lst->head==NULL)
	{
		llist_crfirstnode(lst,data);
		return;
	}
	Node *n;
	n=lst->head;
	while(n->next!=NULL)
	{
		n=n->next;
	}
	Node *n2=(Node*)malloc(sizeof(Node));
	n->next=n2;
	n2->data=data;
	n2->next=NULL;
}
// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int data )
{
	Node *n=(Node*)malloc(sizeof(Node));
	n->data=data;
	n->next=NULL;
	if(lst->head==NULL)
	{
		llist_crfirstnode(lst,data);
		return;
	}
	else
	{
		n->next=lst->head;
		lst->head=n;
	}
}

// Add a new element at the @idx index
void llist_insert( LList* lst, int idx, int data )
{
	if(idx<0||idx>llist_size(lst))
		return;
	if(idx==0)
	{
		llist_prepend(lst,data);
		return;
	}
	int i=0;
	Node *n;
	n=lst->head;
	while(i<idx-1&&n!=NULL)
	{
		n=n->next;
		i++;
	}
	Node *n2=(Node*)malloc(sizeof(Node));
	n2->next=n->next;
	n2->data=data;
	n->next=n2;
}

// Remove an element from the end of the list
void llist_remove_last( LList* lst )
{
	if(lst->head==NULL)
		return;
	Node *n;
	Node *n2;
	n=lst->head;
	if(lst->head->next==NULL)
	{
		lst->head=lst->head->next;
		free(n);
		return;
	}
	while((n->next)->next!=NULL)
	{
		n=n->next;
	}
	n2=n->next;
	free(n2);
	n->next=NULL;
}

// Remove an element from the beginning of the list
void llist_remove_first( LList* lst )
{
	if(lst->head==NULL)
		return;
	Node *n;
	n=lst->head;
	if(lst->head->next==NULL)
		{
			llist_remove_last(lst);
			return;
		}
	lst->head=lst->head->next;
	free(n);
}

// Remove an element from an arbitrary @idx position in the list
void llist_remove( LList* lst, int idx )
{
	if(idx<0||lst->head==NULL||idx>=llist_size(lst))
		return;
	if(idx==0)
	{
		llist_remove_first(lst);
		return;
	}
	int i=0;
	Node *n=(Node*)malloc(sizeof(Node));
	n=lst->head;
  while(i<idx-1&&n!=NULL)
	{
		n=n->next;
		i++;
	}
	if((n->next)->next==NULL)
	{
		Node *n2=(Node*)malloc(sizeof(Node));
		n2=n->next;
		free(n2);
		n->next=NULL;
	}
	else
	{
		Node *n2=(Node*)malloc(sizeof(Node));
		n2=n->next;
		n->next=(n->next)->next;
		free(n2);
	}
}
