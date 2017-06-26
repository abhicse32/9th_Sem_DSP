/* Author: G.Kavitha
Roll Number: CS15B057
Date: 11-08-16 */
#include <stdio.h>
#include <math.h>
const double precision=1e-15;
int main(){
	int n;//Holds number whose square root is to be found
	scanf("%d",&n);//Reads in n
	double prev=1,cur=1;//prev is previous guess, cur is current guess
	do{
		prev=cur;//Updating prev
		cur=cur-(cur*cur-n)/(2*cur);//Updating cur
	}while(fabs(prev-cur)>precision);//Loops till required precision is obtained
	printf("%.15f\n",cur);// Displays the answer upto 15 decimal points
	return 0;
}