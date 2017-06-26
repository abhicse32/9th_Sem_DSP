// Lab Assignment 5 Question 3
// Next larger element
// Author : Milind Srivastava
// Date : 16 Sep 2016

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "List.h"
#include "stack.h"

int main()
{
    int k;
    scanf("%d", &k);
    
    while(k>0)
    {
        int size;
        scanf("%d", &size); // size of arr
        int* arr = (int*)malloc(size*sizeof(int));
        int i;
        for(i = 0; i < size; i++)
        {
            scanf("%d", &arr[i]); // take input
        }
        
        // declare 3 stacks
        
        stack* ind1 = stack_new();
        stack* ind2 = stack_new();
        stack* val = stack_new();
        
        /* if arr value of i is greater tham arr value of index on top of ind1, pop it, push it to ind2 and push arr value of i onto val; keep repeating till either ind1 is empty or arr value of i is less than arr value of index on top of ind1; then push i*/

        for(i = 0; i < size; i++) 
        {
            if(stack_is_empty(ind1))
            {
                stack_push(ind1, i);
            }
            else
            {
                int temp = stack_pop(ind1);
                while(true)
                {
                    if(arr[i] > arr[temp])
                    {
                        stack_push(ind2, temp);
                        stack_push(val, arr[i]);
                        if(stack_is_empty(ind1))
                        {
                            stack_push(ind1, i);
                            break;
                        }
                        else
                        {
                            temp = stack_pop(ind1);
                        }
                    }
                    else
                    {
                        stack_push(ind1, temp);
                        stack_push(ind1, i);
                        break;
                    }
                }
            }
        }
        while(!stack_is_empty(ind1)) // pop elements from ind1, push them to ind2 and push -1 to val for all corresponding popped elements
        {
            int temp = stack_pop(ind1);
            stack_push(ind2, temp);
            stack_push(val, -1);
        }
        while(!stack_is_empty(ind2)) // modify original array according to the indices popped from ind2 and values popped from val
        {
            int index = stack_pop(ind2);
            int arrVal = stack_pop(val);
            arr[index] = arrVal;
        }        
        for(i = 0; i < size; i++) // print array
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        free(arr);
        k--;
    }
    
    return 0;
}
