#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
Node* node_new( int data)
{
	Node* new;
	new=(Node*)malloc(sizeof(Node*));
	if(new!=NULL)
	{
	new->data=data;
	new->next=NULL;
	}
	return new;
}


LList* llist_new()
{
	LList* lst;
	lst=(LList*)malloc(sizeof(LList*));
	
	lst->head=NULL;
		
	return lst;
}

int llist_size( LList* lst )
{
	
	
	if(lst->head==NULL)
	return 0;
	int size=0;
	Node* a;
	a=lst->head;
	while(lst->head!=NULL)
	{   size++;
		lst->head=lst->head->next;
		

	}
	lst->head=a;
	return size;
}

void llist_print( LList* lst )
{
	Node* a;
	a=lst->head;
	
	while(a!= NULL)
		{
			printf("%d",a->data);
			a=a->next;
		}
	printf("\n");

}



int llist_get( LList* lst, int idx )
{
	
	Node* a;
	a=lst->head;
	int pos=0;
	while(lst->head!=NULL)
	{  
		if(pos==idx)
			{  int num=lst->head->data;
				lst->head=a;
			return num;
		}
		lst->head=lst->head->next;
		pos++;

	}
	if(pos<idx)
		{   lst->head=a;
			return INT_MIN;
        }
}



void llist_append( LList* lst, int data )
{
	Node* new;
	new=node_new(data);
	Node* a;
	int flag=0;
	a=lst->head;
	if(new!=NULL)
	{
		if(lst->head==NULL)
		{lst->head=new;
			lst->head->next=NULL;
		 flag=1;}
		 else{	
		while(lst->head->next!=NULL)
		{
			lst->head=lst->head->next;
		}
		lst->head->next=new;}
	}
		if(flag==0)
			lst->head=a;
		
}

void llist_prepend( LList* lst, int data )
{
	Node* new;
	new=node_new(data);
	if(new!=NULL)
	{
		new->next=lst->head;
	    lst->head=new;

	}
	
}



void llist_insert( LList* lst, int idx, int data )
{
	Node* new;
	new=node_new(data);
	Node* a;
	a=lst->head;
	int pos=0;
	if(new!=NULL)
	{   if(idx==0)
		 llist_prepend(lst,data);
		 else
		 {
		while(lst->head!=NULL)
		{  
			if(pos+1==idx)
			{
				new->next=lst->head->next;
				lst->head->next=new;
				break;
			}
			lst->head=lst->head->next;
			pos++;
		}

		lst->head=a;
		if(pos==idx)
			llist_append(lst,data); 
		
		}
	}
	
}

void llist_remove_last( LList* lst )
{
	Node* a;
	Node* prev;
	prev=(Node*) malloc(sizeof(Node));
	a=lst->head;
	int flag=0;
	if(lst->head!=NULL)
		if(lst->head->next==NULL)
		flag=1;
 if(lst->head!=NULL )
	{
	while(lst->head->next!=NULL)
		{  prev=lst->head;
			lst->head=lst->head->next;}
			
				Node* temp;
				temp=lst->head;
				prev->next=NULL;
				lst->head=NULL;
				free(temp);
			
		
	}

       if(flag==0)
 		lst->head=a;

}

void llist_remove_first( LList* lst )
{
	if(lst->head!=NULL)
	{
		if(lst->head->next==NULL)
 		{
 				Node* temp;
				temp=lst->head;
				lst->head=NULL;
				free(temp);
 		}
 		else
 		{
 			Node* temp;
 			temp=lst->head;
 			lst->head=lst->head->next;
 			free(temp);
 		}

	}
}
void llist_remove( LList* lst, int idx )
{
	Node* a;
	a=lst->head;
	int flag=0;
	int pos=0;
	if(lst->head!=NULL)
	{
	if(idx==0 )
		llist_remove_first(lst);
	else if(lst->head->next!=NULL)
	{	flag=1;
		while(1)
		{  
			if(pos+1==idx)
			{
				Node* temp;
 			    	temp=lst->head->next;
 				lst->head->next=lst->head->next->next;
 				free(temp);
			}
			if(lst->head->next==NULL)
				break;
			lst->head=lst->head->next;
			pos++;

		}
	}
	if(flag==1)
	lst->head=a;
}
}




































			
