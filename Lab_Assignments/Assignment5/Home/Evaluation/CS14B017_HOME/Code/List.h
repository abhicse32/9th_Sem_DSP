#ifndef LIST_H
#define LIST_H

typedef struct Node_ Node;
struct Node_ {
    int data;
    Node* next;
};

Node* node_new( int data);

typedef struct LList_ {
    Node* head;
} LList;

LList* llist_new();

int llist_size( LList* lst );

void llist_print( LList* lst );

int llist_get( LList* lst, int idx );

void llist_append( LList* lst, int data );

void llist_prepend( LList* lst, int data );

void llist_insert( LList* lst, int idx, int data );

void llist_remove_last( LList* lst );

void llist_remove_first( LList* lst );

void llist_remove( LList* lst, int idx );

#endif

