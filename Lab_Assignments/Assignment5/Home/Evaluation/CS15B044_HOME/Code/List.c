#include "List.h"
#include<stdlib.h>
#include<limits.h>
#include<stdio.h>
// Create a new node with next set to NULL
Node* node_new( int data)
{
	Node *new;
	new= (Node*)malloc(sizeof (Node)); //memory allocation
	new->data=data;
	new->next=NULL;
	return new;
}
// Create an empty list (head shall be NULL)
LList* llist_new()
{
	LList *start;
	start= (LList *)malloc(sizeof(LList));	//memory allocation
	start->head=NULL;
	return start;
}
// Traverse the linked list and return its size
int llist_size( LList* lst )
{
	int i=0;
	Node* temp=lst->head;
	while(temp!=NULL)	//iteration till end
	{
		temp=temp->next;
		i++;	//count for elements
	}
	return i;
}

// Traverse the linked list and print each element
void llist_print( LList* lst )
{  
	Node* temp=lst->head;
	while(temp!=NULL)	//iteration till end
	{   
		printf("%d ",temp->data);	//print element
		temp=temp->next;
	}
	printf("\n");
}
//get the element at position @idx
int llist_get( LList* lst, int idx )
{
	int size,data;
	size=llist_size(lst);
	if(idx<0 || idx>=size)	//check for idx range
	return INT_MIN;
	else
	{
		Node* temp=lst->head;
		while(temp!=NULL)	//iteration till end
		{
			if(idx==0)	//to return element of idx
			return temp->data;
			else	//iterate till it comes to index=idx
			{
				temp=temp->next;
				idx--;
			}
		}
	}
}
// Add a new element at the end of the list
void llist_append( LList* lst, int data )
{
	Node *new;
	new= node_new(data);
	
	Node *temp,*mid;
	temp=lst->head;
	
	if(temp==NULL)
	lst->head=new;
	
	while(temp!=NULL)	//iteration till end
	{      
		mid=temp->next;
	    if(mid==NULL)	//At last
	    {  
	        temp->next=new;	//add element
	        break;
        }
		temp=temp->next;
	}
	
}
// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int data )
{
	Node *new;
	new=node_new(data);
	if(lst->head==NULL)
	lst->head=new;	//add element 
	else
	{
		new->next=lst->head;
		lst->head=new;	//add element
	}
}
// Add a new element at the @idx index
void llist_insert( LList* lst, int idx, int data )
{
	int size;
	size=llist_size(lst);
	Node *new;
	new=node_new(data);
	if(idx>=0 && idx<=size)    //check for idx range
	{
		if(idx==0)
		llist_prepend( lst,data );
		else if(idx==size)
		llist_append( lst,data );
		else
		{
			Node* temp=lst->head;
			while(idx!=1)
			{
				temp=temp->next;
				idx--;
			}
			new->next=temp->next;
			temp->next=new;
		}
	}
}
// Remove an element from the end of the list
void llist_remove_last( LList* lst )
{
	Node* temp=lst->head,*temp2;
	
	while(temp!=NULL)
	{
		temp2=temp->next;
		if(temp2->next==NULL)
		{
			free(temp2);
			temp->next=NULL;
		}
	//	else
		
		temp=temp->next;
	}
}
// Remove an element from the beginning of the list
void llist_remove_first( LList* lst )
{
	Node* temp=lst->head;
	if(temp!=NULL)
	{
		
		lst->head=temp->next;
	}
	
}

// Remove an element from an arbitrary @idx position in the list
void llist_remove( LList* lst, int idx )
{
	int size;
	size=llist_size(lst);
	if(idx>=0 && idx<size)	//check for idx range
	{
		if(idx==0)
		llist_remove_first( lst );	//at idx, remove first
		else if(idx==size)
		llist_remove_last( lst );	
		else
		{
			Node *temp=lst->head,*temp2;
			while(idx!=1)
			{
				temp=temp->next;
				idx--;
			}
			temp2=temp->next;
			temp->next=temp2->next;
			free(temp2);
		}
	}
}
