#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main()
{
   int t,i=0;
   scanf("%d",&t);
   while(i<t)
   {
       int N,j=0;
       scanf("%d",&N);
       int arr[N];
       while(j<N)
       {
           scanf("%d",&arr[j]);
           j++;
       }
       stack*avi=stack_new();
       int k=0;
       
       for(k=0;k<N-1;k++)
       {
          if(arr[k]<arr[k+1])
          {
              arr[k]=arr[k+1];
              while(stack_is_empty(avi)==0&&arr[k+1]>arr[stack_top(avi)])
              {
                 arr[stack_top(avi)]=arr[k+1];
                 stack_pop(avi);
              }
          }
          else stack_push(avi,k);
       }
       
       arr[N-1]=-1;
       while(stack_is_empty(avi)==0)
       {
          arr[stack_top(avi)]=-1;
          stack_pop(avi);
       }
       int l=0;
       for(l=0;l<N;l++)
       {
          printf("%d ",arr[l]);
       }
       printf("\n");
       i++;
   }  
}             
