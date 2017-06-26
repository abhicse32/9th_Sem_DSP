// Lab Assignment 5 Question 2
// Minimum number of reversals such that given parentheses expression is valid
// Author : Milind Srivastava
// Date : 16 Sep 2016

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "stack.h"

int main()
{
    int k;
    scanf("%d", &k);
    
    while(k>0)
    {
        int left = 0; // number of left brackets
        int right = 0; // number of right brackets
        
        stack* expr = stack_new();
        
        char string[1000];
        scanf("%s", string);
        
        int i;
        for(i = 0; i < strlen(string); i++)
        {
            if(string[i] == '{') // left bracket
            {
                stack_push(expr, string[i]);
                left++;
            }        
            else // right bracket
            {
                if(stack_is_empty(expr)) // empty stack
                {
                    stack_push(expr, string[i]);
                    right++;
                }
                else
                {
                    int temp = stack_pop(expr);
                    if(temp == '{') // popped left bracket
                    {
                        left--;
                    }
                    else
                    {
                        stack_push(expr, temp);
                        stack_push(expr, string[i]);
                        right++;
                    }
                }
            }
        }
        
        // Now expr contains the union of illegal bracket expressions
        
        int size = stack_size(expr);
        
        int min = left;
        if(min > right)
        {
            min = right;
        }
        
        if(size%2 == 0)
        {
            if(min%2 == 0)
            {
                printf("%d\n", size/2);
            }
            else
            {
                printf("%d\n", size/2 + 1);
            }
        }
        else // if size is odd, we can't correct the expression by reversals
        {
            printf("-1\n");
        }
    
        k--;
    }
}
