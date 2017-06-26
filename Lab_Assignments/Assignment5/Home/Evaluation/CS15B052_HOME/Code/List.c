// Defines functions defined in List.h
// Author : Milind Srivastava
// Date : 16 Sep 2016

#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

Node* node_new (int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

LList* llist_new()
{
    LList* temp = (LList*)malloc(sizeof(LList));
    temp->head = NULL;
    return temp;
}

// Traverse the linked list and return its size
int llist_size(LList* lst)
{
    Node* temp = lst->head;
    int count = 0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}

// Traverse the linked list and print each element
void llist_print( LList* lst )
{
    Node* temp = lst->head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    // printf("\n");
}

//get the element at position @idx
int llist_get( LList* lst, int idx )
{
    if (idx>=llist_size(lst))
    {
        return INT_MIN;
    }
    
    Node* temp = lst->head;
    int i=0;
    while (i!=idx)
    {
        temp = temp->next;
        i++;
    }
    return temp->data;
}

// Add a new element at the end of the list
void llist_append( LList* lst, int data )
{
    Node* newNode = node_new(data);
    Node* temp = lst->head;
    if(temp == NULL)
    {
        lst->head = newNode;
        newNode->next = NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}

// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int data )
{
    Node* newNode = node_new(data);
    newNode->next = lst->head;
    lst->head = newNode;
}

// Add a new element at the @idx index
void llist_insert( LList* lst, int idx, int data )
{
    Node* newNode = node_new(data);
    if(idx == 0) // if we have to add at the beginning of the list
    {
        llist_prepend(lst,data);
        return;
    }
    else if (idx > llist_size(lst)) // out of bounds
    {
        return;
    }
    else
    {
        int i=1;
        Node* temp = lst->head;
        while(i!=idx)
        {
            i++;
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Remove an element from the end of the list
void llist_remove_last( LList* lst )
{
    Node* temp = lst->head;
    if (temp==NULL || temp->next==NULL)
    {
        return;
    }
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Remove an element from the beginning of the list
void llist_remove_first( LList* lst )
{
    Node* temp = lst->head;
    if(temp==NULL)
    {
        return;
    }
    else
    {
        if(temp->next == NULL)
        {
            free(temp->next);
            lst->head = NULL;
        }
        else
        {
            lst->head = lst->head->next;
            free(temp);
        }
    }   
}

// Remove an element from an arbitrary @idx position in the list
void llist_remove( LList* lst, int idx )
{
    Node* temp=lst->head;
    int i=1;
    if(idx==0)
    {
        llist_remove_first(lst);
        return;
    }
    while(i!=idx)
    {
        i++;
        temp=temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}
