#include<stdio.h>

int main()
{
int max, next_max, i, n, arr[1000000];

scanf("%d",&n);

scanf("%d",&arr[0]);

scanf("%d",&arr[1]);

if( arr[0]>=arr[1] )
 {
   max = arr[0];
   next_max = arr[1];
 }
else
 {
   max = arr[1];
   next_max = arr[0];
 }

for(i=2; i<n; i++)
{
  scanf("%d",&arr[i]);

  if( arr[i]>=max )
    {
      next_max = max;
      max = arr[i];
    }
  else if( arr[i]>=next_max )
    {
      next_max = arr[i];
    }
}
printf("%d  %d\n",max, next_max);

return 0;
}
