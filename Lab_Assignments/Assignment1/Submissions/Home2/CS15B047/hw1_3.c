#include <stdio.h>

int main(void) 
{
	int num1,num2;
	
	scanf("%d%d",&num1,&num2); // Take 2 numbers
	int smaller; //stores smaller of 2 nos.
	int i,j;
	//store smaller of 2 nos in smaller
	if(num1<=num2)
		smaller=num1;
	else
		smaller=num2;
		
	
	int p[smaller+1] ; //Array where p[i] = 1 --> i is prime  p[i] = 0 --> i composite 
	for(i=2;i<=smaller;i++)
		p[i]=1;// Initialize all to prime
	
	
	// This loop determines all primes from 2 to smaller 
	for(i=2;i<=smaller;i++) //Iterate till smaller of 2 nos.
	{
		if(p[i]==1) 
		{
		        // If i-->prime make all multiples of i which are lesser than smaller composite
			for(j=2;j*i<=smaller;j++)
			{
				p[j*i]=0;
			}
		}
		//Ignore composite
	}
	
	for(i=2;i<=smaller;i++)
	{
	        // Check for prime and factor of both nos.
		if(p[i]==1 && num1%i==0 && num2%i==0 )
			printf("%d ",i); // Print prime factor
	}
	
	return 0;
}

