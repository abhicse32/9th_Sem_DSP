/*
 * =====================================================================================
 *
 *
 *    Description:  To compute Square Root of A Number currect to given precision
 *
 *
 *         Author: Harshavardhan.P.K. 
 	  Roll No: CS15B061
 * =====================================================================================
 */

#include <stdio.h>
#define PRECISION 15

typedef unsigned int uni;
double squart(uni num, uni pres);
double absolute(double);


/*
 * =====================================================================================
 *	Function: main
 *	Input: positive integer in n
 *	Output: prints square root of n upto giver PRECISION
 * =====================================================================================
 */ 
int main (void){
	uni n;
	scanf("%u",&n);
	printf("%.*lf\n",PRECISION,squart(n,PRECISION));
	return 0;
}


/*
 * =====================================================================================
 *	Function: sqruat
 *	Input: positive integer in num, and positive integer pres for PRECISION
 *	
 *	next: stores next closer value of sqrt(num) by Newton-Ralphson Method.
 *	Previous: stores previous result of sqrt(num)
 *	in: store value of 10^(-PRECISION-1)
 *	Output: square root of num upto given PRECISION.
 * =====================================================================================
 */ 
double squart (uni num, uni pres){
	double next,previous;
	double in=1;
	uni i;
	for (i=0; i<=pres; i++)
		in/=10;
	previous = num/2;
	next = (previous + num/previous)/2;
	while (absolute(next-previous)>=in){
		previous =next;
		next = (previous + num/previous)/2;
	}

	return next;

}


/*
 * =====================================================================================
 *	Function: absolute.
 *	Input: positive integer in n
 *	Output: Outputs the absolute value of n.
 * =====================================================================================
 */ 
double absolute (double n){
	if(n>0)
		return n;
	return (-n);
}
