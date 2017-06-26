/* Program to implement basic operations on a linked list Akshay Kumar*/

#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// Create a new node with next set to NULL
Node* node_new( int data)
{
	Node *p;
	p = (Node*) malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	return p;
}

// Create an empty list (head shall be NULL)
LList* llist_new()
{
	LList* l;
	l = (LList*) malloc(sizeof(LList));
	l->head = NULL;
	return l;
}

// Traverse the linked list and return its size
int llist_size( LList* lst )
{
	int k = 0;
	Node *n;
	n = lst->head;
	while(n != NULL)
	{
		k++;
		n = n->next;
	}
	return k;
}

// Traverse the linked list and print each element
void llist_print( LList* lst )
{
	Node *n;
	n = lst->head;
	if(n==NULL) return;
	while(1)
	{
		printf("%d ",n->data);
		n = n->next;
		if(!n) break;
	}
	
}

//get the element at position @idx
int llist_get( LList* lst, int idx )
{
	int k = 0;
	Node *n;
	n = lst->head;
	if(idx >= llist_size(lst)) return INT_MIN;
	while(k != idx)
	{
		n = n->next;
		k++;
	}
	return n->data;
}

// Add a new element at the end of the list
void llist_append( LList* lst, int data )
{
         
       Node * n=(Node *)malloc(sizeof(Node)*1);
       n->data=data;
       n->next=NULL;

       if(lst->head==NULL)
       lst->head=n;
       else
       {
      	 Node * t=lst->head;

      	 while(t->next!=NULL)
      	 {
      		 t=t->next;         
      	 }

      	 t->next=n; 
      	 } 
}

// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int data )
{
	Node *n = node_new(data);
	if(lst->head == NULL) lst->head = n;
	else
	{
		n->next = lst->head;
		lst->head = n;
	}
}

// Add a new element at the @idx index
void llist_insert( LList* lst, int idx, int data )
{
	int k = 1;
	Node *n;
	Node *x = node_new(data);
	n = lst->head;
	if(idx > llist_size( lst )) return;
	if(!lst->head) 
	{
		lst->head = x;
		x->next=NULL;
	}
	else if(idx == 0)
	{
		llist_prepend(lst, data );
		
	}
	else
	{
		while(k != idx)
		{
			n = n->next;
			k++;
		}
		x->next = n->next;
		n->next = x;
	}

}

// Remove an element from the end of the list
void llist_remove_last( LList* lst )
{
	Node *n;
	n = lst->head;
	while((n->next)->next != NULL)
	{
		n = n->next;
	}
	n->next = NULL;
}

// Remove an element from the beginning of the list
void llist_remove_first( LList* lst )
{
	lst->head = (lst->head)->next;
}

// Remove an element from an arbitrary @idx position in the list
void llist_remove( LList* lst, int idx )
{

	Node* n=lst->head;
	Node* m=lst->head;
	if(idx==0)
	{
		llist_remove_first( lst );
		return;
	}
	
	int k = llist_size(lst);
	if(idx>=k) return;
	
	k=0;
	

	while(n!=NULL)
	{
		if(k==idx)
		{
			m->next=n->next;
			return;				
		}
		k++;
		m=n;
		n=n->next;
	}
}