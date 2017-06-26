/*  Program to determine the common prime factors of two positive integers
	By  Chandrashekhar D   CS15B009   Programming Home Assignment 1   */

#include <stdio.h>


/*  A function to find the greatest common divisor of two positive integers :
	Input parameters : Two positive integers a,b
	Returns : gcd, Greatest common divisor of a and b  */
int gcd(int a,int b)
{
	int temp,i;     

	if (a<b)   // Swapping a and b if a is lesser than b
	{
		temp = a;
		a = b;
		b = temp;
	}

	i = b;
	while (i > 0)    // Finding GCD of a and b by Euclids algorithm
	{
		i = a%b;
		if (i == 0)
			return b;
		a = b;
		b = i;
	}
	return 1;
}


/*  A function to determine if a number is prime or not :
	Input parameters : A positive integer n
	Returns : 1 if n is prime, 0 otherwise  */ 
int isPrime(int n)
{
	int i;
	for (i = 2;i < n-1;i++)
	{
		if (n%i == 0)    // Checking if n is divisible by i
			return 0;
	}
	return 1;
}


/*  Main function:  */ 
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);  // Taking the two integers as input
	int g = gcd(a,b);      // Finding the GCD of a and b
	int i;

	for (i = 2;i <= g;i++)  // Checking the numbers below the GCD
	{
		if (a%i == 0 && b%i == 0 && isPrime(i)==1)       // Checking for a prime number that divides both a and b
			printf("%d ",i);
	}
	return 0;
}   // End of main function

