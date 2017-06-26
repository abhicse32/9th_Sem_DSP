//Program written by B.Nikhil Baba - CS15B008 on Sept 18th 2016
//Program written to evaluate a post-fix expression

#include<stdio.h>
#include<string.h>
#include "stack.c"
#include "List.c"
#define size 1000


//Evaluation function
void postfixevaluate(char* exp)
{
 int i = 0;
 int t = 0;
 stack* num = stack_new();//New stack
 for(i = 0; i < strlen(exp)  ;i++)
 {
  if(exp[i] >= '0' && exp[i] <= '9')
  { 
   t = 10*t + (exp[i]-'0');
  }
  if(exp[i] == ' ' && (exp[i-1] >= '0' && exp[i-1] <= '9'))
   { 
    stack_push(num,t);
    t = 0;
   }
  else if(exp[i] == '+')//additiom
   {
    int p = stack_pop(num);
    int q = stack_pop(num);
    stack_push(num,p+q);
   }
  else if(exp[i] == '-')//subtraction
   {
    int p = stack_pop(num);
    int q = stack_pop(num);
    stack_push(num,q-p);
   }
  else if(exp[i] == '*')//multiplication
   {
    int p = stack_pop(num);
    int q = stack_pop(num);
    stack_push(num,p*q);
   }
  else if(exp[i] == '/')//division
   {
    int p = stack_pop(num);
    int q = stack_pop(num);
    stack_push(num,q/p);
   }
  else if(exp[i] == '&')//bitwise and
   {
    int p = stack_pop(num);
    int q = stack_pop(num);
    stack_push(num,q/p);
   }
  else if(exp[i] == '|')//bitwise nor
   {
    int p = stack_pop(num);
    int q = stack_pop(num);
    stack_push(num,q/p);
   }
 else if(exp[i] == '^')//bitwise xor
   {
    int p = stack_pop(num);
    int q = stack_pop(num);
    stack_push(num,q/p);
   }
 
 
 }
 stack_print(num);
}
 

int main()
{
 char exp[size];
 int i=0;
 exp[0]=getchar();
 while(exp[i] != '\n')
 {
  i++;
  exp[i] = getchar();
 }

 postfixevaluate(exp);
 return 0;
}


