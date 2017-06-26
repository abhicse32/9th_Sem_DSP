#include "List.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
Node* node_new( int data)
{
    Node *node_new;
    node_new = ( Node*)malloc(sizeof( Node));
    node_new->next = NULL;
    node_new->data = data;
    return node_new;
}
LList* llist_new()
{
    LList *llist_new;
    llist_new = (LList*)malloc(sizeof(LList));
    llist_new->head = NULL;
    return llist_new;
}
int llist_size( LList* lst)
{
    Node *head = lst->head;
    int counter = 0;
    while(head != NULL)
    {
        head = head->next;
        counter = counter + 1;
     }
     return counter;
 }
 void llist_print( LList* lst )
 {	int i = llist_size(lst);
 	if(i = 0)
 	{
 		return;
 	}
    Node *head = lst->head;
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head->next;
     }
 }
 int llist_get( LList* lst, int idx )
 {
    Node *head = lst->head;
    int i = 0;
    while(head!=NULL)
    {   
        if(i == idx)
            return head->data;
        head = head->next;
        i++;
    }
    return INT_MIN;         
 }
 void llist_append( LList* lst, int data )
 {
    Node *head1 = lst->head;
    int j = llist_size(lst);
    if(j == 0)
    {
    	Node *demo1 ;
    	demo1 = (Node*)malloc(sizeof(Node));
    	demo1->data = data;
    	demo1->next = NULL;
    	lst->head = demo1;
    	return;
    }
    int i = 0;
    while(head1->next!=NULL)
    {
    	head1 = head1->next;
    	i = i+1;
    }
    Node *demo2;
    demo2 = (Node*)malloc(sizeof(Node));
    demo2->data = data;
    demo2->next = NULL;
    head1->next = demo2;
}    
void llist_prepend( LList* lst, int data )
{	int j = llist_size(lst);
	if(j == 0)
	{
    Node*head;
    head = (Node*)malloc(sizeof(Node));
    head->data = data;
    head->next = NULL;
    lst->head = head;
    return;
    }
    Node*head;
    head = (Node*)malloc(sizeof(Node));
    head->data = data;
    head->next = lst->head;
    lst->head = head;
 }
 void llist_insert( LList* lst, int idx, int data )
 {	int j = llist_size(lst);
 	if(idx>j)
 	{
 		return;
 	}
 	if(idx == 0)
 	{
 		llist_prepend(lst,data);
 		return;
 	}
 	if(idx == j)
 	{
 		llist_append(lst,data);
 		return;
 	}	
    Node *head1 = lst->head;
    Node *demon;
    
    demon = (Node*)malloc(sizeof(Node));
    demon->data = data;
    int i =0;
    
    while(i!=idx-1)
    {
          head1 = head1->next;
          i = i+1;
    }
    demon->next = head1->next;
    head1->next = demon;
  }    
  void llist_remove_last( LList* lst ) 
  {
  		 if(lst->head == NULL)
  		 {
  		 	return;
  		 }
  		 int j = llist_size(lst);
  		 if(j == 1)
  		 {
  		 	lst->head = NULL;
  		 	return;
  		 }
  		 Node *head1 = lst->head;
  		 Node *head2 = head1->next;
  		 int i = 0;
  		 while(head2->next!=NULL)
  		 {
  		 	head2 = head2->next;
  		 	head1 = head1->next;
  		 	i = i+1;
  		 }
  		 head1->next = NULL;
 }
 void llist_remove_first( LList* lst )
 {
 		if(lst->head == NULL)
 		{
 			return;
 		}
 		int j = llist_size(lst);
 		if(j == 1)
 		{
 			lst->head = NULL;
 			return;
 		}
 		Node *head1 = lst->head;
 		Node *head2 = head1->next;
 		head1->next = NULL;
 		lst->head = head2;
 		
 }
 void llist_remove( LList* lst, int idx )
{
	if(lst->head == NULL)
	{
		return;
	}
	int i = llist_size(lst);
	if(idx > i-1)
	{
		return;
	}
	if(idx == 0)
	{

		llist_remove_first(lst);
		return;
	}
	if(idx == i-1)
	{
		llist_remove_last(lst);
		return;
	}
	Node *head1 = lst->head;
	Node *head2 = head1->next;
	int j =0;
	while(j != idx-1)
	{
		head2 = head2->next;
		head1 = head1->next;
		j = j+1;
	}
	head1->next = head2->next;
		head2->next = NULL;
}
