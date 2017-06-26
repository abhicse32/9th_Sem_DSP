#include "List.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <assert.h>

Node* node_new(int data){
    Node* new = malloc( sizeof(Node));												// Memory for new node
    new->data = data;
    new->next = NULL;
    return new;
}

LList* llist_new(){
    LList* new = malloc(sizeof(LList));
    new->head = NULL;																// memory for new list
    return new;
}

int llist_size( LList* lst){

    int i = 1;
    Node* p = lst->head;
    if(p == NULL) return 0;

    while( p -> next != NULL){
        p = p->next;															// Last term has next pointing to null
        i++;
    }
    return i;
}

void llist_print( LList* lst ){

    //if(lst->head == NULL) return ;
   
    Node* p = lst->head;
    
    while(p != NULL){															// Printing upto last variable
    	printf("%d ", p->data);
    	p = p->next;    
    }
    
    //printf("\n");
    return;
}

int llist_get( LList* lst, int idx){

    if(lst->head == NULL) return INT_MIN;
    Node* p = lst->head;
    int k = llist_size(lst);

    if( idx >= k ) return INT_MIN;											// When index is more than available terms

    int j = 0;

    while(j < idx){
        p = p->next;														//Normal cases with lower index
        j++;
    }

    return (p->data);
}

void llist_append( LList* lst, int data ){

    Node* p;
    p = lst->head;
    if( p == NULL ){													// When there is pointer is to NULL or list is empty
     	p=node_new(data);
     	lst->head = p;
     	return;
     }

    while( p->next != NULL ){											// when non-empty
        p = p->next;
    }
    Node* new = node_new(data);
    p->next = new;														// Assigning new one's next to NULL and old last one to NEW
    return;
}

void llist_prepend( LList* lst, int data){

    if( lst->head == NULL){ 											// Adding an element at the frnt of list when it is empty
    	Node* new = node_new(data);
    	lst->head = new;
    	return;
    }

    Node* new = node_new(data);									// When Not empty
    new->next = lst->head;

    lst->head = new;
    return;
}
void llist_insert( LList* lst, int idx, int data){									// Inserting at given index

    if( lst->head == NULL) return;
    Node* p = lst->head;
    int j = llist_size(lst);

    if( idx > j ) return;							// Index greater than length of list = ERROR
    if(idx == 0){
        llist_prepend(lst, data);					// Index at first one
        return;
    }
	if( idx == j){
        llist_append(lst, data);					// WHen index is last one's index
        return;
    }
    j = 1;
    while(j < idx){
        p = p->next;								// Normal case
        j++;
    }
    Node* new = node_new(data);
    new->next = p->next;
    p->next = new;

    return;
}

void llist_remove_last(LList* lst){

    if( lst->head == NULL ) return;					//  When it is empty

    Node* p = lst->head->next;
	Node* p1 = lst->head;
	while( p->next != NULL ){
        p1 = p1->next;								// Normal cases when not empty
        p = p->next;								// Assigning last but one's next to NULL 		
    }
    free(p);
    p1->next = NULL;
    
	return;
}

void llist_remove_first(LList* lst){
    
    if( lst->head == NULL ) return;					// Removing inital one's element
    Node* p;
    
    p = lst->head;
    
    lst->head = lst->head->next;
    free(p);
    return;
}

void llist_remove(LList* lst, int idx){				// Removing at given index's position

    if( lst->head == NULL ) return;
	Node* p;
    Node* p1;
    int j = llist_size(lst);
	p = lst->head;
	if( idx >= j ) return;
	if( idx == 0 ){								// At first position		
        llist_remove_first(lst);
        return;
    }
    j = 1;
    while(j < idx){								// Changing previous one's next from index term to next one's address
        p = p->next;
        j++;    
    }
    p1 = p->next;
    p->next = p1->next;
    free(p1);   
    return;
}



