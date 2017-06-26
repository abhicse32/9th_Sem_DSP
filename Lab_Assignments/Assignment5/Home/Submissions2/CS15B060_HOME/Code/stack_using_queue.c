#include<stdio.h>
#include<stdlib.h>//program for implementing stack oprns using queue
#include"List.h" 
#include"queue.h"   //note:here i am assuming when i give pop(),i print the status of stack itself,not popped element
#include<string.h>   //because it is given as an example in question
#define BUFF_SIZE 20


int pp;
                            //all the basic queue inplementations copied from queue.c

           
            void reverseq(queue *p,queue *q)   //function for reversing queue
            
            { int x;                            //reversing q is nesessary as stack is LIFO whereas queue is FIFO 
              if(queue_size(q)>=1)
              {x=dequeue(q);
               
                reverseq(p,q);
                 enqueue(p,x);
                
                 }
                 
                 }
                 
                 void normqueue(queue *p,queue *q)  //function created to copy queue Q to queue P
                 { int x,i;
                     i=0;
                  while(i<queue_size(q))
              {x=dequeue(q);
                
                 enqueue(p,x);
                 enqueue(q,x);
                  i++;
                 }
                 }
           
           
           
           
           
           
           
           queue* push(queue *q,int a)   //pushing element using series of reversing,copying of queues
           {queue *p=queue_new();
            queue *s=queue_new();
                enqueue(q,a);
              
                normqueue(s,q);
              
                reverseq(p,q);
                 normqueue(q,s);
                 return p;
                 
                 }
                 
                  
           queue* pop(queue *q)  //function for simulating pop() using queue
           {queue *p=queue_new();
            queue *s=queue_new();
            queue *r=queue_new();
               
               normqueue(s,q);
                reverseq(p,q);
               
                int x=dequeue(p);
                pp=x;
                 normqueue(r,p);
                 q=queue_new();
                 reverseq(q,p);
                
                 return r;
                 
                 } 
                 
                 
                 int fpp()
                 {return pp;}
                
                
                
                
                
                
                
                
                
                
                
