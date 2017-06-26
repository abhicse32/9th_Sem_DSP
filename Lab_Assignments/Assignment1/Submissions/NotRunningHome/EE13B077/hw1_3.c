
/*

Author Name: Gudur Phani Karan Reddy (EE13B077)
Time: Sun Aug 14 20:30:26 IST 2016

Description:
This program takes two numbers as input and outputs their common prime factors.

*/



#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
	int i;
	for(i=2; i<=n/2; i++)
		if(n%i==0)
			return 0;

	return 1;
}

int main()

{

	int a,b,p, min; 

	printf("Numbers? \n");
	scanf("%d %d", &a, &b);

	min = b;

	if(a<b)
		min = a;


    for(p=2; p<=min; p++)
    	if(is_prime(p))
	    	if(a%p==0 && b%p==0)
				printf("%d ", p);

	printf("\n");

	return 0;
}

