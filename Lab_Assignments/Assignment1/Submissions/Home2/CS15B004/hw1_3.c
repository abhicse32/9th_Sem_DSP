#include<stdio.h>
#include<math.h>


int checkprime(int n)
{
	if(n==2)  									// case for 2
		return 1;

	int i;
	if(n%2 == 0)
		return 0;
	else
	{
		for( i = 3; i <=sqrt(n); i+=2)			//check only odd numbers
			if( n%i == 0)
				return 0;
	}
	return 1;
}

int main()
{
	int n1,n2;
	scanf("%d %d", &n1, &n2);
	int i = 2;
	
	while( i<=n1 && i<=n2)
	{
		if( n1%i == 0 && n2%i == 0)          // check divisibility
		{
			if(checkprime(i))
				printf("%d ", i);
		}
		i++;
	}
	return 0;
}