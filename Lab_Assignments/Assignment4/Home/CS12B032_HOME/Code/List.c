/*
 * Author:Abhishek Yadav
 * Linked list data structure (Implementation)
 */

#include "List.h"
#include <stdlib.h>
#include <stdio.h>

// Create a new node with data and next element (can be NULL)
Node* node_new( int data1, int data2)
{
  Node* n = (Node*) malloc( sizeof(Node));
  n->col_ind = data1;
  n->val = data2;
  n->next = NULL;
  return n;
}
// Create an empty list (head shall be NULL)
LList* llist_new()
{
  LList* l = (LList*) malloc( sizeof( LList ) );
  l->head = NULL;
  return l;
}
// Traverse the linked list and return its size
int llist_size( LList* lst )
{
  int i=0;
  Node* n=lst->head;
  while(n!=NULL)
  {
     n=n->next;
     i++;
  }
  return i;
}

// Traverse the linked list and print each element
void llist_print( LList* lst )
{
  Node* n;
  for( n = lst->head; n != NULL; n=n->next )
  {
    printf( "%d ", n->val);
  }
}

Node* llist_get( LList* lst, int idx )
{
  int i = 0;
  Node* n=lst->head;
  if(n==NULL || idx< 0 || idx>=llist_size(lst))
    return NULL;
  while(i<idx){
    n=n->next;
    i++;
  }
  return n;
}

// Add a new element at the end of the list
void llist_append( LList* lst, int data1, int data2 )
{
    Node*p = lst->head;
    Node*q=node_new(data1,data2);
    if(p==NULL)
      lst->head=q;
    else{
       while(p->next!=NULL)
            p=p->next;
        p->next=q;
    }
}

// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int data1, int data2 )
{
  Node* n = node_new( data1,data2);
  n->next= lst->head;
  lst->head = n;
}
// Add a new element at the @idx index
void llist_insert( LList* lst, int idx, int data1, int data2)
{
  if (!idx)
      llist_prepend(lst,data1,data2);
  else
  {
    int i = 1;
    Node* n=lst->head;
    Node* p = node_new( data1,data2);
    while(i<idx && n)
    {
       n=n->next;
       i++;
    }
    if(!n)
      return;
    p->next=n->next;
    n->next =p;
  }
}
