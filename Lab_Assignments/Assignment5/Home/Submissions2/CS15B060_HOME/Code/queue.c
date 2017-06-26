#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new()                                //creating and initialising queue
{ queue* q=(queue*)malloc(sizeof(queue));
   q->front=(LList*)malloc(sizeof(LList));
   q->front->head=NULL;
  // q->front->head=(Node*)malloc(size(Node));
   q->rear=(LList*)malloc(sizeof(LList));
   q->rear->head=NULL;
   
   return q;
   
   }
   
   void enqueue(queue*q, int a)               //adding element to queue
   {
     llist_append( q->front, a );
     if(queue_size(q)==1)
     {q->rear->head=q->front->head;}
     else
     {q->rear->head=q->rear->head->next;} 
   
     }
     
     
     bool queue_is_empty(queue*q)              //checks if queue is empty
     { return (q->front->head==NULL);}
     
     
     
     
     
     int dequeue(queue*q)                       //removing element from queue
     {  int t; 
     
       if(!queue_is_empty(q))
         { t=q->front->head->data;
           llist_remove_first( q->front );
           return t;
           }
           return -1;
           
           }
           
        int queue_size(queue*q)                  //returns size of queue
        
        {return llist_size( q->front );
        }
        
        void queue_print(queue*q)             //printing elem in q
        { 
            Node *t=q->front->head;
         
          while(t!=NULL)
             {  printf("%d ",t->data);
               t=t->next;
               }
           }   
           
           
           
   
     
