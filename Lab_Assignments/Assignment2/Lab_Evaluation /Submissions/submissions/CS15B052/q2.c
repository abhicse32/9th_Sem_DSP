// Lab Assignment 2 Question 2
// Printing all n! permuations of a set of n numbers
// Author : Milind Srivastava
// Date : 18 Aug 2016

#include <stdio.h>
#include <stdlib.h>

void nextPerm(int*, int);

int fact(int);

int compare (const void * a, const void * b) // compare function for qsort
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int n;
    scanf("%d",&n);
    
    int input[9]; // array to hold inputs
        
    int i;
    int count = 0;
    int flag = 0;
    for(i=0;i<n;i++)
    {
        int temp;
        scanf("%d",&temp);
        
        int j;
        for(j=0;j<count;j++)
        {
            if(temp == input[j]) // checking for duplicate inputs
            {
                flag = 1;
                break;
            }
               
        }
        if (flag == 0)
        {
            input[count] = temp; // if no duplicate, add inputted value to array
            count++;
        }
        else
        {
            flag = 0;
        } 
    }
    
    qsort (input, count, sizeof(int), compare); // sort the given values
    
    for (i=0;i<count;i++)
    {
        printf("%d", input[i]);
    }
    printf(" ");
    
    if (count != 1)
        nextPerm (input, count);
        
    printf("\n");
    return 0;
}

void nextPerm(int* input, int n) // calculates next permutation 
{
    static int funcCount = 0; // number of times function has been executed 
    int i = n-1;
    while (input[i] < input[i-1])
    {
        --i;
    }
    int swapIndex1 = i-1;
    i = n-1;
    while(input[i] < input[swapIndex1])
    {
        --i;
    }
    int swapIndex2 = i;
    
    int temp1 = input[swapIndex1];
    input[swapIndex1] = input[swapIndex2];
    input[swapIndex2] = temp1;
    
    if((n - swapIndex1) != 1)
        qsort (input+swapIndex1+1, n-swapIndex1-1, sizeof(int), compare);
    
    for (i=0;i<n;i++) // printing permuation
    {
        printf("%d", input[i]);
    }
    
    printf(" ");
    funcCount ++;
    if (funcCount == fact(n) - 1) // checking if n! permutations have been outputted 
        return;
    nextPerm (input, n); // print next permutation
}

int fact(int n) // returning factorial of "n"
{
    if (n==0)
        return 1;
        
    return n*fact(n-1);
}
