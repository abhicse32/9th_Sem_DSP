#include "List.h"
#include <stdlib.h>
#include <stdio.h>

Node* node_new(int data)					//new node with next set to NULL
{
 	Node* node;
	node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	node -> next = NULL;
	return node;
}


LList* llist_new()						//creating an empty list
{
	LList* emptylist = malloc(sizeof(LList));
	emptylist -> head == NULL;
	return emptylist;
}

int llist_size(LList* lst)					//for the sizeof the list
{
   	int l = 0;
   	Node* current;
	
   	for(current = lst -> head; current != NULL; current = current-> next)	l++;

   	return l;
}

void llist_print(LList* lst)					//printing elements in the list
{
	Node* ptr = lst -> head;	
   	while(ptr != NULL)
	{        
      		printf("%d ",ptr -> data);
      		ptr = ptr -> next;
   	}	
	fflush(stdout);
	
	return;
}

int llist_get( LList* lst, int idx )				//for a element at any index
{
   	Node* current = lst -> head; int i = 0;

   	if(current == NULL)
	{
      		return -1;
   	}
	else
   	{
		while(i != idx)		
		{
			i++;
			current = current -> next;
		}
   	}     
   	return current -> data;
}

void llist_append( LList* lst, int data )				//adding an element at the last
{

	Node* node = node_new(data);

	Node* current = lst -> head;
	
 	if(current == NULL)
 	{
   		lst -> head = node;
   		return;
 	}
 	else
 	{
     		while(current -> next != NULL)
     		{
     			current = current -> next;
     		}
   		current -> next = node;
 	}
}
void llist_prepend( LList* lst, int data )				//adding a element at the first
{
	
	Node* node = node_new(data);


   	if(lst -> head == NULL)
   	{
   		lst -> head = node;
   		return;
   	}
   	else
   	{
   	
   		node -> next = lst -> head;
   		lst -> head = node;

   		
   	}
   	return;
}

void llist_insert( LList* lst, int idx, int data )			//adding an element at any index
{
	
   
    	Node* current = lst->head;
   
   	Node* node = node_new(data);
   
    	
   
    	if(idx == 0)
    	{
        	node->next = (lst->head);   
        	lst->head = node;
        	return ;
    	}
    	
    	int i;
   
    	for(i = 0; i < idx - 1; i++) current = current->next;
   
    	node->next = current->next;
    	current->next = node;

}

void llist_remove_last( LList* lst )					//removing the last element
{
	Node *current = lst -> head;
	if(current -> next == NULL) 
	{
		lst -> head = NULL;
		return;
	}
	
	while(((current -> next) -> next) != NULL)
	{
		current = current -> next;
	}
	current -> next = NULL;
	return;
}

void llist_remove_first( LList* lst )					//removing the first element
{
	lst -> head = ((lst -> head) -> next); 
}

void llist_remove( LList* lst, int idx )				//removing the element at any index
{
   	Node* current = lst -> head;int i;
   	
   	if(idx == 0)	llist_remove_first( lst );
  	
 
   
    	for(i = 0; i < idx - 1; i++)
    	{
    		current = current -> next;
    	}
    	current -> next = ((current -> next) -> next);	
}


	


