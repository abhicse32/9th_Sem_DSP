#include "DList.h"
#include<stdio.h>
#include<stdlib.h>

DNode* dnode_new( int data){
	
	DNode* new = (DNode*)malloc(sizeof(DNode));			//Allocates memory in the heap for the new node
	
	new->data = data;
	new->next = NULL;
	new->prev = NULL;	
	return new;
}

DList* dlist_new(){

	DList* lst = (DList*)malloc(sizeof(DList));			//Allocates memory for the new list
	lst->head = NULL;
	
	return lst;
}

int dlist_size( DList* lst ){							//Returns the size of the list

	int size = 0;
		
	DNode* a = lst->head;
	
	if(a == NULL) return 0;
		
	while(a != NULL) {							//Loops till the last element is reached
		a = a->next;
		size++;
	}
		
	return size;
}

void dlist_print( DList* lst ){						//Prints out the elements of the list

	DNode* a = lst->head;
	
	while(1)
	{
		if(a->next == NULL){ printf("%d \n",a->data); break;}	//Loops and prints till the last element is reached
		else printf("%d ",a->data);
		a = a->next;
	}

	fflush(stdout);
	
	return ;
}

int dlist_get( DList* lst, int idx ){					//Gives the element at the ith index
	
	if(idx >= dlist_size(lst)) return -1;
	
	int c = 0;
	DNode* a = lst->head;
	
	while(c != idx){								//Loops till the ith element is reached
		a = a->next;
		c++;	
	}	
	
	return a->data;
}

void dlist_append( DList* lst, int data ){				//Appends the data at the end of the list

	DNode* a = lst->head;
	
	DNode* new = dnode_new(data);
	
	if(lst->head ==  NULL){							//if empty list
	
		new->prev = NULL;
		lst->head = new;	
		return ;
	}
		
	while(a->next != NULL) a = a->next;					//loops till the last element is reached and then data is appended
	
	new->prev = a;
	a->next = new;
	
	return ;	
}

void dlist_prepend( DList* lst, int data ){				//Adds element at the start of the list

	DNode* a = lst->head;	

	DNode*  new = dnode_new(data);
	
	if(a == NULL){								//If empty list
		lst->head = new;
		return ;
	}
	
	new->next = lst->head;							//Sets next of the new element to the earlier first
	new->prev = NULL;								//Prev of the the new element to NULL	
	
	(lst->head)->prev = new;
	
	lst->head = new;								//Adds the new element
	
}

void dlist_insert( DList* lst, int idx, int data ){		//Inserts an element at ith index of the list

	DNode* a = lst->head;
	
	DNode* new = dnode_new(data);
	
	int c;
	
	if(idx == dlist_size(lst)){
		dlist_append(lst,data);
		return;
	}	
	
	if(idx == 0){			
				
		dlist_prepend(lst,data);				//Prepends if the element is to be inserted as the first element
		return ;
	}
	if(idx > dlist_size(lst)) return ;				//Returns if the theh index at which its supposed to be add is greater than size
	
	for(c = 0; c < idx-1; c++) a = a->next;
	
	(a->next)->prev = new;
	
	new->next = a->next;						//Adds element at the ith index
	new->prev = a;
	a->next = new;
	
	return ;
}

void dlist_remove_last( DList* lst ){			//Removes the last element from the list

	DNode* a = lst->head;
	if(a != NULL){
	
		if(a->next == NULL) {				
			lst->head = NULL;
			return ;
			}
			
		while((a->next)->next != NULL) a = a->next;
	
		a->next = NULL;
	}

	return ;
}

void dlist_remove_first( DList* lst ){			//removes the first element of the list	

	if(lst->head == NULL) return ;
	
	lst->head = (lst->head)->next;			//Assigns lst->head to the address of the second element
	(lst->head)->prev = NULL;				//Assigns prev of the second element as NULL
	
	return ;
}

void dlist_remove( DList* lst, int idx ){			//Removes the ith element from the list

	DNode* a = lst->head;
	
	int c;
	
	if(idx > dlist_size(lst)) return ;			//If the to be removed index is greater than the size if the list
	
	if(idx == 0){
		lst->head = a->next;
		(lst->head)->prev = NULL;			//Removes the ith element by bypassing over it
		return ;
	}
	
		
	
	for(c = 0; c < idx-1; c++) a = a->next;		//Removes the ith element by bypassing over it
	
	((a->next)->next)->prev = a;
	a->next = (a->next)->next; 	
	
	return ;
}

void dlist_reverse(DList* lst){			//Revereses the order of the list
	
	DNode* a = lst->head;
	 
	if((a == NULL)||(a->next == NULL)) return ;
	
	while(a->next != NULL){				//Changes prev to next and next to prev for the n-1 elements
		DNode* temp;
		temp = a->next;
		a->next = a->prev;
		a->prev = temp;
		
		a = a->prev;
	}
	lst->head = a; 					//Gives the lst head to the last element
	DNode* temp;					//Changes next and prev for the last element
	temp = a->next;
	a->next = a->prev;
	a->prev = temp;
	
	
	return ;
	
}
