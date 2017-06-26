/*
 * =====================================================================================
 *
 *       Filename:  commfactors.c.c
 *
 *    Description:  To print common prime factors of two numbers.
     
 *
 *         Author: Harshavardhan.P.K. 
 *
 * 	  Roll No: CS15B061
 * =====================================================================================
 */
#include <stdio.h>
#include <math.h>

typedef unsigned long int ul;
 ul gcd (ul,ul);
short isprime (ul);




/*
 * =====================================================================================
 *	Main Functions
 *	Inputs 2 numbers : n1, n2
 *	gcd_num:  Stores gcd of n1 and n2 in gcd_num 
 *	Output: prints all common factors.
 * =====================================================================================
 */
int main (void){
	ul n1,n2;
	ul gcd_num;
	ul i;

	scanf ("%lu%lu",&n1,&n2);
	gcd_num=gcd(n1,n2);

	/*
		This check is done so if two are even we can directly print 2 and prevent further checks of even numbers which are not prime.
	*/
	if (gcd_num%2==0)
		printf ("2 ");

	/*
		Checks every prime number from 3 to gcd_num if it is a common factor of num1 and num2.
	*/
	for (i=3;i<=gcd_num;i+=2){
		if (n1%i==0 && n2%i==0 && isprime(i))
			printf ("%lu ",i);
	}

	printf("\n");
	return 0;
}


/*
 * =====================================================================================
 *	gcd Functions
 *	Inputs 2 numbers : num1, num2
 *	Outputs: GCD of num1 and num2 using euclid's long division algorithm
 * =====================================================================================
 */
ul gcd (ul num1,ul num2){
	ul divisor, remainder, dividend;
	if (num1 > num2) divisor=num2;
	else divisor=num1;

	dividend = num1+num2-divisor;
	
	remainder = dividend % divisor;

	while (remainder != 0){
		dividend = divisor;
		divisor = remainder;
		remainder = dividend % divisor;
	}

	return divisor;
}


/*
 * =====================================================================================
 *	gcd Functions
 *	Inputs integer: num
 *	Outputs: 1 if num is prime, 0 if not prime.
 * =====================================================================================
 */
short isprime (ul num){
	ul i;
	if (num %2 == 0 && num>2)
		return 0;

	for (i=3; i<=sqrt(num); i+=2)
		if (num % i ==0 ){
			return 0;
		}

	return 1;
	
}
