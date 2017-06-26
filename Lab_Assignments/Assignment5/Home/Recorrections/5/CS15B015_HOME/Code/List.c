/* Program to implement basic operations on a linked list
        G.Pranav    CS15B015    12-9-2016*/
#include "List.h"
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
// Create a new node with next set to NULL
Node* node_new( int data){
    Node *newnodeptr=malloc(sizeof(Node));
    newnodeptr->data=data;
    newnodeptr->next=NULL;
    return newnodeptr;
}
// Create an empty list (head shall be NULL)
LList* llist_new(){
    LList *listptr=malloc(sizeof(LList));
    listptr->head=NULL;
    return listptr;
}
// Traverse the linked list and return its size
int llist_size( LList* lst ){
    int size=0;
    if(lst==NULL) return 0;
    else{
        Node *currptr=lst->head;
        while((currptr)!=NULL){
            size++;
            currptr=currptr->next;
        }
        return size;
    }
}
// Traverse the linked list and print each element
void llist_print( LList* lst ){
    Node *currptr=lst->head;
    while(currptr!=NULL){
        printf("%d ",currptr->data);
        currptr=currptr->next;
    }
    //printf("\n");
}
//get the element at position @idx
int llist_get( LList* lst, int idx ){
    int num;
    int i;
    Node *currptr=lst->head;
    for(i=0;(i<idx)&&(currptr!=NULL);i++){
        currptr=currptr->next;
    }
    if(currptr==NULL) num=INT_MIN;
    else num=currptr->data;
    return num;
}
// Add a new element at the end of the list
void llist_append( LList* lst, int data ){
    Node *currptr=lst->head;
    if(currptr==NULL){
        Node *newptr=node_new(data);
        lst->head=newptr;
    }
    else{
        Node *nextptr=currptr->next;
        while(nextptr!=NULL){
            currptr=currptr->next;
            nextptr=currptr->next;
        }
        Node *newptr=node_new(data);
        currptr->next=newptr;
    }
}
// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int data ){
    Node *newptr=node_new(data);
    newptr->next=lst->head;
    lst->head=newptr;
}
// Add a new element at the @idx index
void llist_insert( LList* lst, int idx, int data ){
    int a=llist_get(lst,idx);
    int b=llist_get(lst,idx-1);
    int i;
    if(a!=INT_MIN){
        if(idx==0){
            llist_prepend(lst,data);
            return;
        }
        Node *newptr=node_new(data);
        Node *currptr=lst->head;
        Node *nextptr;
        for(i=0;i<idx-1;i++){
            nextptr=currptr->next;
            currptr=nextptr;
        }
        nextptr=currptr->next;
        newptr->next=nextptr;
        currptr->next=newptr;
    }
    else if(b!=INT_MIN){
        llist_append(lst,data);
    }
    if(lst->head==NULL) llist_append(lst,data);
}
// Remove an element from the end of the list
void llist_remove_last( LList* lst ){
    Node *currptr=lst->head;
    if(currptr!=NULL){
        Node *nextptr=currptr->next;
        if(nextptr==NULL){
            lst->head=NULL;
            free(currptr);
        }
        else{
            while(nextptr->next!=NULL){
                currptr=nextptr;
                nextptr=nextptr->next;
            }
            currptr->next=NULL;
            free(nextptr);
        }
    }
}
// Remove an element from the beginning of the list
void llist_remove_first( LList* lst ){
    Node *currptr=lst->head;
    Node *nextptr;
    if(currptr!=NULL){
        nextptr=currptr->next;
        lst->head=nextptr;
        free(currptr);
    }
}
// Remove an element from an arbitrary @idx position in the list
void llist_remove( LList* lst, int idx ){
    int a=llist_get(lst,idx);
    int i;
    if(a!=INT_MIN){
        if(idx==0){
            llist_remove_first(lst);
        }
        else{
            Node *nextptr;
            Node *currptr=lst->head;
            for(i=0;i<idx-1;i++){
                nextptr=currptr->next;
                currptr=nextptr;
            }   
            
            currptr->next=(currptr->next)->next;
            //free(nextptr->next);
        }
    }
}




























