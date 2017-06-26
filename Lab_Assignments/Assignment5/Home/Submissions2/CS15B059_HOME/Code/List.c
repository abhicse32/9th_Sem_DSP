/* KOMMURU ALEKHYA REDDY 
        CS15B059
        30AUG2016
 IMPLEMENT VARIOUS OPERATIONS ON A LIST
 */               
#include "List.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//to create a new node and store the value in it
Node* node_new( int data)
{
	Node *newnode=(Node *)malloc(sizeof(Node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;	
}

// to create a new list by assigning the head pointer to NULL
LList* llist_new()
{
	LList *newlist=(LList *)malloc(sizeof(LList));
	newlist->head=NULL;
	return newlist;
}

//returns the size of the list by traversing the array and incrementing the count variable
int llist_size( LList* lst )
{
	int count=0;
	Node * temp=lst->head;//temporary pointer
	if(temp==NULL)
		return 0;
	else
	{
		while(temp!=NULL)
			{
			count++;
			temp=temp->next;
			}
	}
	return count;
}

//to print all the elements of the list by traversing the array
void llist_print( LList* lst )
{
	Node * temp=lst->head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;//increments the pointer after printing the data
	}
	printf("\n");
}

//used to get the element at a given index,by using a temporary pointer
int llist_get( LList* lst, int idx )
{
	Node *temp=lst->head;
	int count=0;	
	while(temp!=NULL)
	{
		if(count==idx)
		return temp->data;//returns data if count has reached the value of the given index
		else
		{
		temp=temp->next;
		count++;
		}
	}
	return INT_MIN;//returns int_min if index is not found
}

//used to add a node at the end of the list by dynamically creating it 
void llist_append( LList* lst, int data )
{
	
	Node *last=(Node *)malloc(sizeof(Node));
	last->data=data;
	last->next=NULL;
	if(lst->head==NULL)
	{
		lst->head=last;//if there is no element then directly point head to the element
	}
	else
	{
	Node * temp=lst->head;
	while(temp->next!=NULL)
		temp=temp->next;//else reach the last node and change the self referential pointers
	temp->next=last;
	}
}

//to add a node at the beginning of the list
void llist_prepend( LList* lst, int data )
{
	Node * first=(Node *)malloc(sizeof(Node));
	first->data=data;
	first->next=lst->head;//need to use the head element directly, cant use a temporary variable
	lst->head=first;
}

//to insert a node at the given index
void llist_insert( LList* lst, int idx, int data )
{
	Node *element=(Node *)malloc(sizeof(Node));
	element->data=data;
	Node * temp=lst->head;//creat a temporary pointer
	int count=0;
	if(idx==0)
	{
		element->next=lst->head;
		lst->head=element;//if index is NULL then you have to use the head pointer directly
	}	
	else{
	while(count<(idx-1))
	{
		temp=temp->next;
		count++;//increment till you reach the index	
	}
	element->next=temp->next;
	temp->next=element;
	}
}

//to remove the last node
void llist_remove_last( LList* lst )
{
	Node *temp=lst->head;
	while((temp->next)->next!=NULL)
		temp=temp->next;//increment till you reach the last but one node
	free(temp->next);//delete the last node by freeing the memory
	temp->next=NULL;
}

//to remove the first element, we have to use the head pointer directly and then free the temporary variable
void llist_remove_first( LList* lst )
{
	Node *temp=lst->head;
	lst->head=temp->next;
	free(temp);
}

//to remove a node at the specified index
void llist_remove( LList* lst, int idx )
{
	int count=0;
	Node *del;
	Node *temp=lst->head;
	if(idx==0)
	llist_remove_first( lst );//using a previous function if its the first node 
	else
	{
		while(count<(idx-1))
		{
		temp=temp->next;
		count++;
		}//increment it till you reach the last but one node
	if((temp->next)->next!=NULL)
		{
		del=temp->next;
		temp->next=(temp->next)->next;
		free(del);//free it 
		}
	else
	{
		del=temp->next;
		free(del);
		temp->next=NULL;
	}//special case when its the last node,have to make it NULL
	}
}







