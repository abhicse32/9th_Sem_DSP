//file content - finding common prime factors between two integers 
//author - Shiva Poojith
//date - 14/08/2016

#include <stdio.h>

inline int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}

// Sieve of Eratosthenes may be used here for constant time look-up 
int isPrime(int a)
{
	int i;
	for (i = 2;i*i<=a;i++)
		if (a%i==0)
			return 0;
	return 1;
}

void primeFactors(const int& a,const int& b)
{
	int gc = gcd(a,b);
	int i;

	for (i = 2;i*i<=gc;i++){
		if (!isPrime(i))
			continue;
		if (!(gc%i)) {
			printf("%d ",i);
			while(!(gc%i)) 
				gc/=i;
		}
	}

	printf("\n");
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	primeFactors(a,b);
}
