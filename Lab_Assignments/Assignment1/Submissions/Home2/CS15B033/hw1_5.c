#include <stdio.h>

/* Completed by R.Gokulan, Roll num.CS15B033 on 13.8.16*/

int main()
{
	int n;
	scanf("%d",&n);
	int b;
	int i,k;
	double j;

	for( i = 0; i*i <= n; i++)
	{
		if( i*i <=n && (i+1)*(i+1))
			b = i;
	}

	double x = b;

	long long int p = 10;
	for( k = 0; k<15; k++)
	{
		for( j = 0; j < 10; j+=1)
		{
			double l = x + (double)j/p;
			double m = x + (double)(j+1)/p;

			if( l*l <= n && m*m >n)
				{
					x = l;
					break;
				}
		}
		p *= 10;
	}

	printf("%.15f", x);
	return 0;
}