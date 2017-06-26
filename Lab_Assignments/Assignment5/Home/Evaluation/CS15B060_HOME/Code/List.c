//this program includes list.h 
                       
 #include "List.h"
#include<stdio.h>
#include<stdlib.h>
Node* node_new( int data)                   //function for creating a new node
 {Node *cur=(Node*)malloc(sizeof(Node));
   cur->data=data;
   cur->next=NULL;
   return cur;
   }
   
   LList* llist_new()                       //making head ptr point to null initially
   {LList *h;
    h=(LList*)malloc(sizeof(LList));
    
    h->head=NULL;
     return h;
    }
    int llist_size( LList* lst )              //getting size of list
     { 
       int n;int i=0;
       Node *t=lst->head;
         if(t==NULL)
          return -1;
           else
            { while(t->next!=NULL)
              {t=t->next;i++;}
             return i+1;
             }
             
         }    
         
         void llist_print( LList* lst )           //printing  the list of elements till NULL is reached
         { Node *t=lst->head;
         
          while(t!=NULL)
             {  printf("%d ",t->data);
               t=t->next;
               }
             
             printf("\n");
             
             }
             
             
             int llist_get( LList* lst, int idx )    //this function is used for getting value of index(eg. a[idx]...sort of)
          {  Node *t=lst->head;
          if(idx<0 ||idx>llist_size(lst))
                 return;
           else{      
           if(t==NULL)
             return -1;
             else
             { int i=0;
               for(i=0;i<idx;i++)
               t=t->next;
               return t->data;
               }
               }
               
               }
               
               void llist_append( LList* lst, int data )    //fn for appending data
               {Node *node;
                 node=(Node*)malloc(sizeof(Node));
                 node->data=data; node->next=NULL;
                 Node *t=lst->head;
                 if(t==NULL)
                 lst->head=node;
                 else{
                 while(t->next!=NULL)
                 t=t->next;
                 t->next=node;
                 t=node;
                 node->next=NULL;
                 }
                 }
                 
                 
                 
                 void llist_prepend( LList* lst, int data )   //function for adding node to 1st position
                 {Node *node;
               //  if(lst->head==NULL)
                //{node->next=NULL;lst->head=node;}
                 
                 
                 node=(Node*)malloc(sizeof(Node));
                 node->data=data;
                 node->next=lst->head;
                 lst->head=node;
                 
                 }
                 
                 
                 
                 void llist_insert( LList* lst, int idx, int data )// insertion operation of list
                 {Node *temp;int i=0;
                 Node *t=lst->head;
                 temp=(Node*)malloc(sizeof(Node));
                 temp->data=data;
                 
                if(idx<0 ||idx>llist_size(lst)+1)                //corner cases taken care of here
                 return;
                 else{
                 if(idx!=0)
                 {
                  
                  while(i<idx-1)
                  {  t=t->next; 
                      i++;}
                    temp->next=t->next;
                     t->next=temp;
                  }
                  
                  
                  else{temp->next=lst->head;
                  lst->head=temp;
                   }
                   }
                  
                  }
                  
                  
                  void llist_remove_last( LList* lst )              //removing last element each time
                  { Node *t=lst->head;
                   if(t==NULL)
                    return;
                    if( t->next!=NULL)                             //again,corner cases taken care of
                     {while(t->next->next!=NULL )
                      t=t->next;
                      t->next=NULL;
                      }
                      else 
                      lst->head==NULL;
                      }
                 
              
                       
                       void llist_remove_first( LList* lst )             //removing 1st element
                  { if(lst->head==NULL)
                   return; 
                  if(lst->head->next!=NULL) 
                  lst->head=lst->head->next;
                  else 
                  lst->head=NULL;
                  }
                  
             void llist_remove( LList* lst, int idx )                    //removing intermediate elements
                   { int i=0;
                      Node *t=lst->head;
                      if(idx<0 ||idx>llist_size(lst))
                 return;
                    else
                    {
                      while(i<idx-1)
                      {t=t->next;i++;}
                       if(i!=0)
                       t->next=t->next->next;
                       if(i==0)
                        lst->head=t->next;
                       
                       }
                       }
