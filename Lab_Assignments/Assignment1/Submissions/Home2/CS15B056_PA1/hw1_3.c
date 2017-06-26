//common prime factors

#include <stdio.h>

int main()
{
	int a,b,i;
	scanf("%d%d",&a,&b);
	for (i=2;i<=a&&i<=b;i++)           
	{
		if(a%i==0&&b%i==0)                //checks if i is a prime factor 
		{
			for (;a%i==0&&b%i==0;)    //removes all the factors of i from a and b
			{
				a=a/i;
				b=b/i;
			}
			printf("%d ",i);       
		}
	}
	return 0;
}

		
