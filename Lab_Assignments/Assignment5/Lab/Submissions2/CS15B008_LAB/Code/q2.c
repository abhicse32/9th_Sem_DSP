//Program written by B.Nikhil Baba on Sept 16th,2016- Lab assignment 5
//Code written to calculate minimum number of alterations to make a bracket series valid.

#include<stdio.h>
#include"stack.h"
#include"stack.c"
#include<string.h>
#include"List.h"
#include"List.c"
//Calling all the header files.

//Reversal sum function
int Reversalnum(char* s)
 {
  int t = strlen(s);
  if(t%2 == 1)
  {
   return -1;
  }
  //New stack for remaining parenthesis
  stack* parenthesis = stack_new();               
  int j,count;
  count = 0;
  for(j = 0;j < t;j++)
  {     //123 ='{' and 125 = '}'
   	if(s[j] == 123)
        {
         	stack_push(parenthesis,123);
        }
        else if(s[j] == 125)
        {  
         	if(stack_is_empty(parenthesis) == 1)
                {
                 	count++;
                        stack_push(parenthesis,123);
                }
                else 
                 {
                  	stack_pop(parenthesis) == 123;
                 }
                 
              
                
        }
  }
  //Remaining '{' in stack require  a minimum of stack_size/2 alterations
  return (count+(stack_size(parenthesis))/2);
 }

//Main function.
int main()
{
 int t,i;
 scanf("%d",&t);
 for(i = 0;i < t;i++)
 {
  	char s[1000];
  	scanf("%s",s);
  	Reversalnum(s);
  	printf("%d\n",Reversalnum(s));
 }
 return 0;
}


     	
    
    
