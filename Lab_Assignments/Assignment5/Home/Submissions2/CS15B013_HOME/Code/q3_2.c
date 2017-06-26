#include<stdio.h>
#include<string.h>
#include"stack.h"
#include<stdlib.h>

int main()
{
 int i=0,index,num;
 char a,arr[10];
 
 for(;i<10;i++)
 {
 stack * stk=stack_new();
 stack * new=stack_new();
 
 a=getchar();
 while(a!=10)
 {
   if(a==32)
   a=getchar();
 
  if(a=='+')
  {
    stack_push(stk,a);a=getchar();
  }
  
 if(a=='-')
  {
   a=getchar();
   if(a==32)
    stack_push(stk,'-');
   else
   {index=0;
   
    while(a!=32 && a!=10)
      {arr[index]=a;index++;
       a=getchar();
      }
    while(index<9)
       {arr[index]=32;index++;}
    int num=atoi(arr);   
    stack_push(stk,-1*num);     
   } 
  }
 if((a=='*' || a=='/' || a=='%' || a=='&' || a=='^' || a=='|') && a!=32 && a!=10) 
   {stack_push(stk,a);a=getchar();}
  else
  {
   if(a!=32 && a!=10)
   {index=0;
   while(a!=32 && a!=10)
     {arr[index]=a;index++;
       a=getchar();
      }
    while(index<9)
       {arr[index]=32;index++;}
    int num=atoi(arr);   
    stack_push(stk,num);
   
   }
  
   }
   

 }
  
   //if(!stack_is_empty(stk))
    //printf("empty\n");
   int x;int pop1,pop2;int ans;
   while(!stack_is_empty(stk))
     stack_push(new,stack_pop(stk));
     
     while(!stack_is_empty(new))
     {
      int x=stack_pop(new);
      
      if(x==43)
      {
       pop1=stack_pop(stk);
       pop2=stack_pop(stk);
       
       ans=pop2+pop1;
       stack_push(stk,ans);
       
      }
      else
      if(x==45)
      {
       pop1=stack_pop(stk);
       pop2=stack_pop(stk);
       
       ans=pop2-pop1;
       stack_push(stk,ans);
       
      }
      else      
            if(x==42)
      {
       pop1=stack_pop(stk);
       pop2=stack_pop(stk);
       
       ans=pop2*pop1;
       stack_push(stk,ans);
       
      }
      else
            if(x==47)
      {
       pop1=stack_pop(stk);
       pop2=stack_pop(stk);
       
       ans=pop2/pop1;
       stack_push(stk,ans);
       
      }
      else
            if(x==37)
      {
       pop1=stack_pop(stk);
       pop2=stack_pop(stk);
       
       ans=pop2%pop1;
       stack_push(stk,ans);
       
      }
      else
            if(x==38)
      {
       pop1=stack_pop(stk);
       pop2=stack_pop(stk);
       
       ans=pop2&pop1;
       stack_push(stk,ans);
       
      }
      else     
       if(x==94)
      {
       pop1=stack_pop(stk);
       pop2=stack_pop(stk);
       
       ans=pop2^pop1;
       stack_push(stk,ans);
       
      }
      else
      if(x==124)
      {
       pop1=stack_pop(stk);
       pop2=stack_pop(stk);
       
       ans=pop2|pop1;
       stack_push(stk,ans);
       
      }
      else
      stack_push(stk,x);
        
     } 
     
    printf("%d\n",stack_pop(stk)); 
 }
}










