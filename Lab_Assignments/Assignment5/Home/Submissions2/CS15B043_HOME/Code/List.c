
 #include "List.h"
 #include <stdlib.h>
 #include <stdio.h>
 
 typedef struct LList_ *List;
 typedef Node *PtrToNode;
 
 // Create a new node with next set to NULL
 
 Node *node_new( int data )
{
  PtrToNode NewNode = ( PtrToNode )malloc( sizeof( Node ) );
  
  NewNode->data = data;
  NewNode->next = NULL;
  
  return NewNode;
} 

 // Create an empty list (head shall be NULL)
 
 LList *llist_new()
{
  List NewList = ( List )malloc( sizeof( LList ) );
  NewList->head = NULL;
  
  return NewList;
} 

 // Traverse the linked list and return its size
 
 int llist_size( LList *lst )
{
  PtrToNode Temp = lst->head;
  int size = 0;
  
     while( Temp )
    {
      size++;
      Temp = Temp->next;
    } 
    
  return size;  
}

 // Traverse the linked list and print each element
 
 void llist_print( LList *lst )
{
  PtrToNode Temp = lst->head;
  
     while( Temp )
    {
      printf( "%d " , Temp->data );
      Temp = Temp->next;
    }   
}
 
 // Add a new element at the end of the list
 
 void llist_append( LList *lst , int data )
{
  PtrToNode Temp = lst->head;
  
     if( !Temp )
    {
      lst->head = node_new( data );
      return;
    } 
    
     while( Temp->next )
      Temp = Temp->next;
      
  Temp->next = node_new( data );    
} 

 // Add a new element at the beginning of the list
 
 void llist_prepend( LList *lst , int data )
{
  PtrToNode Temp = lst->head;
  
     if( !Temp )
    {
      lst->head = node_new( data );
      return;
    } 
    
  Temp = node_new( data );
  Temp->next = lst->head;
  lst->head = Temp;
} 

 // Remove an element from the end of the list
 
 void llist_remove_last( LList *lst )
{
  PtrToNode Temp1 = lst->head , Temp2;
  
     if( !Temp1 )
      return;
 
     if( !Temp1->next )
    {
      free( Temp1 );
      lst->head = NULL;
      return;
    }  
      
     while( Temp1->next )
    {
      Temp2 = Temp1;
      Temp1 = Temp1->next;
    }  
    
  free( Temp1 );
  Temp2->next = NULL;   
} 

 // Remove an element from the beginning of the list
 
 void llist_remove_first( LList *lst )
{
  PtrToNode Temp1 = lst->head;
  
     if( !lst->head )
      return;
      
  lst->head = lst->head->next;
  free( Temp1 );     
} 
