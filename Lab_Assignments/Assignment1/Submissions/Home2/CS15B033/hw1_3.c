#include <stdio.h>

/* Completed by R.Gokulan, Roll num.CS15B033 on 8.8.16*/


int isprime(int n)
{
	int i;
	if( n!= 2 && n%2 == 0)
		return 0;
	else
	{
		for( i = 3; i*i <=n; i+=2)
			if( n%i == 0)
				return 0;
	}
	return 1;
}

int main()
{
	int a,b;
	scanf("%d %d", &a, &b);

	int i = 2;
	while( i<=a && i<=b)
	{
		if( a%i == 0 && b%i == 0)
		{
			if(isprime(i))
				printf("%d ", i);
		}
		i++;
	}
	return 0;
}