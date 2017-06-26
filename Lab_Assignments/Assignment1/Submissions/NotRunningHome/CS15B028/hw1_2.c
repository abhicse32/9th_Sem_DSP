#include<stdio.h>
int main()
{
   int n,i;
   scanf("%d",&n);
   int a[100];

   for(i = 0;i < n; i++)
   {
       scanf("%d",&a[i]);
   }

   int max,min;
   max = a[0];
   min = a[0];
   for(i = 1;i < n;i++)
   {
      if(max < a[i]) max = a[i];
      else if( min > a[i])  min = a[i];
   }
   printf("%d  %d",min,max);
}
          