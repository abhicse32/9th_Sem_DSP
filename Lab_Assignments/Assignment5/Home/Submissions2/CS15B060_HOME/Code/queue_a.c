#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

queue* queue_new()                             //creating and initialising queue
{queue *q=(queue*)malloc(sizeof(queue));
  q->arr=(int*)malloc(size*sizeof(int));
  q->front=0;
  q->rear=size-1;
  return q;
  }
  
  void enqueue(queue*q, int a)             //adding element to queue
  {if(!queue_is_full(q))
    { if(q->rear==size-1)
       q->rear=0;
        else
         q->rear++;
         q->arr[q->rear]=a;
        
         }
         }
         
      int dequeue(queue*q)                //removing element from queue
      { if(!queue_is_empty(q))
    {  int t=q->arr[q->front];
      if(q->front==size-1)
       q->front=0;
        else
         q->front++;
         return t;
         }
         return -1;
         } 
         
         
       bool  queue_is_empty(queue*q)        //checks if queue is empty
         { int re;
            if(q->rear==size-1)
             re=0;
             else
             re=q->rear+1;
             return (re==q->front);
             
             }
             
             bool queue_is_full(queue*q)      //checks if queue is full
         { int re;
            if(q->rear==size-1)
             re=1;
             else if(q->rear==size-2)
              re=0;
             else
             re=q->rear+1;
             return (re==q->front);
             
             }
             
             
             int queue_size(queue*q)         //returns size of queue that can be done using simple formula that can be self generated
             { int c=(q->rear-q->front+1+size)%size;
               return c;
               }
               
               void queue_print(queue*q)    //printing elem in q
               {int i;
                  if(q->front<=q->rear)
                   for(i=q->front;i<=q->rear;i++)
                    printf("%d ",q->arr[i]);
                    
                    else
                    {
                      for(i=q->front;i<size;i++)
                      printf("%d ",q->arr[i]);
                      for(i=0;i=q->rear;i++)
                      printf("%d ",q->arr[i]);
               
                      }
                      
                      }
               
             
             
       
  
