//file content - finding square root of any integer with 15 decimal precision
//author - Shiva Poojith
//date - 14/08/2016

#include <stdio.h>
#define EPSILON 0.000000000000001  // sets the precision to 15 decimals

int equals (double a,double b)
{
	return ((a-b)>0)?(a-b)<EPSILON:(b-a)<EPSILON;
} 

double mySqrt(int n)
{
	double mid,high = n,m = 1.0;

	// binary search to find the sqrt(n)
	while(!equals(n/m,m))
	{
		mid = m+(high-m)/2;
		if (mid*mid < n + EPSILON)
			m = mid;
		else 
			high = mid;
	}
	return m;
}

int main()
{
	int n;
	scanf("%d",&n);
	double sqrt_n = mySqrt(n);
	printf("%.15f\n",sqrt_n);
}