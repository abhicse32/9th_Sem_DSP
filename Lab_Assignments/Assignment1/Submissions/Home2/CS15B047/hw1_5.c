#include <stdio.h>
#include <math.h>

int main(void) 
{
	int n;
	scanf("%d",&n); // Input number
	
	// Solution is by Newtons Method
	long double x=(long double)(n)/2 ; //Make an initial guess of square root as n/2 ; 
	
	//Till error b/w x^2 and n is greater than 10^-16 improve estimate
	while(fabs(x*x-n) > pow(10,-15))
	{
	        // f(x) = x^2 -n 
	        // x(new) = x(old) - f(x(old))/f'(x(old))
		x = x - (x*x-n)/(long double)(2*x) ; 
	} 
	printf("%.15Lf",x); // print answer till 15 digits
	
	return 0;
}

