/*CS15B059 KOMMURU ALEKHYA REDDY 12AUG2016
TO PRINT THE COMMON PRIME FACTORS OF TWO NUMBERS*/
#include <stdio.h>
#include <math.h>
void prime(int check);
int comdiv(int no1,int no2);//defining the functions
void main()
{
	int no1,no2;
	scanf("%d%d",&no1,&no2);//input two numbers
	int gcd=comdiv(no1,no2);//calculate its gcd
	int count;
	for(count=2;count<=gcd;count++)
		{
			prime(count);//check primality of the divisors of gcd
		}
}


//this function calculates the gcd of two given numbers using recursion
int comdiv(int no1,int no2)
{
	if(no1==0)
		return no2;
	else if(no2==0)
		return no1;
	else if(no1>no2)
		return(comdiv(no1-no2,no2));
	else
		return(comdiv(no2-no1,no1));
}

//function prints the prime factors of gcd by checking whether the factors are prime or not
void prime(int check)
{
	int i,flag=1;//flag is used to signify change
	for(i=2;i<=sqrt(check);i++)
	{
		if(check%i==0)
		{
			flag=0;
			break;			
		}	
		
	}
	if(flag==1)
		printf("%d ",check);
}
