#include<stdio.h>
void swap(int A[9],int i,int j);
void permut(int A[9],int i,int j);
int main(void)
{
   int n,i,A[9];
   scanf("%d\n",&n);
   for(i=0;i<n;i++)
     {
       scanf("%d",&A[i]);
     }
   permut(A,0,n); 
   printf( "\n" ); 

 return 0;
}

void swap(int A[9],int i,int j)
{
   int temp;
   temp=A[i];
   A[i]=A[j];
   A[j]=temp;
}

void permut(int A[],int i,int n)
{
  int j;
  if(i==n)
   {
    for(j=0;j<n;j++)
       {
         printf("%d",A[j]);
       }
    printf( " " );
    return;
   }
  else
   {
    for(j=i;j<n;j++)
       {
         swap(A,i,j);
         permut(A,i+1,n);
         swap(A,i,j);
       }
   }
}
