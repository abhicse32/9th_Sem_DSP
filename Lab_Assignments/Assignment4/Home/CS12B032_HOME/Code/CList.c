
#include "CList.h"
#include <stdlib.h>
#include <stdio.h>

// Create a new node with data and next element (can be NULL)
CNode* cnode_new( int data_)
{
  CNode* n = (CNode*) malloc( sizeof(CNode));
  n->data = data_;
  n->next = n;
  return n;
}
// Create an empty list (head shall be NULL)
CList* clist_new()
{
  CList* l = (CList*) malloc( sizeof( CList ) );
  l->head = NULL;
  return l;
}
// Traverse the linked list and return its size
int clist_size( CList* lst )
{
  if(lst->head==NULL)
  	return 0;
  CNode* n=lst->head;
  int i=1;
  for(; lst->head != n->next; n=n->next, ++i);
  return i;
}

// Traverse the linked list and print each element
void clist_print( CList* lst )
{
  if(lst->head!=NULL){
	  CNode* n= lst->head;
	  while(1){
	  	printf("%d ",n->data);
	  	n=n->next;
	  	if(n==lst->head)
	  		break;
	  }
	}
  printf( "\n" );
}

int clist_get( CList* lst, int idx )
{
  int i = 0;
  CNode* n=lst->head;
  if(n==NULL || idx< 0 || idx>=clist_size(lst))
    return -1;
  while(i<idx){
    n=n->next;
    i++;
  }
  return n->data;
}

// Add a new element at the end of the list
void clist_append( CList* lst, int data )
{
    CNode*p=lst->head;
    CNode*q=cnode_new(data);
    if(p==NULL)
      lst->head=q;
    else{
       while(p->next!=lst->head)
            p=p->next;
        q->next= lst->head;
        p->next=q;
    }
}

// Add a new element at the beginning of the list
void clist_prepend( CList* lst, int data )
{
  CNode* n = cnode_new( data);
  CNode* temp= lst->head;
  if(!temp)
  	lst->head= n;
  else{
	  n->next= temp;
	  while(temp->next!=lst->head)
	  	temp= temp->next;
	  temp->next= n;
	  lst->head = n;
	}
}
// Add a new element at the @idx index
void clist_insert( CList* lst, int idx, int data )
{
  if(idx<0 || idx>clist_size(lst))
  	return;
  else if (!idx)
      clist_prepend(lst,data);
  else
  {
    int i = 1;
    CNode* n=lst->head;
    CNode* p = cnode_new( data);
    while(i<idx)
    {
       n=n->next;
       i++;
    }
    p->next=n->next;
    n->next =p;
  }
}

// Remove an element from the end of the list
void clist_remove_last( CList* lst )
{
  CNode* n;
  if(lst->head==NULL)
    return;
  else if( lst->head->next ==lst->head )
  {
    free( lst->head );
    lst->head = NULL;
  }
  else
  {
    n=lst->head;
    while(n->next->next!=lst->head)
      n=n->next;
    CNode* temp= n->next;
    n->next= lst->head;
    free(temp);
  }
}

// Remove an element from the beginning of the list
void clist_remove_first( CList* lst )
{
  CNode* n = lst->head;
  if(n==NULL)
   return;
  else if(n->next == lst->head)
  	lst->head=NULL;
  else{
  	CNode* temp= lst->head;
  	while(temp->next!= lst->head)
  		temp= temp->next;
  	n=temp->next;
  	temp->next= lst->head->next;
  	lst->head=temp->next;
  }
  free(n);
}

// Remove an element from an arbitrary position in the list
void clist_remove( CList* lst, int idx )
{
  CNode* n=lst->head;
  if(n==NULL || idx<0 || idx >= clist_size(lst))
      return ;
  else if(idx==0)
  	clist_remove_first(lst);

  else
  {
    int i = 1;
    while(i<idx){
      n=n->next;
      i++;
    }
    CNode* temp=n->next;
    n->next=temp->next;
    free(temp);
  }
}

void clist_reverse(CList* lst){
	if(lst->head==NULL)
		return;
	CNode* node= lst->head->next;
	CNode* temp2= lst-> head;
	lst->head->next= lst->head;
	while(node!= temp2){
		CNode* temp= node->next;
		node->next=node;
		if(lst->head){
			CNode* temp3= lst->head->next;
			while(temp3->next!= lst->head)
				temp3= temp3->next;
			temp3->next= node;
			node->next= lst->head;
		}
		lst->head= node;
		node= temp;
	}
}