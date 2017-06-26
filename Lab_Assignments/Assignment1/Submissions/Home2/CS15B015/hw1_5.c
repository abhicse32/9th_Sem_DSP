/*	Program to find square root of an integer with a precision of 15 digits after the decimal point
		G.Pranav CS15B015	10-8-2016*/
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	double prevguess,currguess,error;	//declaring variables as double so that the required precision is attained
	currguess=(double)n/2;	//type casting n to double
	do{
		prevguess=currguess;
		currguess=(prevguess+(n/prevguess))/2;
		if(prevguess<currguess) error=currguess-prevguess;
		else error=prevguess-currguess;
	}while(error>0.00000000000001);	//loop terminates when error is less than 0.000000000000001 
	printf("%.15f\n",currguess);	//currguess is the square root of n with a precision of 15 digits after the decimal point
	return 0;
}