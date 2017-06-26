#include "List.h"
#include<stdlib.h>
#include<stdio.h>
Node* node_new( int data)
{
	Node* ptr=(Node*)malloc(sizeof(Node));
	ptr->data=data;
	ptr->next=NULL;
	return ptr;
}
LList* llist_new()
{
	
	LList* a=(LList*)malloc(sizeof(LList));
	a->head=NULL;
	return a;
}
int llist_size( LList* lst )
{
	Node *list1=lst->head;
	if(list1==NULL)
	{
		return 0;
	}
	else
	{
		int count=0;
		while((list1)!=NULL)
		{
			count ++;
			list1=list1->next;
			
		}
	return count;
	}
}
void llist_print( LList* lst )
{
	Node* list1=lst->head;
	if(list1==NULL)
	{
		return;
	}
	
	while((list1)!=NULL)
	{
		printf("%d ",list1->data);
		list1=list1->next;
	}
}	
int llist_get( LList* lst, int idx )
{
	int i;
	Node* list1=lst->head;
	for(i=0;i<idx;i++)
	{
		list1=list1->next;
	}
	return list1->data;
}
void llist_append( LList* lst, int data )
{
	Node* list1;
	list1=lst->head;
	if(list1==NULL)
	{
		lst->head=node_new(data);
	}
	else
	{
		for(;list1->next!=NULL;list1=list1->next)
		;
		list1->next=node_new(data);
		
		
	}
}
void llist_prepend( LList* lst, int data )
{
	Node* list1=lst->head;
	Node* ptr;
	ptr=(Node*)malloc(sizeof(Node));
	ptr->data=data;	
	ptr->next=NULL;
	if(list1==NULL)
	{
		lst->head=ptr;
	}
	else 
	{
	ptr->next=lst->head;
	lst->head=ptr;
	}
	
	
}
void llist_insert( LList* lst, int idx, int data )
{
	int i;
	
	if(idx==0)
	{
		llist_prepend(lst,data);
	}
	
	else if(idx==llist_size(lst))
	{
		llist_append(lst,data);
	}
	else 
	{
	Node* list1=lst->head;
	Node* ptr=(Node*)malloc(sizeof(Node));
	ptr->data=data;	
	for(i=0;i<idx-1;i++)
	{
		list1=list1->next;
	}
	ptr->next=(list1->next);
	list1->next=ptr;
	}
}
void llist_remove_last( LList* lst )
{
	Node* list1=lst->head;
	while((list1->next)->next!=NULL)
	{
		list1=list1->next;
	}
	list1->next=NULL;
}
void llist_remove_first( LList* lst )
{
	Node* list1=lst->head;
	lst->head=(list1->next);
}
void llist_remove( LList* lst, int idx )
{
	int i;
	Node* list1=lst->head;
	if(idx==0)
	{
		llist_remove_first(lst );
	}
	for(i=0;i<idx-1;i++)
	{
		list1=list1->next;
	}
	list1->next=(list1->next)->next;
}
		

		
	
		

	
	
	
	
	
	
	
	
	
