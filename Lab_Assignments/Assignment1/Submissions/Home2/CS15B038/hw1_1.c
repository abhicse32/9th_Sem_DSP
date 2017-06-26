#include<stdio.h>

int main()
{
 int i, j, n, m1, m2;
 int A[n];
 
 scanf("%d",&n);
 
 for(i=0;i<n;i++)
  scanf("%d",&A[i]);
 
 m1=A[0];
 
 for(i=0;i<n;i++)
  {
   if(A[i]>m1){ m1=A[i];j=i;}
  }
 
 A[j]=(-2147483648);
 m2=A[0];
 
 for(i=0;i<n;i++)
  {
   if(A[i]>m2) m2=A[i];
  }

 printf("%d %d",m1,m2);
 return 0;
}
