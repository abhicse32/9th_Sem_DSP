
/*
*16th September 2016
*Written By Teratipally Srikar, CS15B037
*This Program has the functions required
*for manipulating the linked lists
*like create, insert, remove, size, print
*/

#include"List.h"    /*Inluding the necessary libraries*/
#include<stdlib.h>
#include<limits.h>
#include<stdio.h>

Node* node_new( int data)   /*This function creates a new node, by feeding the data into it and next to NULL and returns its pointer*/
{
    Node *new = (Node*) malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

LList* llist_new()  /*This function creates a new list, and points its head to NULL*/
{
    LList* x = (LList*) malloc(sizeof(LList));
    x->head=NULL;
    return x;
}

int llist_size( LList* lst )    /*This function finds the length of the linked list given*/
{
    int length = 0;
    if( (lst-> head) == NULL) return length;    /*Since if head is pointing to null, then length will be zero*/
    else{
            Node* counter;  /*Counter*/
            counter = lst->head;
            while( counter!=NULL)   /*Since the end of the list is intacterized by having NULL at its next datatype*/
                {
                    counter = counter->next;
                    length++;
                }
            return length;
        }
}

void llist_print( LList* lst )  /*This function prints the linked list*/
{
    if(lst->head == NULL);  /*If the linked list is null then there is nothing to be printed*/

    else{
            Node* counter;  /*Counter*/
            counter = lst-> head;

            while( counter!=NULL)   /*Since, we have to print the data till we hit the null pointer*/
                {
                    printf("%c ",counter->data);
                    counter = (counter->next);
                }
        }
    printf("\n");   /*Prints a new line*/
}

int llist_get( LList* lst, int idx )    /*This function fetches for an index element idx in list, and returns the data contained in it*/
{
    int l = llist_size(lst);    /*Computing the length of the linked list*/
    if((l-1)<idx) return 'a';   /*If the idx is greater than the size then we have to return int minimum*/
    int length = 0; /*Counter*/
    Node* counter = lst->head;  /*Counter*/

    while(length != idx)    {
                                counter = counter->next;
                                length++;
                            }
    return counter->data;
}

void llist_append( LList* lst, int data )   /*This function creates a node the end of array and feeds data to it*/
{
    if (lst->head == NULL) {
                                Node *node = (Node*) malloc(sizeof(Node));  /*Creating a new node*/
                                node->data = data;
                                node->next = NULL;
                                lst->head = node;
                           }
    else {
            Node *counter;      /*Counter*/
            counter = lst->head;
            while ((counter->next)!= NULL)
                {
                    counter = counter->next;
                }
            Node *x= node_new(data);    /*Creating a new node*/
            counter->next = x;
        }
}

void llist_prepend( LList* lst, int data )  /*This function creates a node at the beginning of list and feeds data into it*/
{

    Node* n = (Node*) malloc(sizeof(Node)); /*Creating a new node*/
    n->data = data;     /*Adding data into it*/
    n -> next = (lst->head);
    lst -> head = n;
}

void llist_insert( LList* lst, int idx, int data )  /*This function adds a node at the given idx*/
{
    int length = llist_size(lst);   /*Getting the size of the list*/

    if ((length==0) || (idx == 0)) llist_prepend(lst,data); /*Since if idx=0 then it is same as prepending*/
    else if (idx>=length) llist_append(lst,data);   /*Since if idx is very large then it is same as appending*/
    else    {
                Node *counter;  /*Counter*/
                counter = lst->head;
                int l = 1;  /*Counter*/

                while (l!=(idx))
                    {
                        counter = counter->next;
                        l++;
                    }
                Node *node = (Node*) malloc(sizeof(int));   /*Creating a new node*/
                node->data = data;                          /*Adding data into it*/
                node->next = counter->next;
                counter->next  = node;
            }
}

void llist_remove( LList* lst, int idx )    /*This function removes a node at the given idx*/
{
    int length = llist_size(lst);   /*Computing the size of the linked list*/
    if(length==1) {                 /*If length is 1 then we can directly change the head pointer to null*/
                    lst->head = NULL;
                  }

    else if ( idx==0 )  {           /*Removing the first element*/
                            lst->head = lst->head->next;
                        }

    else    {
                int l = 0;      /*Counter*/
                Node *counter;  /*Counter*/
                counter = lst->head;
                while ( l!=(idx-1))
                    {
                        counter = counter->next;
                        l++;
                    }
                Node *node; /*Temporary pointer*/
                node = ((counter->next)->next);
                counter->next = node;
            }
}

void llist_remove_last( LList* lst )    /*This function removes an element at the end of the list*/
{
    int length = llist_size(lst);       /*This computes the size of the linked list*/
    llist_remove( lst, length -1 );     /*This is same as removing element at the length-1 index of the linked list*/
}

void llist_remove_first( LList* lst )   /*This function removes the element at the beginning of the list*/
{
    llist_remove(lst,0);    /*It is same as removing the element the 0th index*/
}

