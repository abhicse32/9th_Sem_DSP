#include "List.h"
#include<stdlib.h>
#include<limits.h>
#include<stdio.h>

Node* node_new(int data){
        Node* new = (Node*) malloc(sizeof(Node));
        if(new==NULL) return;
        else{
                new->data=data;
                new->next=NULL;
        }
        return new;
}

LList* llist_new(){
        LList* list;
        list=(LList*)malloc(sizeof(LList));
        list->head=NULL;
        return list;
}


int llist_size( LList* lst ){
        Node* temp;
        temp=lst->head;
        int i=0;
        while(temp!=NULL){
                
                temp=temp->next;
                i++;
        }
        return i;
}

void llist_print( LList* lst ){
        Node* temp;
        temp=lst->head;
        if(temp==NULL) return;
        while(temp!=NULL){
                printf("%d ",temp->data);
                temp=temp->next;
        }
        //printf("\n");        
}

int llist_get( LList* lst, int idx ){
        if(idx<0) return INT_MIN;
        int i=0;
        Node* temp=lst->head;
        if(temp==NULL) return;
        if(temp->next==NULL&&idx==1) return temp->data;
        while(temp->next!=NULL){
                if(i==idx) return temp->data;
                else{
                        temp=temp->next;
                        i++;
                }
        }
        if(temp->next==NULL&&i==idx) return temp->data;
        if(temp->next==NULL&&i!=idx) return INT_MIN;

}

void llist_append( LList* lst, int data ){
        Node* new=node_new(data);      
        Node* temp;
        temp=lst->head;
        if(lst->head==NULL){
                lst->head=new;
                new->next=NULL;
                return;
        }
        while(temp->next!=NULL){
                temp=temp->next;
        }
        temp->next=new;
        new->next=NULL;
        return;
        
}

void llist_prepend( LList* lst, int data ){
        Node* new = (Node*) malloc(sizeof(Node));
        new->data=data;
        new->next=lst->head;
        lst->head=new;               
}

void llist_insert( LList* lst, int idx, int data ){
        Node* new=(Node*) malloc(sizeof(Node));
        int i=idx;
        new->data=data;
        Node *curr,*temp,*prev;
        curr=lst->head;
        prev=NULL;
        if(i==0){
                llist_prepend(lst,data);
                return;
        }
        
         while(curr!=NULL&&i!=0){
                prev=curr;
                curr=curr->next;
                i--;
        }
        if(curr==NULL&&i!=0) return;
       
        prev->next=new;
        new->next=curr;          
}

void llist_remove_last( LList* lst ){
        Node *last,*prev;
        last=lst->head;
        if(last->next==NULL){
                prev=last;
                free(last);
                prev=NULL;
                return;
        } 
        if(lst==NULL) return;
        while(last->next!=NULL){
                prev=last;
                last=last->next;
        }
        free(last);
        prev->next=NULL;
   
}

void llist_remove_first( LList* lst ){
        if(lst->head==NULL) return;
        Node* temp=lst->head;
        lst->head=(lst->head)->next;
        free(temp);
}

void llist_remove( LList* lst, int idx ){
        Node *curr,*prev;
        curr=lst->head;
        if(lst->head==NULL) return;
         if(curr->next!=NULL&&idx==0){
                lst->head=(curr->next);
                free(curr);
                return;
                
        }
        if(idx==0&&curr->next==NULL){
                llist_remove_first(lst);
                return;
        }
        prev=NULL;
        while(curr->next!=NULL&&idx!=0){
                prev=curr;
                curr=curr->next;
                idx--;
        }
        if(curr->next==NULL&&idx!=0) return;
        if(curr->next==NULL&&idx==0){ 
                llist_remove_last(lst);
                return;
        }
               
        Node* temp;
        temp=curr;
        prev->next=curr->next;
        free(temp);
        
}





