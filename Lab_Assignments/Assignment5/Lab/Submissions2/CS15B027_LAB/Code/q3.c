#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "List.h"
int main()
{
   int j,t;
   scanf("%d",&t);   //taking input no of test cases
   for(j=0;j<t;j++)
   {
       int n,i;
       scanf("%d",&n);    //taking input no of elements in array
       int A[n];
       for(i=0;i<n;i++)
       {
           scanf("%d",&A[i]);
       }
       stack *p=stack_new();
       for(i=0;i<n-1;i++)    //using this for loop tramsforming array into nextmax array
       {
          if(A[i]<A[i+1])
          {
              A[i]=A[i+1];
              while(stack_is_empty(p)==0 && A[i+1]>A[stack_top(p)])   //checking for next max nearer to index j
              {
                 A[stack_pop(p)]=A[i+1];
              }
          }
          else stack_push(p,i);
       }
       A[n-1]=-1;                                          //for last element no element is next to is so making it -1
       while(stack_is_empty(p)==0)                     //no elements next to it are greater than itself so it should become -1
       {
          A[stack_top(p)]=-1;
          stack_pop(p);
       }
       for(i=0;i<n;i++)
       {
          printf("%d ",A[i]);
       }
       printf("\n");
   }  
}             
