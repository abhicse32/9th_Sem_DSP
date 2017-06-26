/*Program with function definitions for linked list operations, Author: B Arjun, CS15B058*/
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Create a new node with next set to NULL
Node* node_new( int data)
{
	Node* nd=(Node*)malloc(sizeof(Node));
	if(nd!=NULL)
	{
		nd->data=data;
		nd->next=NULL;
		return nd;
	}
	return nd;
}



// Create an empty list (head shall be NULL)
LList* llist_new()
{
	LList* list=(LList*)malloc(sizeof(LList));
	list->head=NULL;
	return list;
}

// Traverse the linked list and return its size
int llist_size( LList* lst )
{
	int size=0;
	Node* np=lst->head;
	while(np!=NULL)
	{
		size++;
		np=np->next;
	}
	return size;
}

// Traverse the linked list and print each element
void llist_print( LList* lst)
{
	Node* np=lst->head;
	while(np!=NULL)
	{
		printf("%d ",np->data);					
		np=np->next;
	}
}

//get the element at position @idx
int llist_get( LList* lst, int idx )
{
	Node* np=lst->head;
	int counter=0;
	while(np!=NULL)
	{
		if(counter==idx)
		{
			return np->data;
		}
		else
		{
			np=np->next;
			counter++;
		}
	}
	return INT_MIN;					//If element is not found we return int min
}

// Add a new element at the end of the list
void llist_append( LList* lst, int data)
{
	Node* np=lst->head;
	if(np==NULL)						//If the list is empty
	{
		lst->head=node_new(data);
	}
	else
	{
		while(np->next!=NULL)			//To reach last element
		{
			np=np->next;
		}
		np->next=node_new(data);
	}
}

// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int data)
{
	Node* np=node_new(data);
	np->next=lst->head;
	lst->head=np;
}

// Add a new element at the @idx index
void llist_insert( LList* lst, int idx, int data)
{
	int counter=0;
	Node* np=lst->head;
	if(np==NULL&&idx==0)							//If the list is empty and idx==0
	{
		llist_append(lst,data);
	}
	else
	{
		if(idx==0)			//If we hav to add element at 0th index
		{
			llist_prepend(lst,data);				
		}
		else
		{
			while(np!=NULL)
			{
				if(counter==idx-1)		//To find element just before required index
				{
					Node* temp=np->next;
					np->next=node_new(data);
					np->next->next=temp;
					break;
				}
				counter++;
				np=np->next;
			}
		}
	}
}

// Remove an element from the end of the list
void llist_remove_last( LList* lst )
{
	Node* np=lst->head;
	if(np!=NULL)
	{
		if(np->next==NULL)			//if only 1 element
		{
			Node* del=np;
			lst->head=NULL;
			free(np);
		}
		else
		{
			while(np->next->next!=NULL)	//to get second last element
				np=np->next;
			Node* del=np->next;
			np->next=NULL;
			free(del);
		}
	}
}

// Remove an element from the beginning of the list
void llist_remove_first( LList* lst )
{
	Node* del=lst->head;
	if(del!=NULL)
	{
		lst->head=lst->head->next;
		free(del);
	}
}

// Remove an element from an arbitrary @idx position in the list
void llist_remove( LList* lst, int idx )
{
	if(lst->head!=NULL)			//if list is not empty
	{
		
		int counter=0;
		Node* np=lst->head;
		if(idx==0)				//if we have to delete at 0th index
			llist_remove_first(lst);
		else
		{
			while(np!=NULL)		
			{
				if(counter==idx-1)	//If we reach element just before index
				{
					Node* del=np->next;
					np->next=del->next;
					free(del);
					break;
				}
				counter++;
				np=np->next;
			}
		}	
	}	
}