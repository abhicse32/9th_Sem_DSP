#include<stdio.h>
#include<stdlib.h>
#include "List.h"
#include "stack.h"
#include "stack.c"
#include "List.c"
int Max = 1000;
int main()
{
   int T,i; 
   scanf("%d",&T);
   for(i =0;i<T;i++)
   {
       int j = 0;
       char S[Max];
       scanf("%s",S);
       stack* st = stack_new();
       for(;S[j] != '\0';j++)
       {
           if(S[j] == '[') stack_push(st,1);  // if char is [ push 1
           else if(S[j] == '(') stack_push(st,2); // if char is ( push 2
           else if(S[j] == '{') stack_push(st,3);  // if char is { push 3
           else if(S[j] == ']')
           {
                if(stack_is_empty(st) != 1)
                {
                     if(st->top->head->data == 1)
                     {
                         stack_pop(st);
                     }
                     else break;  //if closing char is not matching with st->top->head->data then break
                }
                else     
                {
                     stack_push(st,1);
                     break;    // if stack is empty and char is closing break
                }
           }
           else if(S[j] == ')')
           {
                if(stack_is_empty(st) != 1)
                {
                     if(st->top->head->data == 2)
                     {
                         stack_pop(st);
                     }
                     else break;  //if closing char is not matching with st->top->head->data then break
                }
                else 
                {
                     stack_push(st,1);
                     break;    // if stack is empty and char is closing break
                }
           }
           else if(S[j] == '}')
           {
                if(stack_is_empty(st) != 1)
                {
                     if(st->top->head->data == 3)
                     {
                         stack_pop(st);
                     }
                     else break;   //if closing char is not matching with st->top->head->data then break
                }
                else 
                {
                     stack_push(st,1);
                     break;   // if stack is empty and char is closing break
                }
           }
        }
        if(stack_is_empty(st))  // if stack is empty print 1
        {
           printf("1");
        }
        else
        {
            printf("0");     
        }
        printf("\n");
    }
 }
                                  
