// Lab Assignment 1 Question 2
// Finding min and max of an array of integers in minimum number of comparisons
// Author : Milind Srivastava
// Date : 8 Aug 2016

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{   
    int n;
    scanf("%d",&n);
    int* arrPtr = (int*)malloc(n*sizeof(int)); // Allocating memory for n integers
    
    int i;
       
    for(i=0;i<n;i++) // Inputting values of n integers
    {
        scanf("%d",&arrPtr[i]);
    }
    
    // Allocating space for winner and loser elements
    
    int* winners = (int*)malloc((n/2+1)*sizeof(int));
    int* losers = (int*)malloc((n/2+1)*sizeof(int));
    
    // Assigning last elements of "winners" and "losers" appropriately
    // If number of elements is even, the last elements of the arrays have been assigned such that they'll have no effect on the actual max/min value
    // If number of elements is odd, the last elements of the arrays will be overwritten
    
    winners[n/2] = INT_MIN;
    losers[n/2] = INT_MAX;
    
    for(i=0;i<n;i+=2)
    {
        if(i+1 != n) // If number of elements is even
        {
            if(arrPtr[i]>arrPtr[i+1])
            {
                winners[i/2] = arrPtr[i];
                losers[i/2] = arrPtr[i+1];
            }
            else
            {
                winners[i/2] = arrPtr[i+1];
                losers[i/2] = arrPtr[i];
            }
        }
        else // If number of elements is odd
        {
            winners[i/2] = arrPtr[i];
            losers[i/2] = arrPtr[i];
        }
    }
    
    int j,k; //counters for "winners" and "losers" arrays
    
    // Calculating max
    
    int max = winners[0];
    for(j=0;j<n/2+1;j++)
    {
        if(winners[j] > max)
        {
            max = winners[j];
        }
    }
    
    // Calculating min
    
    int min = losers[0];    
    for(k=0;k<n/2+1;k++)
    {
         if(losers[k] < min)
         {
             min = losers[k];
         }
    }
    
    printf("%d %d", min, max); // Print min and max
    
    // Free dynamically allocated memory
    
    free(arrPtr);
    free(winners);
    free(losers);
    
    return 0;
}
