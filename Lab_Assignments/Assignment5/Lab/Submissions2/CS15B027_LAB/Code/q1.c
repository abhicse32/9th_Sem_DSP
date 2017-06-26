#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"
#include"stack.h"
int main()
{
  int i,j,t;
  scanf("%d",&t);                          //taking input no of test cases
  for(i=0;i<t;i++)
  {
     char str[1000];
     scanf("%s",str);
     int l = strlen(str);
     stack *p = stack_new();
     stack_push(p,str[0]);
     if(str[0] == '}' || str[0] == ']' || str[0] == ')')    //checking two exterme cases
     {
       printf("0\n");
       continue;
     }
     if(str[l-1] == '{' || str[l-1] == '[' || str[l-1] == '(')
     {
       printf("0\n");
       continue;
     }
        for(j=1;j<l;j++)
        {
          if(str[j] == '{' || str[j] == '[' || str[j] == '(')
          stack_push(p,str[j]);
          else
          {
           char temp = stack_pop(p);
           if(temp != '[' && str[j] == ']')
           {
               stack_push(p,temp);
                 printf("0\n");
               break;
           }
           if(temp != '{' && str[j] == '}')
           {
               stack_push(p,temp);
               printf("0\n");
               break;
           }
           if(temp != '(' && str[j] == ')')
           {
               stack_push(p,temp);
                printf("0\n");
               break;
           }
          }
        }if(j==l)
         printf("1\n");
  }
        return 1;
}
