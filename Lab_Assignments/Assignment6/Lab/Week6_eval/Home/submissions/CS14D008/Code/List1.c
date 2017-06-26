
#include "List1.h"
#include <stdlib.h>
#include <stdio.h>

#include "binary_tree1.h"

// Create a new node with data and next element (can be NULL)
list* node_new( Node* data_)
{
  list* n = (list*) malloc( sizeof(list));
  n->data = data_;
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
  list* n=lst->head;
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
  list* n;
  for( n = lst->head; n != NULL; n=n->next )
  {
    printf( "%s ", n->data->data );
  }
}

Node* llist_get( LList* lst, int idx )
{
  int i = 0;
  list* n=lst->head;
  if(n==NULL || idx< 0 || idx>=llist_size(lst))
    return NULL;
  while(i<idx){
    n=n->next;
    i++;
  }
  return n->data;
}

// Add a new element at the end of the list
void llist_append( LList* lst, Node* data )
{
    list*p=lst->head;
    list*q=node_new(data);
    if(p==NULL)
      lst->head=q;
    else{
       while(p->next!=NULL)
            p=p->next;
        p->next=q;
    }
}

// Add a new element at the beginning of the list
void llist_prepend( LList* lst, Node* data )
{
  list* n = node_new( data);
  n->next= lst->head;
  lst->head = n;
}

// Remove an element from the end of the list
void llist_remove_last( LList* lst )
{
  list* n;
  if(lst->head==NULL)
    return;
  else if( lst->head->next == NULL )
  {
    free( lst->head );
    lst->head = NULL;
  }
  else
  {
    n=lst->head;
    while(n->next->next!=NULL)
      n=n->next;
    free( n->next );
     n->next = NULL;
  }
}

// Remove an element from the beginning of the list
void llist_remove_first( LList* lst )
{
  list* n = lst->head;
  if(n==NULL)
  return;
  lst->head=n->next;
  free(n);
}

