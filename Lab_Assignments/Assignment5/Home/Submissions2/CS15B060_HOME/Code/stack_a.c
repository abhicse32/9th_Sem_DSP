#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000


stack* stack_new()                    //creating and initialising stack
{
  stack *s=(stack*)malloc(sizeof(stack));
  s->arr=(int*)malloc(sizeof(int)*size);
  s->top=-1;
  return s;
  
  }
  
  void stack_push(stack*s, int a)//pushing element to stack
  {
     if(!stack_is_full(s))
     { s->top++; 
      s->arr[s->top]=a;
      }
      }
      
      
    int stack_pop(stack*s)       //popping element out of stack
    {
       if(!stack_is_empty(s))
     { return(s->arr[s->top--]); 
      
      } 
       
       return -1;
       
       }
       
       
       bool stack_is_empty(stack*s)  //checks if stack is empty
       {return(s->top==-1);}
       
       bool stack_is_full(stack*s)   //checks if stack is full
       {return(s->top==size-1);
       }
       
       
       int stack_size(stack*s)       //finding size of stack
       { stack*s1=stack_new();
         int t,count=0;
         while(!stack_is_empty(s))
         { t=stack_pop(s);
           stack_push(s1,t);
           count++;
           }
           
         while(!stack_is_empty(s1))
         { t=stack_pop(s1);
           stack_push(s,t);
           
           }  
           return count;
           
           }
           
           void stack_print(stack*s)     //printing elements in stack
           {stack*s1=stack_new();
         int t,count=0;
         while(!stack_is_empty(s))
         { t=stack_pop(s);
           stack_push(s1,t);
            printf("%d ",t);
           }
           
         while(!stack_is_empty(s1))
         { t=stack_pop(s1);
           stack_push(s,t);
           
           } 
           
           } 
           
           
           
       
  
