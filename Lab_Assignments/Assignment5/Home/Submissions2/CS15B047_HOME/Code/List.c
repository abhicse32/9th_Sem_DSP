#include<stdio.h>
#include "List.h"
#include<limits.h>
#include<stdlib.h>

//1)Create new Node
Node* node_new(int value)
{
	Node *new;
	new = (Node*)malloc(sizeof(Node)) ;//Allocate memory
        //If no space available malloc returns NULL,so check for successfull memory allocation
	if(new != NULL)
	{
		new->data = value ;
		new->next = NULL;	//Point node's next field to NULL
	}
	return new;
}

//Create and Initialize Empty Linked List
LList* llist_new()
{
	LList *list;
	list = (LList*)malloc(sizeof(LList)); //Allocate Memory
	list->head = NULL ; //Initialize
	return list ;
}

//Calculates size of LL
int llist_size( LList* lst )
{
	Node *temphead ;
	temphead = lst->head ;
	int size = 0;
	//Traverse to end of list and incrementing size together
	while(temphead != NULL)
	{
		size++;
		temphead = temphead->next ;  
	}
	return size;
}

//Print LL
void llist_print( LList* lst )
{
	Node *temphead ;
	temphead = lst->head ;
	//Traverse LL till end and print data element
	while(temphead != NULL)
	{
		printf("%d ",temphead->data);
		temphead = temphead->next ;
	}
//	printf("\n");
}

//Gets element at given index
//If index is invalid returns INT_MIN
int llist_get( LList* lst, int idx )
{
	int count = 0;
	int value=0;
	Node *temphead;
	temphead = lst->head ;
	//Check validity of index
	if( idx >= llist_size(lst) || idx < 0 )
	{
		return INT_MIN;
	}
	else
	{
	        //Traverse to index
		while(count<=idx-1)//count=idx on loop break 
		{
			temphead = temphead->next ;
			count++;
		}
		value = temphead->data ;		
		return value ;
	}	
}

//Appends element to end of LL
void llist_append( LList* lst, int value )
{
	Node *new;
	Node *temphead;
	//Check for empty list
	if(lst->head!=NULL)
		temphead = lst->head ; //Store list head
	
	new = node_new(value); //Create new node
	
	//For Base Case
	if(lst->head == NULL)
	{
		lst->head = new ;
	}
	else
	{
	        //Traverse to last element	
		while(lst->head->next != NULL)
		{
			lst->head = lst->head->next ;
		}
		//Insert new node 
		lst->head->next = new ;
		lst->head = temphead ;
	}
}
//Prepends element before list
void llist_prepend( LList* lst, int value )
{
        //Create new node
	Node *new;
	new = node_new(value);
	//Point new ele to head 
	new->next = lst->head ;
	//change head to new node
	lst->head = new ;	
}

//Insert given element at given index
void llist_insert( LList* lst, int idx, int value )
{
	if(idx>0 && idx < llist_size(lst) )//Check index validity
	{
		int count = 0;
		Node *new=node_new(value);//create node
		Node *temphead = lst->head;//store head		
	
		while(count<=idx-2)//Traverse to idx-1
		{
			count++;
			lst->head = lst->head->next ;
		}
		
                //head->next points to current ele at idx position	
                //Insert new bet idx-1 and current idx
		new->next = lst->head->next ;
		lst->head->next = new ;
		lst->head = temphead ;//recover head
	}
	else if(idx==0) //insert at start-->prepend
	{
		llist_prepend(lst,value);
	}
	else if (idx==llist_size(lst))//insert at end-->append
	{
		llist_append(lst,value);
	}
}

//Remove Last Element from list  
void llist_remove_last( LList* lst )
{	
	if(lst->head != NULL)//Check for empty list
	{		
		Node *temphead,*prev;//Maintain 2nd last element -->prev
		temphead = lst->head ;
		prev = lst->head ;
		//Only 1 element in list
		if(lst->head->next==NULL)
		{
			lst->head = NULL ;
		}
		
		while(lst->head->next!= NULL)
		{
			prev = lst->head;
			lst->head = lst->head->next ;			
		}
		//disconnect last ele by pointing prev to NULL
		prev->next=NULL;
		lst->head = temphead ;		//recover head
		
	}
}

//Remove first ele from LL
void llist_remove_first( LList* lst )
{
        //Check for empty list
	if(lst->head!=NULL)
	{	
	        Node *temphead  = lst->head ;
		lst->head = lst->head->next ;
		free(temphead);		//Change head to skip 1st element
	}
}

//Deletion at given index 
void llist_remove( LList* lst, int idx )
{
	int count = 0 ;
	if(idx >0 && idx < llist_size(lst)) //Check index validity
	{ 	
		Node *temphead = lst->head ;
		if(idx==1)//Remove 2nd element
		{
			lst->head->next = lst->head->next->next ;//Next connection has to be changed to skip element
		}
		else
		{	//Traverse to idx-1	
			while(count <= idx-2)
			{
				lst->head = lst->head->next ;
				count++; 
			}
			lst->head->next=lst->head->next->next ;
		}
		lst->head = temphead ;
		
	}
	else if (idx==0)//Remove from 0th index = remove from first
	{
		llist_remove_first(lst);
	}
}
