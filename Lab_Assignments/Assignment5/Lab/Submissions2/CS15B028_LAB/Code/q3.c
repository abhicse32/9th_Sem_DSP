#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.c"
#include "List.c"
int main()
{
   int t,i;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
       int N,i;
       scanf("%d",&N);
       int a[N];
       for(i=0;i<N;i++)
       {
           scanf("%d",&a[i]);
       }
       stack*ps=stack_new();
       //printf("akhil\n");
       for(i=0;i<N-1;i++)
       {
          if(a[i]<a[i+1])
          {
              a[i]=a[i+1];
              while(stack_is_empty(ps)==0&&a[i+1]>a[stack_top(ps)])
              {
                 a[stack_top(ps)]=a[i+1];
                 stack_pop(ps);
              }
          }
          else stack_push(ps,i);
       }
       //printf("akhil\n");
       a[N-1]=-1;
       while(stack_is_empty(ps)==0)
       {
          a[stack_top(ps)]=-1;
          stack_pop(ps);
       }
       for(i=0;i<N;i++)
       {
          printf("%d ",a[i]);
       }
       printf("\n");
   }  
}             
