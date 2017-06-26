/*This program takes as input two numbers and prints all their
prime factors.

Ameet S Deshpande
CS15B001
*/

#include<stdio.h>
#include<math.h>

int main()
{
	int gcd(int,int);
	void prime(int);
	int isprime(int);
	
	int a,b;	//The two numbers are stored in these
	int g_c_d;	//Stores the greatest common divisor of the number
	scanf("%d%d",&a,&b);	//Prompt the user to enter the numbers
	
	if(a>=b)	//The gcd is found
	{
		g_c_d=gcd(a,b);
	}
	
	else
	{
		g_c_d=gcd(b,a);
	}
	prime(g_c_d);	//Calling the prime function on gcd
	
}

int gcd(int a,int b)	//Calculates the greatest common divisor recursively using euclid's division lemma
{
	int temp;
	if(b==0)
	{
		return a;
	}
	else
	{
		return gcd(b,a%b);
	}
}

void prime(int a)	//Prints all the prime divisors of the greates common divisor of the two given numbers
{
	int isprime(int);
	int i=0;	//For loop variable
	for(i=2;i<=a;++i)
	{
		if(isprime(i))
		{
			if(a%i==0)
			{
				printf("%d ",i);
			}
		}
	}
	
}

int isprime(int a)	//Return 1 if the given number is prime and 0 otherwise
{
	int temp,i,flag=1;
	temp=sqrt(a)+1;
	
	if(a==2)
	{
		return 1;
	}
	
	for(i=2;i<=temp;++i)
	{
		if(a%i==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}
