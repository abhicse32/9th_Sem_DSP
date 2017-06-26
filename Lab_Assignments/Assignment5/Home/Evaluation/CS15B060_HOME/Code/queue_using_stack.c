#include<stdio.h>
#include<stdlib.h>    //program for implementing queue oprns using stack
#include"List.h"       //note:here i am assuming when i give dequeue(),i print the status of queue itself,not dequeued element
#include<string.h>      //because it is given as an example in question 
#define BUFF_SIZE 20

typedef struct Stack{       //using the same stack defn defined in stack.c
	LList* top;
}stack;

stack* stack_new()
{stack* s= (stack*)malloc(sizeof(stack));
  s->top=(LList*)malloc(sizeof(LList));
  s->top->head=NULL;
  return s;
  }
  
  int stack_is_empty(stack*s)
  { return (s->top->head==NULL);}
  
  void stack_push(stack*s, int a)
  {
    llist_prepend( s->top, a );
    }
    
    
    int stack_pop(stack *s)
    {  int t;
      if(!stack_is_empty(s))
       {t=s->top->head->data;
         s->top->head=s->top->head->next;
          return t;
                   }
          return -1;
          
          }
          
          
       int stack_size(stack *s)
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
           
           
           
           void stack_print(stack*s)
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
                   s2=revstk(s1);
                   s1=revstk(s2);
                 
                 
                   return s1;                 
                 }
                 
                 
                 
                 void main()          //main fn to implement queue oprns just like format in prev question
                  { stack *q=stack_new();
                   stack *p=stack_new();
                    
             
                int n;
                char str[BUFF_SIZE];
	
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"enqueue")){
			int data=atoi(strtok(NULL," "));
			
                        p=enqueue(q,data);
                        stack_print(p);
                         q=revstk(p);

		}else if(!strcmp(temp,"size"))
			printf("%d",stack_size(p));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",stack_is_empty(p));
		else if(!strcmp(temp,"dequeue"))
			{//printf("%d", dequeue(que));
			p=dequeue(q);
                        stack_print(p);
                        q=revstk(p);
			}
		printf("\n");
	}
                
                
                
                
                
                
                } 
           
