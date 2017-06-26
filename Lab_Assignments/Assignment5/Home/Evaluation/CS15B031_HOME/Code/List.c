//Author: Phalguna Rao Ch.
//CS15B031
#include "List.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
Node* node_new( int data){
	Node* curr;
	curr = (Node*) malloc(sizeof(Node));		//allocating memory
	curr->data = data;
	curr->next = NULL;			
	return curr;
}
LList* llist_new(){
	LList* emp;
	emp = (LList*) malloc(sizeof(LList));		//allocating memory
	emp->head == NULL;
	return emp;
}
int llist_size( LList* lst ){
	int size = 1;
	Node* curr = (Node*) malloc(sizeof(Node));		//allocating memory
	if(lst->head == NULL) return 0;					//when empty list
	if(lst->head != NULL){								//traversing and noting size
		for(curr = lst->head; curr->next != NULL; curr = curr->next) size++;
	}
	return size;
}
void llist_print( LList* lst ){
	Node* curr = (Node*) malloc(sizeof(Node));		//allocating memory
	if(lst->head != NULL){								//if head = NULL : do nothing
		for(curr = lst->head; ; curr = curr->next){		//traversing and printing 
			printf("%d ", curr->data);
			if(curr->next == NULL) break;				//end of list
		}
	}
	//printf("\n");
	return ;
}
int llist_get( LList* lst, int idx ){
	int index = 0;
	Node* curr = (Node*) malloc(sizeof(Node));		//allocating memory to node
	if(lst->head == NULL) return INT_MIN;			//empty list
 	else{
		for(curr = lst->head; ; curr = curr->next){		//traversing  till idx
			if(index == idx) return curr->data;			//retrieving the value
			index++;
			if(curr->next == NULL) break;				//end of list
		}
	}
	return INT_MIN;
}
void llist_append( LList* lst, int data ){
	Node* curr = (Node*) malloc(sizeof(Node));			//allocating memory to node
	Node* target = (Node*) malloc(sizeof(Node));		//allocating memory to node
	if(lst->head == NULL){									//empty list
		curr->data = data;
		curr->next = NULL;
		lst->head = curr;
	}
	else{			
		for(curr = lst->head; ; curr = curr->next){			//travesing till the end
			if(curr->next == NULL){
				target->data = data;
				target->next = NULL;
				curr->next = target;
				break;
			}
		}
	}	
}
void llist_prepend( LList* lst, int data ){
	Node* curr = (Node*) malloc(sizeof(Node));			//allocating memory to node
	if(lst->head == NULL){									//if empty list
		curr->data = data;
		curr->next = NULL;
		lst->head = curr;
	}
	else{													//non empty list
		curr->data = data;
		curr->next = lst->head;
		lst->head = curr;
	}
}
void llist_insert( LList* lst, int idx, int data ){
	Node *temp1;         
	Node* temp = (Node*) malloc(sizeof(Node));            	//to have a note of current node 
	temp1 = (Node*)malloc(sizeof(Node));				//to have a note of prev node
	temp1 = lst->head;
 	int i;
	if(idx == 0) llist_prepend(lst, data);					
	else{													//traversing till idx
		for( i = 0 ; i < idx-1 ; i++ ){
      			temp1 = temp1->next;       
 		}
		temp->data = data;
		temp->next = temp1->next;
		temp1->next = temp;
	}
}
void llist_remove_last( LList* lst ){
	Node* curr = (Node*) malloc(sizeof(Node));			//current node 
	Node* prev = (Node*) malloc(sizeof(Node));			
	curr = lst->head;
	while(curr->next != NULL){							//to have a note of last but one node 
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;									//removing last node
	free(curr);
}
void llist_remove_first( LList* lst ){
	Node *temp;                                      
	temp = (Node*)malloc(sizeof(Node));				//allocating memory to node  
	temp = lst->head;                   
	lst->head = temp->next;     
	free(temp);		
}
void llist_remove( LList* lst, int idx ){
	if(idx == 0) llist_remove_first(lst);
	else{
		Node* curr = (Node*) malloc(sizeof(Node));		
		Node* prev = (Node*) malloc(sizeof(Node));
		curr = lst->head;
		while(idx--){										//having note of current and prev nodes
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		free(curr);
	}
	return ;
}



















		

	
