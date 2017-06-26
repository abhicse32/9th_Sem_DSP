#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include <limits.h>

// Create a new node with next set to NULL
Node* node_new( int data)
{
	Node* new;
	new = (Node*) malloc (sizeof(Node));
	new -> data = data;
	new -> next = NULL;
	return new;
}


// Create an empty list (head should be NULL)
LList* llist_new()
{
	LList* lst= ( LList*) malloc (sizeof(LList));
	lst -> head = NULL;    												// head is a pointer that points to first element of list. here NULL
	return lst;
}





// Traverse the linked list and return its size
int llist_size( LList* lst )
{
	if(lst-> head == NULL)
		return 0;

	int ctr = 1;
	Node* cur;
	cur = lst-> head -> next;
	while( cur!= NULL)
		{ 
			ctr++;
			cur = cur -> next;
		}
	
	return ctr;
	
}



// Traverse the linked list and print each element
void llist_print( LList* lst )
{
	Node* cur;
	cur = lst-> head;
	while( cur!= NULL)
		{ 
			printf("%d ", cur -> data);
			cur = cur -> next;
		}
	//printf("\n");
														// free cur because it becomes NULL
}

//get the element at position @idx
int llist_get( LList* lst, int idx )
{
	Node* cur;
	cur = lst-> head ;

	int pos = 0, temp;
	while(cur!= NULL)	
		{
			if(pos == idx )
			{ 
				temp = cur -> data;
				
				return temp;
			}
			pos++; 
			cur = cur -> next;
		}
	return INT_MIN;	
}




// Add a new element at the end of the list
void llist_append( LList* lst, int data )
{
	Node* cur;
	cur = lst-> head;

	Node* new = node_new(data);

	if(cur == NULL)
		{
			lst -> head = new;
			return;
		}
	while ( cur -> next != NULL)
		cur = cur -> next;
	cur -> next = new;         				    
}



// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int data )
{
	
	//Node * cur ;
	//cur = lst-> head ;

	Node* new = node_new(data);
	new -> next = lst -> head ;
	lst -> head = new;

}






// Add a new element at the @idx index
void llist_insert( LList* lst, int idx, int data )
{
	if(idx == 0)
		llist_prepend( lst, data );

	else
	{	
		Node* cur = (Node*) malloc (sizeof(Node));
		cur = lst-> head;
		Node* new = node_new(data);

		int pos = 0;
		while(cur!= NULL)	
			{
				if(pos+1 == idx )
				{ 
					new -> next = cur -> next;
					cur -> next = new;
				}
				pos++; 
				cur = cur -> next;
			}
	}
}

// Remove an element from the end of the list
void llist_remove_last( LList* lst )
{
	Node* cur ;
	cur = lst-> head;

	if( cur == NULL)
		return;

	if(cur -> next == NULL)
		{
			lst -> head = NULL;
			return;
		}


	if(cur != NULL)
	{	
		while ( cur -> next -> next != NULL)
			cur = cur -> next;

		Node* p = cur -> next;
		cur -> next = NULL;
		free(p);
		
	}        
}

// Remove an element from the beginning of the list
void llist_remove_first( LList* lst )
{
	Node* cur ;
	cur = lst-> head;

	if(cur != NULL)
	{
		lst -> head = cur-> next;
		cur -> next = NULL;
		free(cur);			
	}

	else
		free(cur);
}




// Remove an element from an arbitrary @idx position in the list
void llist_remove( LList* lst, int idx )
{
	if(idx == 0)
		llist_remove_first(lst);

	else
	{
		Node* cur;
		cur = lst-> head;
	
		int pos = 0;
		while(cur!= NULL)	
			{
				if(pos+1 == idx )
				{ 
					Node* p = cur -> next;
					cur -> next = cur -> next -> next;
					p -> next = NULL;
					free(p);
				}
				pos++; 
				cur = cur -> next;
			}	
	}
}


// Search for a data and return its least index
int llist_search( LList* lst, int val )
{
	Node* cur;
	cur = lst-> head ;

	int idx = 0;
	while(cur!= NULL)	
		{
			if( cur -> data == val )
			{ 
				return idx;
			}
			idx++; 
			cur = cur -> next;
		}
	return INT_MIN;	
}

// Change val at position idx given idx exists
void llist_changeval( LList* lst, int idx, int data )
{
	Node* cur = (Node*) malloc (sizeof(Node));
	cur = lst-> head;	
		
	int pos = 0;
	while(cur!= NULL)	
	{
		if(pos == idx )
		{ 
			cur -> data = data;
		}
		pos++; 
		cur = cur -> next;
	}	

	
}

// get the pos to insert a node with data as val
int llist_getpos( LList* lst, int data )
{
	Node* cur;
	cur = lst-> head ;

	int pos = 0, temp;
	while(cur!= NULL)	
		{
			if( (cur -> data) > data )
			{ 
				return pos;
			}
			pos++; 
			cur = cur -> next;
		}
	return INT_MIN;	
}









