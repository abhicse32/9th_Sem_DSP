//CS15B013 Making curly braces valid

#include<stdio.h>
#include "stack.h"

int main()
{ 
 int cases,i,count;char no;
 scanf("%d",&cases);
 char * val;
 
 for(;cases>0;cases--)
 {stack * stk=stack_new();    //creating new stack
  scanf("%s",val); 
  
  for(i=0;val[i]!='\0';i++)   //i contains size after exiting loop
   {}
   
  if(i%2==0)                  //if no of paranthesis are even
 { for(i=0,count=0;;i++)
  {
   if(val[i]=='\0')
     break;
  
   if(stack_is_empty(stk))   // if stack is empty
   {
    if(val[i]=='{')            
     stack_push(stk,val[i]);
    else
     {val[i]='{';
      count++;stack_push(stk,val[i]); //incrementing count
     } 
   }
   else
   {
    if(val[i]=='{')   
      stack_push(stk,val[i]);
    else
      {
       no=stack_pop(stk);
      
      }
   }
  }
   count=count+stack_size(stk)/2;    //incrementing count
 printf("%d\n",count); 
 }
  else 
  {printf("-1\n");}         //if no of parathesis is odd
  

 }
}
