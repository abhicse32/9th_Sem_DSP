#include "DList.h"
#include <stdlib.h>
#include <stdio.h>

// Create a new node with data and next element (can be NULL)
DNode* dnode_new( int data_)
{
  DNode* n = (DNode*) malloc( sizeof(DNode));
  n->data = data_;
  n->next = NULL;
  n->prev=NULL;
  return n;
}
// Create an empty list (head shall be NULL)
DList* dlist_new()
{
  DList* l = (DList*) malloc( sizeof( DList ) );
  l->head = NULL;
  return l;
}
// Traverse the linked list and return its size
int dlist_size( DList* lst )
{
  int i=0;
  DNode* n=lst->head;
  while(n!=NULL)
  {
     n=n->next;
     i++;
  }
  return i;
}

// Traverse the linked list and print each element
void dlist_print( DList* lst )
{
  DNode* n;
  for( n = lst->head; n != NULL; n=n->next )
  {
    printf( "%d ", n->data );
  }
  printf( "\n" );
}

int dlist_get( DList* lst, int idx )
{
  int i = 0;
  DNode* n=lst->head;
  if(n==NULL || idx< 0 || idx>=dlist_size(lst))
    return -1;
  while(i<idx){
    n=n->next;
    i++;
  }
  return n->data;
}

// Add a new element at the end of the list
void dlist_append( DList* lst, int data )
{
    DNode*p=lst->head;
    DNode*q=dnode_new(data);
    if(p==NULL)
      lst->head=q;
    else{
       while(p->next!=NULL)
            p=p->next;
        q->prev=p;
        p->next=q;
    }
}

// Add a new element at the beginning of the list
void dlist_prepend( DList* lst, int data )
{
  DNode* n = dnode_new( data);
  n->next= lst->head;
  if(lst->head)
    lst->head->prev= n;
  lst->head = n;
}
// Add a new element at the @idx index
void dlist_insert( DList* lst, int idx, int data )
{
  if (!idx)
      dlist_prepend(lst,data);
  else
  {
    int i = 1;
    DNode* n=lst->head;
    DNode* p = dnode_new( data);
    while(i<idx && n)
    {
       n=n->next;
       i++;
    }

    if(!n)
      return;
    p->prev= n;
    if(n->next)
      n->next->prev= p;
    p->next=n->next;
    n->next =p;
  }
}

// Remove an element from the end of the list
void dlist_remove_last( DList* lst )
{
  DNode* n;
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
    DNode* temp= n->next;
    temp->prev=NULL;
    free( temp);
    n->next = NULL;
  }
}

// Remove an element from the beginning of the list
void dlist_remove_first( DList* lst )
{
  DNode* n = lst->head;
  if(n==NULL)
  return;
  lst->head=n->next;
  if(lst->head)
    lst->head->prev=NULL;
  free(n);
}

// Remove an element from an arbitrary position in the list
void dlist_remove( DList* lst, int idx )
{
  DNode* n=lst->head;
  if(lst==NULL || idx<0 || idx >= dlist_size(lst))
      return ;
  else if(idx==0)
    dlist_remove_first(lst);
  else
  {
    int i = 1;
    while(i<idx){
      n=n->next;
      i++;
    }
    DNode* temp=n->next;
    temp->next->prev= n;
    n->next=temp->next;
    free(temp);
  }
}

void dlist_reverse(DList* lst){
  DNode* node= lst->head;
  lst->head=NULL;
  while(node){
    DNode* temp= node->next;
    node->next=NULL;
    node->next= lst->head;
    if(lst->head)
      lst->head->prev= node;
    node->prev=NULL;
    lst->head= node;
    node= temp;
  }
}
