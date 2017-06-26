#include "List.h"
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

// Create a new node with next set to NULL
Node* node_new(int data){
  Node *np = (Node*) malloc(sizeof(Node));
  np->data = data;
  np->next = NULL;
  return np;
}

// Create an empty list (head shall be NULL)
LList* llist_new(){
  LList* list = (LList*) malloc(sizeof(LList));
  list->head = NULL;
  return list;
}

// Traverse the linked list and return its size
int llist_size( LList* lst ){
  Node *np = (Node*) malloc(sizeof(Node));
  np = lst->head;
  int count = 0;
  for(; np != NULL; np = np->next)
	count++;
  return count;
}

// Traverse the linked list and print each element
void llist_print( LList* lst ){
  Node *np = (Node*) malloc(sizeof(Node));
  np = lst->head;
  for(; np != NULL; np = np->next)
	printf("%d ", np->data);
  //printf("\n");
}

//get the element at position @idx
int llist_get( LList* lst, int idx ){
  if(idx < 0)
	return INT_MIN;
  Node *np = (Node*) malloc(sizeof(Node));
  np = lst->head;
  if(idx == 0)
	return np->data;
  int count = -1;
  for(; count < idx-1 && np->next != NULL; count++){
	np = np->next;
  }
  if(count == -1)
	return INT_MIN;
  return np->data;
}

// Add a new element at the end of the list
void llist_append( LList* lst, int data ){
  Node *np = (Node*) malloc(sizeof(Node));
  Node *temp = (Node*) malloc(sizeof(Node));
  np = lst->head;
  temp->data = data;
  if(np == NULL){
	temp->next = NULL;
	lst->head = temp;
	return;
  }
  else {
	while(np->next != NULL){
	  np = np->next;
	}
	np->next = temp;
	np = temp;
	np->next = NULL;
  }
}

// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int data ){
  Node *np = (Node*) malloc(sizeof(Node));
  Node *temp = (Node*) malloc(sizeof(Node));
  np = lst->head;
  temp->data = data;
  temp->next = NULL;

  if(np == NULL){
	np = temp;
	lst->head = temp;
	return;
  }
  temp->next = np;
  lst->head = temp;
}

// Add a new element at the @idx index
void llist_insert( LList* lst, int idx, int data ){
  Node *np = (Node*) malloc(sizeof(Node));
  Node *prev = (Node*) malloc(sizeof(Node));
  Node *temp = (Node*) malloc(sizeof(Node));
  np = lst->head;
  temp->data = data;
  temp->next = NULL;

  if(idx == 0){
	// Special case of prepending
	llist_prepend(lst, data);
	return;
  }
  if(idx == llist_size(lst)){
	//Special case of appending
	llist_append(lst, data);
	return;
  }
  int count = 0;
  for(; count < idx && np->next != NULL; count++){
	prev = np;
	np = np->next;
  }

  prev->next = temp;
  temp->next = np;
}

// Remove an element from the end of the list
int llist_remove_last( LList* lst ){
  Node *np = (Node*) malloc(sizeof(Node));
  Node *temp = (Node*) malloc(sizeof(Node));
  np = lst->head;
  // Special case of only one element
  if(np -> next == NULL){
	int value = lst->head->data;
	lst->head = NULL;
	return value;
  }
  while(np->next->next != NULL){
	np = np->next;
  }
  temp = np->next;
  np->next = temp->next;
  return temp->data;
  free(temp);
}

// Remove an element from the beginning of the list
int llist_remove_first( LList* lst ){
  // Special case of only one element
  if((lst->head)->next == NULL){
	int value = lst->head->data;
	lst->head = NULL;
	return value;
  }
  int value = (lst->head)->data;
  *(lst->head)= *(lst->head)->next;
  return value;
}

// Remove an element from an arbitrary @idx position in the list
int llist_remove( LList* lst, int idx ){
  // Special case of removing first element
  if(idx == 0){
	 return llist_remove_first(lst);
  }
  // Special case of removing last element
  if(idx == llist_size(lst) - 1){
	return llist_remove_last(lst); 
  }
  Node *np = (Node*) malloc(sizeof(Node));
  Node *prev = (Node*) malloc(sizeof(Node));
  np = lst->head;
  int count = 0;
  for(; count < idx && np->next != NULL; count++){
	prev = np;
	np = np->next;
  }
  //Node *temp = (Node*) malloc(sizeof(Node));
  //temp = np;
  prev->next = np->next;
  return np->data;
  free(np);
}
