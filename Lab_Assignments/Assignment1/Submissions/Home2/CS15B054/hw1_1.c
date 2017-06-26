#include<stdio.h>
void main()
{
  int n,i,j;
  int A[10000];
  scanf("%d\n",&n);
  scanf("%d",&A[0]);
  int Max=A[0],index=0;
  int NextMax=A[0];

  for(i=1;i<n;i++)
     {
        scanf("%d",&A[i]);
        if(A[i]>Max)
           {
              Max=A[i];
              index=i;
           }
     }
  for(j=1;j<n;j++)
     {
        if(j!=index)
         {
           if(A[j]>NextMax)
             {
               NextMax=A[j];
             } 
         }
     } 
  printf("%d  %d",Max,NextMax);
} 

  
