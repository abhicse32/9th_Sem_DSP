//CS15B013 next maximum

#include<stdio.h>
#include "stack.h"

int main()
{ 
  int cases,size,i,val,ref,first,next,cond=0;
  scanf("%d",&cases);
  
  for(;cases>0;cases--)
  {
   stack * temp=stack_new();       //new stack
   stack * stk=stack_new();
   stack * ans=stack_new();
   scanf("%d",&size);
   for(i=0;i<size;i++)
    {
     scanf("%d",&val);            
     stack_push(temp,val);        //initialising stack
    } 
   while(!stack_is_empty(temp)) 
    stack_push(stk,stack_pop(temp));
    
   while(!stack_is_empty(stk))  
   {
    ref=stack_pop(stk);
    if(!stack_is_empty(stk))      //if stack has only one element
     {
      first=stack_pop(stk);
      stack_push(temp,first);
        
      while(first<=ref )          //finding next greatest number
      {

       
       if(stack_is_empty(stk))
         break;
       else
       {
       first=stack_pop(stk);
       stack_push(temp,first);
       }
      }
      if(!stack_is_empty(stk))
       {stack_push(ans,first);     //pushing greatest number
       }
      else
        {
         if(first>ref)
          stack_push(ans,first);
         else 
         stack_push(ans,-1);
        }
    while(!stack_is_empty(temp)) 
    stack_push(stk,stack_pop(temp));
           
     }
    else
      stack_push(ans,-1);
   }

   while(!stack_is_empty(ans)) 
    stack_push(stk,stack_pop(ans));   
   
   stack_print(stk);                  //printing stack
   printf("\n");
  }
}																																																																																																																																																																																																				 
