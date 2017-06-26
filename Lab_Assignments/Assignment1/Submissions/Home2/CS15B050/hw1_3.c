						//COde to find square root of a number
						//Author:M.Prasanna Kumar
						//Date:10/08/1997
#include<stdio.h>
int Prime(int);                                 //Function to find if a number is prime        
int Factors(int,int);                           //Function to find Factors
int main()
{
	int a,b,i,cp;
	int max,min;
	scanf("%d %d",&a,&b);                   //Input the two numbers
	if(a<b)
 	{
		max=b;
		min=a;
 	}
	else 
 	{
		max=a;
		min=b;
	}
	for(i=2;i<=min;i++)
 	{
		if(a%i==0 && b%i==0)                    //Finding common factors
		{
			cp=Prime(i);                    //Checking whether the common factor is prime
			if(cp==1) printf("%d ", i);     //Print the common prime factor
		}
	}
	return 0;
}

int Prime(int x)
{
	int i;
	int t=1;
	if(x%2==0 && x!=2) t==0;
	for(i=3;i<x/2;i++)
	{
		if(x%i==0)
		{
			t=0;
			break;
		}
	}
	if (t==1) return 1;
	else return 0;
}


