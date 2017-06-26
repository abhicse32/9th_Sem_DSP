#include<stdio.h>
#include "List.h"
#include<stdlib.h>
#include<limits.h>
Node* node_new( int data)
{
  Node* p=(Node *)malloc(sizeof (Node));  // creating a new node p
  p->data = data;
  p->next = NULL;   // next set to null
  return p;
} 
LList* llist_new()
{
  LList* node=(LList *)malloc(sizeof(LList));  // creating an empty list
  node->head = NULL;                           // head set t null
  return node;
}
int llist_size( LList* lst )
{
    Node* p=(Node *)malloc(sizeof (Node));
    p = (lst->head);
    int size = 0;              // initialising
     while(p!=NULL)           // traversing the linked list
     {
       size++;
       p = p->next;
     }
     return size;
}
void llist_print( LList* lst )
{
    Node* p=(Node *)malloc(sizeof (Node));
    p = (lst->head);
   while(p!=NULL)
   {
      printf("%d ",p->data);              // traversing and printing each element
      p = p->next;
   }
  //printf("\n");
}
int llist_get( LList* lst, int idx )
{
    Node* p=(Node *)malloc(sizeof (Node));
    p = (lst->head);
    int i=0;
    while(p != NULL)
    {
      if(i==idx)
      {
      return p->data;                 // returning the data
      }
      i++;
      p = p->next;
    }
      return INT_MIN;                // returning INT_MIN if idx is out of bound
}
void llist_append( LList* lst, int data )           // adding new element at end of the list
{
    Node *new = node_new(data);                    // creating new node
    if(lst->head == NULL)       // if head is null
    {
       lst->head = new;                          
    return;}
    Node* p=(Node *)malloc(sizeof (Node));
    p = (lst->head);
        while(p->next!=NULL)
       {
           p = p->next;
      }
  p->next = new;
return;}
void llist_prepend( LList* lst, int data )
{
    Node *new = node_new(data);                     
    new->next = lst->head;               
    lst->head = new;            //new becomes head
}
void llist_insert( LList* lst, int idx, int data )
{
  if(idx == 0)
  {
    llist_prepend(lst,data);   //adding in the beginning if idx is zero 
  }
  else
  {
    Node* p=(Node *)malloc(sizeof (Node));
    p = (lst->head);
    int i = 0;
    while((i < idx-1)&&(p->next)!=NULL)
    {
      p = p->next;
      i++;
    }
    Node *new = node_new(data);
    new->next = p->next;
    p->next = new;
  }
}
void llist_remove_last( LList* lst )
{
    Node* p=(Node *)malloc(sizeof (Node));
    p = (lst->head);
       while((p->next)->next != NULL)            // moving the pointer till just before last
       {
           p = p->next;
       }
       p->next = NULL;
}
void llist_remove_first( LList* lst )
{
   lst->head = (lst->head)->next;             // changing the head
}
void llist_remove( LList* lst, int idx )
{
 if(idx==0)
 {
   llist_remove_first(lst);                   // using remove first if idx is zero
 }
   else
   {
    int i=0;
    Node* p=(Node *)malloc(sizeof (Node));
    p = (lst->head);
    while((i < (idx-1))&&(p->next != NULL))
    {
      p = p->next;
      i++;
    }
        (p->next) = ((p->next)->next);
   }
}
