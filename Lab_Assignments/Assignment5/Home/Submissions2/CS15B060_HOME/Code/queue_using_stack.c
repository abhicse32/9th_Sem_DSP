#include<stdio.h>
#include<stdlib.h>    //program for implementing queue oprns using stack
#include"List.h"       //note:here i am assuming when i give dequeue(),i print the status of queue itself,not dequeued element
#include<string.h>      //because it is given as an example in question 
#include"stack.h"
#define BUFF_SIZE 20
int pp;


           
            stack* revstk(stack *s)   //this is operation involving reversing stack using push,pop fns alone
            { int n;
              stack *s1=stack_new();
              
              while(!stack_is_empty(s))
              {n=stack_pop(s);
                stack_push(s1,n);
                }
                return s1;
                }
              
           
           
           
           stack* enqueue(stack *s,int n)   //enqueueing element by combination of adding elem and reversing using revstk()
           { stack *s1=stack_new();
              int i;
              
              stack_push(s,n);
              s1=revstk(s);
              
               return s1;              //returning the stack newly generated
               }
               
               stack* dequeue(stack *s)  //it follows series of reversing ,popping out element
               { stack *s1=stack_new();
                  stack *s2=stack_new();
                int i;
                 
                   s1=revstk(s);
                   i=stack_pop(s1);
                   pp=i;
                   s2=revstk(s1);
                   s1=revstk(s2);
                 
                 
                   return s1;                 
                 }
                 int fpp()
                 {return pp;}
                 
                 
                
