#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

stack* stack_new()
{stack* s= (stack*)malloc(sizeof(stack));        //creating and initialising stack
  s->top=(LList*)malloc(sizeof(LList));
  s->top->head=NULL;
  return s;
  }
  
  bool stack_is_empty(stack*s)         //checks if stack is empty
  { return (s->top->head==NULL);}
  
  void stack_push(stack*s, int a)       //pushing element to stack
  {// Node *n= node_new( a);
    llist_prepend( s->top, a );
    }
    
    
    int stack_pop(stack *s)            //popping element out of stack   
    {  int t;
      if(!stack_is_empty(s))
       {t=s->top->head->data;
         s->top->head=s->top->head->next;
          return t;
                   }
          return -1;
          
          }
          
          
       int stack_size(stack *s)  //finding size of stack
       {int t,count=0;
        stack* s1=stack_new();
        
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
           
           
           
           void stack_print(stack*s)   //printing elements in stack
           {int t;
           
              stack* s1=stack_new();
        
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
           
           
           
           
           
         
        
          
