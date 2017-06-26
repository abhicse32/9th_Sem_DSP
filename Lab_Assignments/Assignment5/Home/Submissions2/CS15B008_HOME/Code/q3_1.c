//This program is written by B.Nikhil Baba -CS15B008 on Sept 18th 2016
//The code converts infix expression to postfix expression

#include<stdio.h>
#include<string.h>
#include "stack_a.c"
#define size 1000

int Operand(char x)
{
 if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
 {
  return 1;
 }
 else
 { 
  return 0;
 }
} 

//Assigning order to operators
int Order(char x)
{
 if(char == '+' || char == '-')
 {
  return 1;
 }
 else if(char == '*' || char == '/' || char == '%')
 {
  return 2;
 }
 else if(char == '^')
 {
  return 3;
 }
 else if(char == '&')
 {
  return 4;
 }
 else
 {
  return -1;
 }
}


//Conversion function
void InToPost(char* exp)
{
 stack *oper = stack_new();
 int i,stackcount;
 for(i = 0,stackcount = -1;i<strlen(exp);i++)
 { 
  if(Operand(exp[i]) == 1)
  {
   stackcount++;
   exp[stackcount] = exp[i];                                            //Adding to ethe expression if it an alphabet
  }
  else if(exp[i] == '(' )
  { 
   stack_push(oper,exp[i]);
  }
  else if(exp[i] == ')' ) //If bracket is closing remove all the elements
  {
    while(stack_is_empty(oper) != 1 && oper->arr[oper->top] != '(' ) 
    {
     stackcount++;
     exp[stackcount] = stack_pop(oper);
    }
    if(stack_is_empty(oper) != 1 && oper->arr[oper->top] != '(')
    { 
     return -1;
    }
    else 
    {
     stack_pop(oper);
    }
  }
  else //If it is an operator?
  {
   while(stack_is_empty(oper) != 1 && Order(exp[i]) <= Order(oper->arr[oper->top])) //Checking the priority
   {
     stackcount++;
     exp[stackcount] = stack_pop(oper);
   }
   stack_push(oper,exp[i]);
  }
 }
 while( stack_is_empty(oper) != 1)
 {
  stackcount++;
  exp[stackcount] = stack_pop(oper);
 }
 stackcount++;
 exp[stackcount] = '\0';
 printf("%s",exp);
}

//Main function
int main()
{
 char expression[size];
 scanf("%s",expression);
 //Scaning the string of characters
 InToPost(expression);  
 return 0;                 
}

//finding whethet the character is alphabet or not


//End of function  
 


 
