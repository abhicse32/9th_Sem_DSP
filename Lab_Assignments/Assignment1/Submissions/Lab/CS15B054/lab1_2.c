#include<stdio.h>
void main()
{
int n,i,j,max,min;
int A[100];
scanf("%d\n",&n);
for(i=0;i<n;i++)
 {
  scanf("%d",&A[i]);
 }
max=A[0];
min=A[0];
for(j=1;j<n;j++)
  {
   if(A[j]>max){
    max=A[j];
     }
   else if(A[j]<min){
    min=A[j];
     }
  }
printf("%d %d",min,max);
}
   
