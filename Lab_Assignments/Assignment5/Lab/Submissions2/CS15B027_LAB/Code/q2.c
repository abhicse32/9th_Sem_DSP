#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"
#include"stack.h"
int main()
{

  int i,j,k,l,t;
  scanf("%d",&t);                               //taking input no of test cases
  for(i=0;i<t;i++)
  {
     char str[1000];
     scanf("%s",str);                     
     int l = strlen(str);
     if(l%2 != 0)                             //if input string length is odd printing -1
     {
       printf("-1\n");
       continue;
     }
     stack *p = stack_new();
     stack_push(p,str[0]);
        for(j=1;j<l;j++)                         // pushing string into stack such that left and right that are consecutive will be popped out
        {
          if(str[j] == '{')
          stack_push(p,str[j]);
          else if(stack_is_empty(p) != 1)
          {
           char temp = stack_pop(p);
           if(temp != '{' && str[j] == '}')
           {
               stack_push(p,temp);
               stack_push(p,str[j]);
               continue;
           }
            
          }
          else if(stack_is_empty(p) == 1)   stack_push(p,str[j]);
        }                                                    //we minimized the stack here by popping some out
        int s = stack_size(p);
        l=0;
        for(k=0;k<s;k++)
        {
          int x = stack_pop(p);                           //counting no of left brackets
          if(x == '{')
          l++;
        }
        if(l%2==0)
        {
          printf("%d\n",(s/2));
        }
        else
        {
          printf("%d\n",(l/2)+(s-l)/2+2);
        }
       }
  return 0;
}
