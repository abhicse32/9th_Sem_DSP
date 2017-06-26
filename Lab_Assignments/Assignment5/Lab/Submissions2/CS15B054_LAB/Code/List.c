#include<stdio.h>
#include<stdlib.h>
#include "List.h"

LList* llist_new()
{
  LList* list = (LList*)malloc(sizeof(LList));
  list->head =NULL;
  return list;
}

Node* node_new( int data)
{ 
   Node* newNode=(Node*)malloc(sizeof(Node));
   newNode->data=data;
   newNode->next = NULL;
   return newNode;
} 
  
int llist_size( LList* lst )
{ 
    int count =0;
    Node* n = lst->head;
    while(n != NULL)
    {
       n = n->next;
       count++;
    }
    return count;
}

void llist_print( LList* lst )
{ 
    int d;
    Node* n;
    n=lst->head;
    while(n != NULL)
    {
      d=n->data;
      printf("%d ",d);
      n=n->next;
    }
    printf("\n");
    fflush( stdout );
}
int llist_get( LList* lst, int idx )
{
    Node* n ;
    n=lst->head;
    int count=0;
    while(count != idx && n!=NULL)
    { 
        count++;
        n = n->next;
    }
    if (n != NULL) return n->data;
}
void llist_append( LList* lst, int data )
{
    Node* temp= (Node*)malloc(sizeof (Node));  
    temp->data=data;
    temp->next=NULL; 
    Node* n ;
    n=lst->head;
    if(n == NULL)
    {
         lst->head = temp;
    }
    else
    {
        while(n->next != NULL) 
        { 
           n= n->next;
        }
        n->next = temp;
    }
} 
void llist_prepend( LList* lst, int data )   
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=data;
    n->next=NULL;
    if(lst->head == NULL)
    {  
        lst->head=n;
    }
    else
    {
        n->next = lst->head;
        lst->head = n;
    }
}

void llist_insert( LList* lst, int idx, int data )  
{
    int  count=0;
    Node* temp;
    temp=lst->head;
    Node* hPtr = (Node*)malloc(sizeof(Node));
    hPtr->data = data;
    hPtr->next = NULL;
    if(temp == NULL) lst->head = hPtr;
    else
    {
        if (idx==0) llist_prepend(lst,data);
        else
        {
           while(count!=(idx-1) && temp != NULL)
           {
               temp = temp->next;
               count++;
           }
           if (temp!=NULL)
           {
               hPtr->next = temp->next;
               temp->next = hPtr;
           }
       }
    }    
}
       
void llist_remove_last( LList* lst )
{
    Node* n;
    n=lst->head;
    if(lst->head != NULL)
    {
       while(n->next->next != NULL) 
       {
           n = n->next;
       }
       n->next = NULL;
    }
}
void llist_remove_first( LList* lst )
{
    if(lst->head != NULL)
    {
        lst->head = lst->head->next;
    }
    
}
void llist_remove( LList* lst, int idx )
{
    int count=0;
    Node* temp;
    temp=lst->head;
    if(lst->head != NULL)
    {
       if (idx == 0) lst->head = lst->head->next;
       else
       {
          while(count != (idx-1) && temp != NULL)
          {
              temp=temp->next;
              count++;
          }
          if(temp != NULL)
          {
              temp->next = temp->next->next;
          }
       }
    }
}    
     
