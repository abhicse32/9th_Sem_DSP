/*
  To find the next greater element for each element
  of the array in order of their appearance in the array
*/
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int t;
    scanf("%d",&t);                              //NO. OF TEST CASES
    stack *S;
    while(t > 0)
    {
        int max = 0;                             //KEEPING TRACK OF MAXIMUM ELEMENT
        int first = 0;                           //FIRST ELEMENT OF STACK
        int i;
        int n;
        scanf("%d",&n);
        int a[n];
        S = stack_new();                         //CREATING A NEW STACK
        for(i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
        }
        int b[n];
        for(i = (n-1);i > -1;i--)
        {
            if(stack_is_empty(S))                //PUSHING ARRAY'S LAST ELEMENT
            {
                b[i] = -1;                       //LAST ELEMENT OF OUTPUT IS ALWAYS -1
                stack_push(S,a[i]);
                max = a[i];
            }
            else
            {
                first = stack_top(S);            //OBTAIN FIRST ELEMENT
                stack_push(S,a[i]);
                if(a[i] >= max)
                {
                    max = a[i];
                    b[i] = -1;
                }
                else if(a[i] < first)            
                    b[i] = first;
                else
                {
                    int j;
                    for(j = 1;j<(n - i);j++)
                    {
                        if(a[i] < b[i + j])
                        {
                            b[i] = b[i + j];
                            break;
                        }
                    }
                }
            }
        }
        for(i = 0;i < n;i++)                     //PRINTING OUTPUT
        {
            printf("%d ",b[i]);
        }
        printf("\n");
        t--;
    }
    return 0;
}
