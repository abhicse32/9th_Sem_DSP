#include <stdio.h>
#include <stdlib.h>

/* Completed by R.Gokulan, Roll num.CS15B033 on 14.8.16*/


int findMax(int a, int b)//Function to find max of two given numbers
{
	if (a>b)
		return a;
	else
		return b;
}
int main()
{
	int n;
	int max;
	int nmax;

	scanf("%d", &n);
	
	int *a = (int*) malloc((2*n-1)* sizeof(int));
	int i;
	for( i = 2*n-2; i>=n-1; i--)
	{
		scanf("%d", a+i);
	}

	int j;
	int k;
	for( j = 2*n-2, k = n-2; j>=0; j-=2, k--)
	{
		if( a[j] > a[j-1])
			a[k] = a[j];
		else
			a[k] = a[j-1];
	}

	max = *a;
	nmax = *(a+1) + *(a+2) - findMax(*(a+1), *(a+2));//assigning min of a[1] and a[2] as default to nmax

	for( i = 3; i<= 2*n-2 ; i++)
	{
		if( *(a+i) == max)
		{
			int temp = findMax(*(a+i-1), *(a+i+1));
			nmax = findMax( nmax, temp);
		}
	}

	printf("%d %d\n",max, nmax );

	return 0;
}
