#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "stack.h"
#include "stack.c"
#include "List.c"
int Max = 1000;
int main()
{
   int T,i; 
   scanf("%d",&T);
   for(i =0;i<T;i++)   // for T test cases
   {
       int count=0,j = 0;
       char S[Max];
       scanf("%s",S);
       stack* st = stack_new();
       for(;S[j] != '\0';j++)
       {
           if(stack_is_empty(st))
           {
               if(S[j] == '{') stack_push(st,1);
               else
               {
                   count++;           // increase count by 1 if starting char is '}' and revrse it 
                   stack_push(st,1);
               }
           }
           else
           {
               if(S[j] == '{') 
               {
                  stack_push(st,1);
               }
               else stack_pop(st);
           }
       }
       if(stack_is_empty(st))        //if stack is empty print count
       {
           printf("%d",count);
       }
       else
       {
           int m;
           m = stack_size(st);
           if(m % 2 == 0)              // if m even no of 1's are remaining count = count+m/2 
           {
                printf("%d",count+m/2);
           } 
           else printf("-1");          // if m is odd print -1
       }
       printf("\n");
    }
    return 0;
}    
               
               
               
               
               
