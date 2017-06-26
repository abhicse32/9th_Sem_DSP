#include "List.h"
#include<stdio.h>
#include<stdlib.h>

/* Create a new node with next set to NULL*/
Node* node_new( int data)
	{
		int i;
		i=data;
		Node *a;
		a=(Node*)malloc(1*sizeof(Node));  /*Allocating space to the new node about to be formed*/
		a->data=i;
		a->next=NULL;
		return a;
	}

/*Creating an empty list (head shall be NULL)*/
LList* llist_new()
	{
				
		LList *a;
		a=(LList*)malloc(1*sizeof(LList));/*Allocating space to the new linked list about to be formed*/
		a->head=NULL;
		return a;
	}

/*Finding the size of the linked list*/
int llist_size( LList* lst )
	{
		int size;
		size=0;
		Node *a;
		if(lst->head==NULL) return 0;	/*The case of an empty list*/
		else{
				a=lst->head;
				while(a!=NULL)
				{
					size=size+1;
					a=a->next;
				}
				return size;			
			}
	}


/*Printing the linked list*/
void llist_print( LList* lst )
	{
		Node *a;
		if(lst->head!=NULL)
		{
			a=lst->head;
			while(a!=NULL)
				{
					printf("%d ",a->data);
					a=a->next;
				}
			//printf("\n");
		}
		
	}			

/*Getting the element at position idx*/
int llist_get( LList* lst, int idx )
	{
		int size,i;
		size=llist_size(lst);
		Node *a;		
		if(idx<size)
		{
			a=lst->head;
			for(i=0;i<idx;i++)
			{
				a=a->next;
			}
			return a->data;
		}
	}	 

/*Adding a new element at the end of the list*/
void llist_append( LList* lst, int data )
	{
		Node *a,*b;
		if(lst->head==NULL) { a=node_new(data); lst->head=a; }/*The case of an empty list*/
		else{
		b=node_new(data);		/*b is the new node to be added*/
		a=lst->head;
		while(a->next!=NULL)
		{
			a=a->next;
		}
		a->next=b;
		}
	}	

/*Adding a new element at the beginning of the list*/
void llist_prepend( LList* lst, int data )
	{
		Node *a;
		a=node_new(data);
		a->next=lst->head;/*Creating a new node*/
		lst->head=a;	/*Changing the head pointer to the new node formed*/
	}

/*Adding a new element at the idx index*/
void llist_insert( LList* lst, int idx, int data )
	{
		int i;
		if(idx==0) llist_prepend(lst,data);
		else {
					Node *a,*b,*temp;
					b=lst->head;
					a=node_new(data);
					for(i=0;i<idx-1;i++)
					{
						b=b->next;
					}
					temp=b->next;
					b->next=a;	
					a->next=temp;					
			}
			
	}
 
/*Removing an element from the end of the list*/
void llist_remove_last( LList* lst )
	{
		Node *a,*b;
		a=lst->head;
		b=a->next;
		while(b->next!=NULL)
		{
			a=a->next;
			b=b->next;
		}
		a->next=NULL;
	}

/*Removing an element from the beginning of the list*/
void llist_remove_first( LList* lst )
	{
		Node *a;
		a=lst->head;
		a=a->next;
		lst->head=a;
	}

/*Removing an element from an arbitrary idx position in the list*/
void llist_remove( LList* lst, int idx )
	{
		int i;
		if(idx==0) llist_remove_first(lst);
		else {
					Node *a,*temp;
					a=lst->head;
					for(i=0;i<idx-1;i++)
					{
						a=a->next;
					}
					temp=a->next;
					a->next=temp->next;
			}
	}
	

			
			








