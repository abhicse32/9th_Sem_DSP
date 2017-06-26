/*
This code calculates the square root of a given integer
upto 15 decimal places by using newton raphson method

Ameet S Deshpande
CS15B001
*/


#include<stdio.h>

int main()
{	
	double sqrt(int);	//Function which return the square root
	double ans;		//The final answer
	int number;		//The input of the user
	scanf("%d",&number);	//Prompt user to enter the number
	ans=sqrt(number);
	printf("%.15lf",ans);	//Prints out the double number with 15 digits precision
	
}


double sqrt(int x)
{
        int i=0;
        int max=10000;	//Maximum precision is achieved much before 10000 iterations
        double s=1;
        for(i=0;i<max;i++)
        {
            s=(s+x/s)/2;	//The new term is a better approximation than the previous term, by newton raphson method
        }
        return s;
}