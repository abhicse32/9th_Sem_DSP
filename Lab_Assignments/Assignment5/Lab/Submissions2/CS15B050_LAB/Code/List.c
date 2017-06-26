#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
Node* node_new (int data)										//Creates a new node with data as info 
{
    Node* cur;
    cur=(Node*)malloc(sizeof(Node));							//Dynamic allocation
    cur->data = data;
    cur->next = NULL;
    return cur;
}

LList* llist_new()												//Declares a new list
{
    LList* cur;
	cur=(LList*)malloc(sizeof(LList));							//Dynamic allocation
    cur->head=NULL;
    return cur;
}

int llist_size(LList* lst)										//Finds the size of the list
{
    Node* cur;
    cur= lst->head;
    int size=0;
    while(cur!=NULL)                                            //Loops till last element
    {
        size++;													
        cur=cur->next;
    }
    return size;												//Returns the size
}

void llist_print( LList* lst )									//Prints the list
{
    Node* cur;
    cur= lst->head;
    while(cur!=NULL)                                            //Loops till last element
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
    printf("\n");
}

void llist_append( LList* lst, int data )						//Adds a node to the end of list
{
    Node* node;
	node= node_new(data);
    Node* cur;
	cur= lst->head;
    if(cur == NULL)												//If list is empty
    {
        lst->head = node;
        node->next = NULL;
    }
    else
    {
        while(cur->next!=NULL) cur=cur->next;
        cur->next = node;
        node->next = NULL;
    }
}

int llist_get( LList* lst, int idx )							//Returns the element at index
{
    if (idx>=llist_size(lst)) return INT_MIN;    
    Node* cur = lst->head;
    int k=0;
    while (k!=idx)												//Traverse till k is equal to index
    {
        cur = cur->next;
        k++;
    }
    return cur->data;
}


void llist_prepend( LList* lst, int data )						//Inserts a node to the beginning of the list
{
    Node* node = node_new(data);
    node->next = lst->head;
    lst->head = node;
}

void llist_insert( LList* lst, int idx, int data )				//Inserts a node at index position
{
    Node* node;
    node= node_new(data);
    Node* cur;
    cur = lst->head;   
    if(idx == 0)												//If element is to inserted in the beginning
    {
        llist_prepend(lst,data);
        return;
    }
    else if(idx==llist_size(lst))								//If element is to inserted in the last
    {
    	llist_append(lst,data);
    	return;
    }
    else if (idx > llist_size(lst)) return;						//Out of bound
    else
    {
        int k=1;
        while(k!=idx)											//Traverse till k is equal to index
        {
            k++;
            cur = cur->next;
        }
        node->next = cur->next;                                 //Inserting node b/w node at (k-1) and (k)
        cur->next = node;
    }
}

void llist_remove_last( LList* lst )							//Removes the last element from the list
{
    Node* cur = lst->head;
    if (cur==NULL)	return;										//If list is empty
	else if(cur->next==NULL) 
	{
		free(cur);
		return;
	}
    while((cur->next)->next!=NULL) cur=cur->next;
    free(cur->next);
    cur->next = NULL;
}

void llist_remove_first( LList* lst )							//Removes the first element of the list
{
    Node* cur = lst->head;
    if(cur==NULL) return;										//If list is empty
    else
    {
        if(cur->next == NULL)                                   //List has 1 element
        {
            free(cur);
            lst->head = NULL;
        }
        else
        {
            lst->head = (lst->head)->next;
            free(cur);
        }
    }   
}

void llist_remove( LList* lst, int idx )						//Removes the element from index 
{
    Node* node;
    Node* cur=lst->head;
    int k=1;
    if(idx==0)													//Removing first element
    {
        llist_remove_first(lst);
        return;
    }
    else if(idx==(llist_size(lst)-1)) 							//Removing last element
    {
    	llist_remove_last(lst);
    	return;
    }
    while(k!=idx)
    {
        k++;
        cur=cur->next;
    }
    node= cur->next;
    cur->next = (cur->next)->next;
    free(node);													//Deleting the node
}
