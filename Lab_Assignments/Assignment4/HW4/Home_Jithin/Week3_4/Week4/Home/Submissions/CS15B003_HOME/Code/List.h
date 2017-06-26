/*
 * Author:Abhishek Yadav
 * Linked list data structure
 */

#ifndef LIST_H
#define LIST_H

// Node for the link list
typedef struct Node_ Node;
struct Node_ {
    int col_ind;
    int val;
    Node* next;
};

// Create a new node with next set to NULL
Node* node_new( int data1, int data2);

// Link list structure
typedef struct LList_ {
    Node* head;
} LList;

// Create an empty list (head shall be NULL)
LList* llist_new();

// Traverse the linked list and return its size
int llist_size( LList* lst );

// Traverse the linked list and print each element
void llist_print( LList* lst);

//get the element at position @idx
Node* llist_get( LList* lst, int idx );

// Add a new element at the end of the list
void llist_append( LList* lst, int, int);

// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int , int);

// Add a new element at the @idx index
void llist_insert( LList* lst, int idx, int, int);

#endif

