//Program to find the square root of a number correct to 15 decimal places
//Author: B Arjun, CS15B058; Date:13/08/16
#include<stdio.h>
/*Function to find absolute value of a real number*/
long double absolute(long double x)
{
	if(x>=0)
		return x;
	else
		return -x;
}
int main(void)
{
	long double n;
	scanf("%Lf",&n);	//The number whose square root is to be found.

	long double x,error;	//x is used to store the value of x intercept from Newton Raphson Method in each iteration
	//error is the difference between old x and new x(old x is stored in xi).
	x=n/2;	//We take n/2 as the initial approximation for square root
	long count=0;
	do
	{
		long double xi=x;
		x=x-(x*x-n)/(2*x);	//According to Newton Raphson method, x(n+1)=x(n)-f(x(n))/f'(x(n))
		error=absolute(x-xi);
		count++;
	}while(error>=1e-16&&count<=100000);	//We put error>=10^-16 to make sure its correct to 15 decimal places.
	printf("%.15Lf",x);
}
