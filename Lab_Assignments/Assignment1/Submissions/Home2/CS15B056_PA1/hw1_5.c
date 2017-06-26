// Program to find square root of a number

#include <stdio.h>

int main () 
{
	int i,j,n;
	long double rt,ip,d=1;
	scanf ("%d",&n);
	for (i=1;i*i<=n;i++);                          //Finds the integer part of the square root of the number
	ip=i-1;
	rt=ip;
	for (i=0;i<15;i++)                             //Computes upto 15 places of decimal
	{
		d=d/10;
		for(j=0;j<10;j++)
		{
			if ((rt+j*d)*(rt+j*d)>n)
				break;
		}
		rt=(rt+(j-1)*d);
	}
	printf("%.15llf",rt);                           //Prints the square root
	return 0;
}

	
		
			
			
		
	
