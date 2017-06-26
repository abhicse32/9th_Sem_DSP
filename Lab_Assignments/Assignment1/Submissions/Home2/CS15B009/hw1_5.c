/*  Program to find the square root of a number upto an accuracy of 15 decimal places
	By  Chandrashekhar D   CS15B009    Programming Home Assignment 1  */

#include <stdio.h>

/*  Function to find the square root of an integer by Newton Raphson method :
	Input parameters : Integer n
	Returns : sqrt, the square root of n  */
double sqRoot(int n)
{
	double prevApprox,currApprox,error1,error2,sqrt;
	currApprox = (float) n/2;
	error1 = 0.0000000000000001;
	error2 = -0.0000000000000001;
	do
	{
		prevApprox = currApprox;
		currApprox = (prevApprox + n/prevApprox)/2;
	} while ((prevApprox - currApprox)>error1 || (prevApprox - currApprox)<error2);
	sqrt = currApprox;
	return sqrt;
}

/*  Main function */
int main()
{
	int n;
	scanf("%d",&n);
	double sqrt = sqRoot(n);  // square root of n
	printf("%.15lf",sqrt);    // printing sqrt upto 15 decimal places 
	return 0;
}