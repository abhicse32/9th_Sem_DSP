#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

Node* node_new(int data)
{ 
    Node* node= (Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
                                      
    return node; 
}

LList* llist_new()
{
   LList* list;
   list=(LList*)malloc(sizeof(LList));
   list->head=NULL;
   return list;
}

int llist_size( LList* lst )
{
    int count=0;
    Node* cur;
    cur = (Node*)malloc(sizeof(Node));
  if(lst->head!=NULL)
    {  cur=lst->head;
        while(cur!=NULL)
        {         
         count++; 
         cur=cur->next;
        }
    }
    return count;
}

void llist_print( LList* lst )
{
    Node* cur=(Node*)malloc(sizeof(Node)*1);   
     
 
  cur=lst->head;
        while(cur!=NULL)
        {
                printf("%d ",cur->data);    
         cur=cur->next;
      
        }
     printf("\n");
 
}

int llist_get( LList* lst, int idx )
{
   Node* cur;
   cur = (Node*)malloc(sizeof(Node));
    
  cur=lst->head;
   int count=0;
        for(count=0;cur!=NULL;count++)
      {
                           
         
         if(count==idx)
         return cur->data;
         cur=cur->next;                       
      }
      
      
      return INT_MIN;
        
        
}

void llist_append( LList* lst, int data )
{
    Node* cur;
    cur = (Node*)malloc(sizeof(Node));
    cur->data=data;
    cur->next=NULL;
    if(lst->head==NULL)
    {lst->head=cur;
    }
else
    { Node * temp=lst->head;
    while(temp->next!=NULL)
    {
             temp=temp->next;
    }
    temp->next=cur;

    }
}

void llist_prepend( LList* lst, int data )
{
    Node* temp;    
    temp = (Node*)malloc(sizeof(Node));
     temp->data=data;
     temp->next=lst->head;
     lst->head=temp;
}

void llist_insert( LList* lst, int idx, int data )
{
      Node* cur;
      cur = (Node*)malloc(sizeof(Node));
      Node* temp;
      int count;
   
   cur->data=data;
   
   if(idx==0)
   {
    cur->next=lst->head;
    lst->head=cur;
   }
   else
   { Node* temp;
     temp=(Node*)malloc(sizeof(Node));
    
     temp=lst->head;
     for(count=0;count<idx-1;  ) 
      {     
       temp=temp->next;
             count++;
      }       
               cur->next=temp->next;
               temp->next=cur;
                                     
   }
    
}

void llist_remove_last( LList* lst )
{
    Node* cur;
    cur = (Node*)malloc(sizeof(Node));
     if (lst->head!=NULL)
   { cur=lst->head;
    while(cur->next->next!=NULL)
    {
         cur=cur->next;
    }
    if(cur->next->next==NULL)
   {
     cur->next=NULL;      
   }
   }
}

void llist_remove_first( LList* lst )
{
 if(lst->head!=NULL)
    lst->head=(lst->head)->next;
}

void llist_remove( LList* lst, int idx )
{
    Node* cur;
    cur = (Node*)malloc(sizeof(Node));
    
    cur=lst->head;
    if(idx==0)
    {
    lst->head=lst->head->next;
    }
    int count=0;
    for(count=0;count<idx-1&&cur!=NULL;count++)
        
      {  
       cur=cur->next;
      }
    cur->next=cur->next->next;     
       
    
  }
 


