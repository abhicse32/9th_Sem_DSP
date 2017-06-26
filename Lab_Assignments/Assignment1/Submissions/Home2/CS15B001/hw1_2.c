/*
This program calculates the hexadecimal equivalent of the 
given decimal number

Ameet S Deshpande
CS15B001
*/

#include<stdio.h>

int main()
{
	long int n;		//Variable that contains the number
	int i,count=0;			//Variable for the loop
	int a[8];		//The hexadecimal number that will be the output
	
	scanf("%ld",&n);	//Prompting user for the input
	
	for(i=0;i<8;++i)
	{
		a[i]=0;
	}
	
	while(n>0)	//While loop to find the hexadecimal number
	{
		a[count]=n%16;
		count++;
		n=n/16;
	}
	
	printf("0x");
	
	for(i=7;i>=0;--i)
	{
		if(a[i]<=9)
		{
			printf("%d",a[i]);
		}
		
		else
		{
			printf("%c",(char)(87+a[i]));
		}
	}
	
	
	
}