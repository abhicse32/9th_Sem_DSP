#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int main()
{
     int j, i;
     for(j=0 ; j<10; j++)
     {
          stack* A = stack_new();
          int a ,b;
          char x; 
          char temp;       
          
          while(1)
          {
               x = getchar();
               
               if(x == '\n') break;
               
               switch(x)
               {
               
               case '&':
               {
                    a = stack_pop(A);
                    b = stack_pop(A);
                    stack_push(A, a&b);
                    break;
               }
               case '%':
               {
                    a = stack_pop(A);
                    b = stack_pop(A);
                    stack_push(A, b%a);
                    break;
               }
               case '^':
               {
                    a = stack_pop(A);
                    b = stack_pop(A);
                    stack_push(A, a^b);
                    break;
               }
               case '+':
               {
                    a = stack_pop(A);
                    b = stack_pop(A);
                    stack_push(A, a+b);
                    break;
               }
               case '-':
               {  
                    temp = getchar();
                    
                    if((temp != ' ')&&(temp != '\n'))
                    {
                    char arr[10];
                    arr[0] = temp;
                    
                    for(i=1;;i++)
                    {
                         temp = getchar();
                         if(temp == ' ' ) break;
                         arr[i] = temp;
                    }
                    
                    arr[i] = '\0';
                    stack_push(A,-1*( atoi(arr)));
                    }
                    else
                    {
                    a = stack_pop(A);
                    b = stack_pop(A);
                    stack_push(A, b-a);
                    }
                    break;
               }
               case '/':
               {
                    a = stack_pop(A);
                    b = stack_pop(A);
                    stack_push(A, b/a);
                    break;
               }
               case '*':
               {
                    a = stack_pop(A);
                    b = stack_pop(A);
                    stack_push(A, a*b);
                    break;
               }
               case '|':
               {
                    a = stack_pop(A);
                    b = stack_pop(A);
                    stack_push(A, b|a);
                    break;
               }
               
               case ' ': break;
               
               default:
               {
                    char arr[10];
                    arr[0] = x;
                    
                    for(i=1;;i++)
                    {
                         temp = getchar();
                         if(temp == ' ' ) break;
                         arr[i] = temp;
                    }
                    
                    arr[i] = '\0';
                    stack_push(A, atoi(arr));
                    break;
               }
               }
          }
          
          printf("%d\n",stack_pop(A));
     }
}
