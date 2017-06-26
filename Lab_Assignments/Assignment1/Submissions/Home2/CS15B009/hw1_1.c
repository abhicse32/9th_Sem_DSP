/*  Program to find the maximum and next maximum of an array of integers
	By	Chandrashekhar D  CS15B009 Programming Assignment 1 Homework  */

#include <stdio.h>

int main()
{
	int n,i,first_max,second_max; // Declaration of required variables
	scanf("%d",&n);     // Taking length of array as input
	int a[n];
	
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);   // Taking the array elements as input
	
	first_max = a[0]>a[1] ? a[0] : a[1];    // Initializing first_max and second_max 
	second_max = a[0]>a[1] ? a[1] : a[0];   // as the first two elements of the array
	for (i = 2;i < n;i++)
	{
		if (a[i]>first_max)       // Checking if array element is greater than both first and second max
		{
			second_max = first_max;   
			first_max = a[i];
		}
		else if (a[i]>second_max) // Checking if array element is greater than only second max
			second_max = a[i];
	}
	printf("%d %d",first_max,second_max);   // Printing the first and second maxima
	return 0;
}   // End of main function
