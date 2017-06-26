#include "List.h"
#include <stdlib.h>
#include <stdio.h>

Node* node_new( int data)
{
	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

// Create an empty list (head shall be NULL)
LList* llist_new()
{
	LList *lst = malloc(sizeof(LList*));
	lst->head = NULL;
	return lst;
}

// Traverse the linked list and return its size
int llist_size( LList* lst )
{
	int count = 0;
	Node *temp = lst->head;
	while( temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

// Traverse the linked list and print each element
void llist_print( LList* lst )
{
	Node *temp = lst->head;
	while(temp != NULL)
	{
		printf("%d ", temp->data );
		temp = temp->next;
	}
}

//get the element at position @idx
int llist_get( LList* lst, int idx )
{
	if( idx > 0 && idx < llist_size(lst))
	{
		int i=0;
		Node *temp = lst->head;
		while( temp != NULL)
		{
			if( i == idx)
				return temp->data;
		}
	}
	return -1;
}

// Add a new element at the end of the list
void llist_append( LList* lst, int data )
{
	Node *temp = lst->head;
	Node *new = node_new(data);

	if( lst->head == NULL)
	{
		lst->head = new;
		return;
	}
	while( temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int data )
{
	Node *new = node_new(data);
	if( lst->head == NULL)
	{
		lst->head = new;
		return;
	}
	new->next = lst->head;
	lst->head = new;
}

// Add a new element at the @idx index
void llist_insert( LList* lst, int idx, int data )
{
	if( idx == 0)
		llist_prepend( lst, data);
	else if( llist_size(lst) == idx)
		llist_append( lst, data);
	else if ( idx > 0 && idx < llist_size(lst))
	{
		int i=0;
		Node *new = node_new(data);
		Node *temp = lst->head;
		while( temp != NULL && i <= idx)
		{
			if( i == idx - 1)
			{
				new -> next = temp->next;
				temp -> next = new;
				return;
			}
			temp = temp->next;
			i++;
		}
	}
}

// Remove an element from the end of the list
void llist_remove_last( LList* lst )
{
	if( lst->head != NULL)
		{
			Node *temp = lst->head;
			if( temp->next == NULL)
			{
				lst->head = NULL;
				free(temp);
				return;
			}
			while( temp != NULL)
			{
				if( temp->next->next == NULL)
				{
					Node *x = temp ->next->next;
					temp->next = NULL;
					free(x);
					return;
				}
				temp = temp->next;
			}
		}
}

// Remove an element from the beginning of the list
int llist_remove_first( LList* lst )
{
	if( lst->head != NULL)
	{
		Node *temp = lst->head;
		if( temp->next == NULL)
		{
			lst->head = NULL;
			int x = temp ->data;
			return x;
		}
		lst->head = temp->next;
		int x = temp ->data;
		free(temp);
		return x;
	}
}

// Remove an element from an arbitrary @idx position in the list
void llist_remove( LList* lst, int idx )
{
	if( idx == 0)
		llist_remove_first(lst);
	else if ( idx == llist_size(lst) - 1)
		llist_remove_last(lst);
	else if ( idx > 0 && idx < llist_size(lst))
	{
		int i=0;
		Node *temp = lst->head;
		while( temp != NULL)
		{
			if( i == idx-1)
			{
				Node *x = temp->next;
				temp->next = x->next;
				free(x);
				return;
			}
			i++;
			temp = temp->next;
		}
	}
}

void llist_reverse_print(LList* lst)
{
	if(lst->head != NULL)
	{
		int x = llist_remove_first(lst);
		llist_reverse_print(lst);
		printf("%d ", x);
		llist_prepend(lst, x);
	}

}