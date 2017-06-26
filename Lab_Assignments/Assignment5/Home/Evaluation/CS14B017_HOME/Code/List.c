
#include "List.h"
#include <stdlib.h>
#include <stdio.h>

Node* node_new( int data_)
{
  Node* n = (Node*) malloc( sizeof(Node));
  n->data = data_;
  n->next = NULL;
  return n;
}
LList* llist_new()
{
  LList* l = (LList*) malloc( sizeof( LList ) );
  l->head = NULL;
  return l;
}
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

void llist_print( LList* lst )
{
  Node* n;
  for( n = lst->head; n != NULL; n=n->next )
  {
    printf( "%d ", n->data );
  }
}

int llist_get( LList* lst, int idx )
{
  int i = 0;
  Node* n=lst->head;
  if(n==NULL || idx< 0 || idx>=llist_size(lst))
    return -1;
  while(i<idx){
    n=n->next;
    i++;
  }
  return n->data;
}

void llist_append( LList* lst, int data )
{
    Node*p=lst->head;
    Node*q=node_new(data);
    if(p==NULL)
      lst->head=q;
    else{
       while(p->next!=NULL)
            p=p->next;
        p->next=q;
    }
}

void llist_prepend( LList* lst, int data )
{
  Node* n = node_new( data);
  n->next= lst->head;
  lst->head = n;
}
void llist_insert( LList* lst, int idx, int data )
{
  if (!idx)
      llist_prepend(lst,data);
  else
  {
    int i = 1;
    Node* n=lst->head;
    Node* p = node_new( data);
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

void llist_remove_last( LList* lst )
{
  Node* n;
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

void llist_remove_first( LList* lst )
{
  Node* n = lst->head;
  if(n==NULL)
  return;
  lst->head=n->next;
  free(n);
}

void llist_remove( LList* lst, int idx )
{
  Node* n=lst->head;
  if(lst==NULL || idx<0 || idx >= llist_size(lst))
      return ;
  else if(idx==0){
    lst->head= n->next;
    free(n);
  }
  else
  {
    int i = 1;
    while(i<idx){
      n=n->next;
      i++;
    }
    Node* temp=n->next;
    n->next=temp->next;
    free(temp);
  }
}

