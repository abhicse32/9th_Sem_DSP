/*  Program to implement a linked list data structure and basic functions on it

	By  Chandrashekhar D --- Roll no.CS15B009 --- 29 Aug 2016 --- CS2710 Lab Assignment 4  */

#include "List.h" // Importing function prototypes and structures from List.c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

/*  Function to create a new node and initialize it with data :
	Input parameters : the data to be stored
	Returns : pointer to the node  */
Node* node_new( int data)
{
	Node* node;
	node = (Node* )malloc(sizeof(Node));
	if(node == NULL)
		printf("Memory Allocation Error!!\n");
	else
	{
		node->data = data;
		node->next = NULL;
	}
	return node;
}

/*  Function to create a new linked list and initialize its head to NULL :
	Input parameters : nothing
	Returns : pointer to the list  */
LList* llist_new()
{
	LList* list;
	list = (LList* )malloc(sizeof(LList));
	if(list == NULL)
		printf("Memory Allocation Error!!\n");
	list->head = NULL;
	return list;
}

/*  Function to find the size of a given linked list :
	Input parameters : pointer to the list
	Returns : size of the list, an integer  */
int llist_size( LList* lst )
{
	int size = 0;
	Node* cur;
	if(lst->head != NULL)
	{
		for(cur = lst->head; cur != NULL; cur = cur->next)
			size++;
	}
	return size;
}

/*  Function to print a list in a seequence from head to end :
	Input parameters : pointer to the list
	Returns : nothing  */
void llist_print( LList* lst )
{
	Node* cur;
	cur = lst->head;
	while(cur != NULL)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
	//printf("\n");
}

/*  Function to retrieve an element at a given index in a linked list :
	Input parameters : pointer to the list, index 
	Returns : element at index idx  */
int llist_get( LList* lst, int idx )
{
	int i = 0;
	Node* node = lst->head;
	if(idx > llist_size(lst)-1) // If index is out of bounds
		i = INT_MIN;
	else
	{
		for(i = 0; i < idx; i++)
			node = node->next;
		i = node->data;
	}
	return i;
}

/*  Function to append an element at the end of a linked list :
	Input parameters : pointer to the list, integer to be appended
	Returns : nothing  */ 
void llist_append( LList* lst, int data )
{
	Node* node;
	Node* cur;
	node = lst->head;
	cur = node_new(data);
	if(node == NULL)       // If list is empty
	{
		lst->head = cur;
		return;
	}
	while(node->next != NULL)
		node = node->next;
	node->next = cur;	
}

/*  Function to prepend(add at beginning) an element to the linked list :
	Input parameters : pointer to the list, integer to be prepended
	Returns : nothing  */
void llist_prepend( LList* lst, int data )
{
	Node** phead;
	Node* cur;
	phead = &(lst->head);
	cur = node_new(data);
	
	cur->next = (*phead);
	(*phead) = cur;
}

/*  Function to insert an element at a particular index :
	Input parameters : pointer to the list, index and integer to be inserted
	Returns : nothing  */
void llist_insert( LList* lst, int idx, int data )
{
	int i;
	if(idx == 0)
	{
		llist_prepend(lst,data);
		return;
	}
	else if(idx == llist_size(lst))
	{
		llist_append(lst,data);
		return;
	}
	else if(idx > (llist_size(lst)) )  // If index is out of bounds
		return;

	Node* node = lst->head;
	Node* cur = node_new(data);
	
	for(i = 0; i < idx-1; i++)
		node = node->next;
	cur->next = node->next;
	node->next = cur;
}

/*  Function to remove the last element in a linked list :
	Input parameters : pointer to the list
	Returns : nothing  */
void llist_remove_last( LList* lst )
{
	Node* node = lst->head;
	Node* remove;
	if (node->next == NULL) // If the list has only one element
	{
		lst->head = NULL;
		return;
	}
	while((node->next)->next != NULL)
		node = node->next;
	remove = node->next;
	node->next = NULL;
	free(remove);
}

/*  Function to remove the first element in a linked list :
	Input parameters : pointer to the list
	Returns : nothing  */
void llist_remove_first( LList* lst )
{
	Node* node = lst->head;
	lst->head = node->next;
	free(node);
}

/*  Function to remove the element at an index idx in a linked list :
	Input parameters : pointer to the list, index idx
	Returns : nothing  */
void llist_remove( LList* lst, int idx )
{
	if(idx == 0)
	{
		llist_remove_first(lst);
		return;
	}
	int i;
	Node* node = lst->head;
	Node* remove;
	for(i = 0; i < idx-1; i++)
		node = node->next;
	remove = node->next;
	node->next = (node->next)->next;
	free(remove);
}

