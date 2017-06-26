// Home Assignement 1 Question 5
// Finding square root of a given integer precise to 15 decimal points using Newton-Raphson method
// Author : Milind Srivastava
// Date : 9 Aug 2016

#include <stdio.h>
#include <math.h>

int main()
{
	long int n;
	
	scanf("%ld",&n);

	long double x_0 = (long double)(n); // Intial guess for root

	int iterations = 10000; 

	while(fabs(x_0*x_0 - n) > pow(10.0,-16.0) && iterations > 0) // Checking for 16 digits of precision
	{
		x_0 = x_0/2 + (long double)n/(2*x_0); // Implementing Newton-Raphson
		iterations--;
	}

	printf("%.15Lf\n",x_0); //Printing to 15 digits of decimal points

	return 0;
}
