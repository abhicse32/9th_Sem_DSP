#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

Node* node_new( int data)                         // Create a new node with next set to NULL
{
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  temp->data = data;
  temp->next = NULL;
  return temp; 
}

LList* llist_new()                              // Create an empty list (head shall be NULL)
{
  LList *node;
  node = (LList *)malloc(sizeof(LList));
  node->head = NULL;
  return node;
}

int llist_size( LList* lst )                   // Traverse the linked list and return its size
{ 
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  temp = lst->head;
  int len = 0;
  while(temp != NULL)
  {
    len++;
    temp = (temp->next);
  }
  return len;
}

void llist_print( LList* lst )                 // Traverse the linked list and print each element
{
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  temp = lst->head;
  while(temp != NULL)
  {
    printf("%d ",(temp->data));
    temp = (temp->next);
  }
  //printf("\n");
}

int llist_get( LList* lst, int idx )              //get the element at position @idx
{
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  temp = lst->head;
  int i =0;
  while(temp != NULL)
  {
    if(i == idx)
    {
      return (temp->data);
    }
    i++;
    temp = (temp->next);
  }
 return INT_MIN;
}

void llist_append( LList* lst, int data )              // Add a new element at the end of the list
{ 
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  temp = lst->head;
  if(temp == NULL)
  {
    Node *new = node_new(data);
    lst->head = new;
    return;
  }
  while(temp->next != NULL)
  {
    temp = (temp->next);
  }
  Node *new = node_new(data);
  temp->next = new;
}

void llist_prepend( LList* lst, int data )                     // Add a new element at the beginning of the list
{
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  temp = lst->head;
  if(temp == NULL)
  {
    Node *new = node_new(data);
    lst->head = new;
    return;
  }
  Node *new = node_new(data);
  new->next = lst->head;
  lst->head = new;
}

void llist_insert( LList* lst, int idx, int data )                  // Add a new element at the @idx index
{
  if(idx == 0)
  {
    llist_prepend(lst,data);
  }
  else
  {
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp = lst->head;
    int i = 0;
    if(idx >= llist_size(lst))
      return;
    while((i < (idx-1))&&(temp->next != NULL))
    {
      temp = temp->next;
      i++;
    }
    Node *new = node_new(data);
    new->next =temp->next;
    temp->next = new;  
  }
}

void llist_remove_last( LList* lst )                         // Remove an element from the end of the list
{
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  temp = lst->head;
  while(((temp->next)->next) != NULL)
  {
    temp = temp->next;
  }
  (temp->next) = NULL;
}

void llist_remove_first( LList* lst )                          // Remove an element from the beginning of the list
{
  (lst->head) = ((lst->head)->next);
}

void llist_remove( LList* lst, int idx )                      // Remove an element from an arbitrary @idx position in the list
{
  if(idx == 0)
  {
    llist_remove_first(lst);
  }
  else
  {
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp = lst->head;
    int i = 0;
    while((i < (idx-1))&&(temp->next != NULL))
    {
      temp = temp->next;
      i++;
    }
    (temp->next) = ((temp->next)->next);
  }
}
