// Home Assignement 1 Question 5
// Finding square root of a given integer precise to 15 decimal points using Newton-Raphson method
// Author : Milind Srivastava
// Date : 9 Aug 2016

#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	
	scanf("%d",&n);

	long double x_0 = (long double)(n); // Intial guess for root

	while(fabs(x_0*x_0 - n) > pow(10.0,-17.0)) // Checking for 17 digits of precision
	{
		x_0 = x_0/2 + (long double)n/(2*x_0); // Implementing Newnon-Raphson
	}

	printf("%.16Lf\n",x_0); //Printing to 16 digits of decimal points

	return 0;
}
