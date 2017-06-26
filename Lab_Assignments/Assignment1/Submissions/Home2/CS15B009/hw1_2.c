/*  Program to print a given integer in hexadecimal 
	By  Chandrashekhar D  CS15B009   Programming Home Assignment 1  */

#include <stdio.h>

/*  Main function */
int main()
{
	unsigned int n;
	scanf("%u",&n);     // Taking an integer as input
	printf("0x%08x",n); // Printing the number in form of a hexadecimal
	return 0;
}