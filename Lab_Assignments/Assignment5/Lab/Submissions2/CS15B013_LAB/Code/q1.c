//CS15B013 checking paranthesis


#include<stdio.h>
#include "stack.h"

int main()
{
 int cases,size=0,i;
 scanf("%d",&cases);
 char * val;int a;
 char popped;
 int b=0;
 for(;cases>0;cases--)
 {stack * stk=stack_new();
  scanf("%s",val);                //initialisation
  b=0;a=1;
  for(i=0;b==0;i++)
  { 
      if(val[i]=='\0')             //end of string 
        break;
        
    if(stack_is_empty(stk))
    {
     if(val[i]==']' || val[i]=='}' || val[i]==')')
       a=0;
     else
       {stack_push(stk,val[i]);a=1;}
    }
    else
    {
     switch(val[i])                     //executes if stack is not empty
     {
      case '{':stack_push(stk,val[i]);
               a=1;
               break;
      case '(':stack_push(stk,val[i]);
               a=1;
               break;
      case '[':stack_push(stk,val[i]);
               a=1;
               break;
      case '}':popped=stack_pop(stk);
               if(popped=='(' || popped=='[')
                 a=0;
               if(popped=='{')
                 a=1;
               break; 
      case ')':popped=stack_pop(stk);
               if(popped=='{' || popped=='[')
                 a=0;
               if(popped=='(')
                 a=1;
               break;
      case ']':popped=stack_pop(stk);
               if(popped=='(' || popped=='{')
                 a=0;
               if(popped=='[')
                 a=1;
               break;
      }
     }

    if(a==0)                    //not in order
     { printf("0\n");break;}
    

    
  }

  if(stack_is_empty(stk) && a==1)  //it is in order
    printf("1\n");
 }
 
}
