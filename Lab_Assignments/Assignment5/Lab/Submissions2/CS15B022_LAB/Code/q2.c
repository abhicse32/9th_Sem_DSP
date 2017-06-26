#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"List.h"
int minimumchanges(char brackets[1005]);
void main()
{
    int n;
    scanf("%d",&n);
    int i = 0;
    int j = 0;
    int k;
    for(i = 0;i<n;i++)
    {
        char brackets[1005];
        scanf("%s",brackets);
        j = 0;
        for(j = 0;brackets[j] != '\0';j++)
        {
        }
        if(j%2 == 1)
        {
            printf("%d\n",-1);
        }
        else
        {
          k = minimumchanges(brackets);
          printf("%d\n",k);
        }
     }
}
int minimumchanges(char brackets[1005])
{
    stack *stack = stack_new();
    int counter = 0;
    int i;
    for(i = 0;brackets[i] != '\0';i++)
    {
        if(brackets[i] == '{')
        {
            stack_push(stack,brackets[i]);
        }
        else 
        {
            if(brackets[i] == '}')
            {
                if(stack_is_empty(stack) == true)
                {
                    brackets[i] = '{';
                    counter = counter + 1;
                    stack_push(stack,brackets[i]);
                }
                else
                {
                    if(stack->top->head->data == '{')
                    {
                        stack_pop(stack);
                     }
                 }
              }
           }
      }
      if(stack_is_empty(stack) == true)
      {
        return counter;
      }
      if(stack_is_empty(stack) == false)
      {
        int m = stack_size(stack);
        return (counter + (m/2));
      }
}
 
