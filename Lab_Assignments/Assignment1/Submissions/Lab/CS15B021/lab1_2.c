#include<stdio.h>

int main()
{

int num, i, arr[100], min, max;

scanf("%d\n",&num);

scanf("%d",&arr[0]);

min=arr[0];

max=arr[0];

for( i=1; i<num; i++ )
{
scanf("%d",&arr[i]);

if( arr[i] >= max )

	max= arr[i];

else if( arr[i] <= min )

	min= arr[i];
}

printf("%d %d\n",min,max);

return 0;

}

