//CS15B013 

#include "List.h"
#include <stdlib.h>
#include<stdio.h>
#include<limits.h>

	Node* node_new( int data)
      {
       Node * address=(Node *)malloc(sizeof(Node)*1);  //creating node pointer			
       address->data=data;							   //accessing member of structure
       address->next=NULL;
       return address;
      } 

	LList* llist_new()
      {
       LList * headaddress=(LList *)malloc(sizeof(LList)*1);
       Node * first=NULL;
       
       headaddress->head=first;
       return headaddress;
      }

	int llist_size( LList* lst )
      {Node * temp;
       if(lst->head==NULL)                           //empty list
         {return 0;}
       else
         {
          temp=lst->head;
         }
       
       int i=1;   
          while(temp->next!=NULL)
            {
             i++;
             temp=temp->next;
            }
          
        return i;      
       }


	void llist_print( LList* lst )
      {Node * temp;
       temp=lst->head;
       while(temp!=NULL)
        {
         printf("%d ",temp->data);
         temp=temp->next;
        }
      
      }

	int llist_get( LList* lst, int idx )
      {Node * temp;
       temp=lst->head;
       int i;
       for(i=0;temp!=NULL && i<idx;)   //loop for index
        {
         temp=temp->next;
         i++;
        }
       if(temp==NULL)
         return INT_MIN;              //constant
       else
         return temp->data;
      }

	void llist_append( LList* lst, int data )
      {
         
       Node * new=(Node *)malloc(sizeof(Node)*1);
       new->data=data;
       new->next=NULL;

       if(lst->head==NULL)
          lst->head=new;
       else
       {
       Node * temp=lst->head;

       while(temp->next!=NULL)
         {
          temp=temp->next;         
         }

       temp->next=new; 
       } 
     }

	void llist_prepend( LList* lst, int data )
      {Node * temp;
       Node * new=(Node *)malloc(sizeof(Node)*1);
       new->data=data;

       new->next=lst->head; 
       lst->head=new;

      }

	void llist_insert( LList* lst, int idx, int data )
      {Node * temp;
       Node * new=(Node *)malloc(sizeof(Node)*1);
       new->data=data;
       int i;
       if(idx==0)
         {
          new->next=lst->head;
          lst->head=new;
         }
       else
         {temp=lst->head;
          for(i=0;i<idx-1;)
            {
             temp=temp->next;
             i++;
            }
          new->next=temp->next;
          temp->next=new;
         }

       }

	void llist_remove_last( LList* lst )
      {Node * temp=lst->head;
       if(lst->head!=NULL)
         {if(temp->next==NULL)
            lst->head=NULL;
          else
          {
          while((temp->next)->next!=NULL)
               temp=temp->next;

          temp->next=NULL;
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
        Node * temp=lst->head;
        int i;
        if(idx==0)
          {lst->head=temp->next;return;}
        if(idx==1)
          {temp->next=(temp->next)->next;return;}

        for(i=0;i<idx-1 && temp!=NULL;i++)
           temp=temp->next;

        if(temp!=NULL )
          {
           temp->next=(temp->next)->next;           
          }
        

       }


