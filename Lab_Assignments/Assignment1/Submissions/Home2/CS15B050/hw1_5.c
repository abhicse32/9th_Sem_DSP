						//COde to find square root of a number
						//Author:M.Prasanna Kumar
						//Date:10/08/1997
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
int n;
scanf("%d",&n);                                      //Input the number
long double prevGuess,currGuess;
long double error;
error=0.000000000000001;                             //Finding it close to its 15 
currGuess=(long double)n/2;
do{
	prevGuess=currGuess;
	currGuess=(prevGuess+n/prevGuess)/2.0;       //Using Newton-Raphson's Method
}while(fabs(prevGuess-currGuess)>error);
printf("%.15Lf",currGuess);                          //Printing the square root
return 0;
}
