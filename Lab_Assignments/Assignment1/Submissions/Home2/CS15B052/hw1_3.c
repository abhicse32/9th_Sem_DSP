// Home Assignement 1 Question 3
// Finding common prime factors of 2 given integer inputs
// Author : Milind Srivastava
// Date : 9 Aug 2016

#include <stdio.h>

int isPrime(int x) // Funtion to determine if number is prime or not
{
	int i=2;
	
	for(;i<x;i++)
	{
		if(x%i == 0)
		{
			return 0;
		}
	}

	return 1;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);

	int i=2;

	for(;i<a && i<b;i++) // iterating through values for possible prime factors
	{
		if(a%i == 0 && b%i == 0 && isPrime(i))
		{
			printf("%d ",i);
		}
	}

	return 0;
}