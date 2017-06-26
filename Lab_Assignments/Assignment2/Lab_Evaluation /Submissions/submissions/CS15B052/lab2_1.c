// Lab Assignment 2 Question 1
// Print time required by iterative and recursive functions to calculate fibonacci numbers from 1 - 20
// Author : Milind Srivastava
// Date : 18 Aug 2016 

#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int iterativeFib(int n);
int recursiveFib(int n);

int iterativeFib (int n) // iterative function to calculate nth fibonacci number
{
    int j=0,k=1;
    int i;
    int fib=1;
    for (i=2;i<=n;i++)
    {
        fib = j+k;
        j=k;
        k=fib;
    }
    return fib;
}

int recursiveFib (int n) // recursive function to calculate nth fibonacci number
{
    if(n==1 || n==2)
    {
        return 1;
    }
    else
    {
        return (recursiveFib(n-1) + recursiveFib(n-2));
    }
}

int main()
{
    //int n;
    //scanf("%d",&n);
    
    int i = 1;
    
    FILE* fp;
    fp = fopen("output.csv", "w+"); // defining output file
    
    struct timeval startTime, endTime; // structures to hold time values
    
    for (i=1;i<=20;i++)
    {
        int temp;
        gettimeofday(&startTime, NULL);
        temp = iterativeFib(i);
        gettimeofday(&endTime, NULL);
        
        // printing time taken by iterative function to output.csv
        
        fprintf(fp, "%ld",(endTime.tv_sec - startTime.tv_sec)*1000000L + (endTime.tv_usec - startTime.tv_usec)); 
        
        gettimeofday(&startTime, NULL);
        temp = recursiveFib(i);
        gettimeofday(&endTime, NULL);
        
        // printing time taken by recursive function to output.csv
        
        fprintf(fp, ",%ld\n",(endTime.tv_sec - startTime.tv_sec)*1000000L + (endTime.tv_usec - startTime.tv_usec));        
    }
    
    fclose(fp); // closing file link
    
    return 0;
}
