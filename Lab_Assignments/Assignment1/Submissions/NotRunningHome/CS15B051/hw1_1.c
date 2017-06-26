#include<stdio.h>
int main()
{
  int a[100],n,i,j,max,nextMax; 
  scanf("%d",&n); //number of elemets in the array
  for(i=0;i<n;i++)
     {
       scanf("%d",&a[i]);   //Passing elements into the array
     }
  max=a[0];
  for(i=1;i<n;i++)
     {
         if(max<a[i])
         {
            max=a[i];
            j = i;
         }
     }
  nextMax=a[n-j-1];
  for(i=1;i<n;i++)
     {
      if( nextMax<a[i] && j != i)
        {
          nextMax =a[i];
        }
     }
    printf("%d  %d",max,nextMax);
 return 0;
}