//Program to find the common prime factors of two integers
//Author: B Arjun, CS15B058; Date:12/08/16
#include<stdio.h>
#include<math.h>
int main(void)
{
	int n1,n2;
	scanf("%d%d",&n1,&n2); //n1 and n2 are the two common integers whose prime factors are to be found
	int min;
/*min is the smaller of n1 and n2*/	
	if(n1>n2)
		min=n2;
	else
		min=n1;
	int pf=2;//pf acts as the prime factor.
	int i;	
/*We use pf starting from 2, and first check if its a prime number and then check if its a factor of n1 and n2.
If pf is 2, we increment it to 3, otherwise we increment it by 2, because even numbers except 2 are not prime.*/	
	while(pf<=min)
	{
		int flag=1;
		int range=sqrt(pf);
		/*We check only need to check till square root of the number to check if its prime.*/
		for(i=3;i<=range;i+=2)
		{
			if(pf%i==0)
			{
				flag=0;//If flag is 0, it is not prime. if flag is 1 its prime.
			}
		}
		if(flag==1)
		{
			if((n1%pf==0)&&(n2%pf==0))
				printf("%d ",pf);
		}
		if(pf==2)
			pf++;
		else
			pf+=2;
	}

}