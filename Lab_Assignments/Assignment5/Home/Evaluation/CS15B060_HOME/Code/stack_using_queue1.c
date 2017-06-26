#include<stdio.h>
#include<stdlib.h>//program for implementing stack oprns using queue
#include"List.h"    //note:here i am assuming when i give pop(),i print the status of stack itself,not popped element
#include<string.h>   //because it is given as an example in question
#define BUFF_SIZE 20
typedef struct Queue{
	LList* front;
	LList* rear;
}queue;


                            //all the basic queue inplementations copied from queue.c
queue* queue_new()
{ queue* q=(queue*)malloc(sizeof(queue));
   q->front=(LList*)malloc(sizeof(LList));
   q->front->head=NULL;
  
   q->rear=(LList*)malloc(sizeof(LList));
   q->rear->head=NULL;
   
   return q;
   
   }
   
   void enqueue(queue*q, int a)
   {
     llist_append( q->front, a );
     if(queue_size(q)==1)
     {q->rear->head=q->front->head;}
     else
     {q->rear->head=q->rear->head->next;} 
   
     }
     
     
     int queue_is_empty(queue*q)
     { return (q->front==NULL);}
     
     
     
     
     
     int dequeue(queue*q)
     {  int t; 
     
       if(!queue_is_empty(q))
         { t=q->front->head->data;
           llist_remove_first( q->front );
           return t;
           }
           return -1;
           
           }
           
           
            int queue_size(queue*q)
        
        {return llist_size( q->front );
        }
        
        void queue_print(queue*q)
        { 
            Node *t=q->front->head;
         
          while(t!=NULL)
             {  printf("%d ",t->data);
               t=t->next;
               }
           }   
           
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
                
                 normqueue(r,p);
                 q=queue_new();
                 reverseq(q,p);
                
                 return r;
                 
                 } 
                 
                 
                 void main()  // main() follows same i/o oprns like stack
                 { queue *q=queue_new();
                   queue *p=queue_new();
                    
                   int c,n;
               
                
                char str[BUFF_SIZE];
	
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"push")){
			int data=atoi(strtok(NULL," "));
			
			 p=push(q,data);
             queue_print(p);
			
			
			}
            else if(!strcmp(temp,"pop"))
			{p=pop(q);
             queue_print(p);
              reverseq(q,p);}
              
              else if(!strcmp(temp,"size"))
			printf("%d",queue_size(q));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",queue_is_empty(q));
              
              
              
              
              
		printf("\n");
	}
       
       
       }         
                
                
                
                
                
                
                
                
                
                
                
                
                
