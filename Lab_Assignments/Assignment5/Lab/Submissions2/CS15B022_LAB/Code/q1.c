#include<stdio.h>
#include"stack.h"
#include"List.h"
#include<stdlib.h>
int bracketsaretrue(char brackets[1000]);
void main()
{   
    int n;
    scanf("%d",&n);
    int j;
    int i = 0;
    for(i = 0;i<n;i++)
    {
        char brackets[1000];
        scanf("%s",brackets);
        j = bracketsaretrue(brackets);
        printf("%d\n",j);
    }
}
int bracketsaretrue(char brackets[1000])
{
    stack *stack = stack_new();
    int i = 0;
    for(i = 0;i<1000 && brackets[i] != '\0';i++)
    {
        if(brackets[i] == '{')
        {
            if(stack_is_empty(stack) == true)
            {
                stack_push(stack,brackets[i]);
            }
            else
            {
                if(((stack->top)->head)->data == '}')
                {
                    return 0;
                }
                else
                {
                    stack_push(stack,brackets[i]);
                }
              }
              continue;
          }
          if(brackets[i] == '(')
          {
            if(stack_is_empty(stack) == true)
            {
                stack_push(stack,brackets[i]);
             }
             else
             {
                if(((stack->top)->head)->data == ')')
                {
                    return 0;
                }
                else
                {
                    stack_push(stack,brackets[i]);
                }
              }
              continue;
           }
           if(brackets[i] == '[')
          {
            if(stack_is_empty(stack) == true)
            {
                stack_push(stack,brackets[i]);
             }
             else
             {
                if(((stack->top)->head)->data == ']')
                {
                    return 0;
                }
                else
                {
                    stack_push(stack,brackets[i]);
                }
              }
              continue;
           }
           if(brackets[i] == '}')
           {
                if(stack_is_empty(stack) == true)
                {
                    return 0;
                }
                else
                {
                    if(stack->top->head->data == '{')
                    {
                        stack_pop(stack);
                    }
                    else
                    {
                        stack_push(stack,brackets[i]);
                    }
                  }
                  continue;
               }
             if(brackets[i] == ')')
           {
                if(stack_is_empty(stack) == true)
                {
                    return 0;
                }
                else
                {
                    if(stack->top->head->data == '(')
                    {
                        stack_pop(stack);
                    }
                    else
                    {
                        stack_push(stack,brackets[i]);
                    }
                  }
                  continue;
               }
              if(brackets[i] == ']')
           {
                if(stack_is_empty(stack) == true)
                {
                    return 0;
                }
                else
                {
                    if(stack->top->head->data == '[')
                    {
                        stack_pop(stack);
                    }
                    else
                    {
                        stack_push(stack,brackets[i]);
                    }
                  }
                  continue;
               }
    }
    if(stack_is_empty(stack) == true)
    {
        return 1;
    }
    else
    {
        return 0;
    }
 }
     
                
                  

        
        
