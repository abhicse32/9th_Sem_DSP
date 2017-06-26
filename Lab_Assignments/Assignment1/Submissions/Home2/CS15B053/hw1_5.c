#include<stdio.h>
#include<stdlib.h>

double sqroot(int num)
{
	double error=0.0000000000000001;
	double g1, g2;
	
	g2 = num/2;
	
	do
	{
		g1 = g2;
		g2 = (g1+num/g1)/2;	
	}while(g1-g2>error || g2-g1>error);
	
	return g2;
}

void main()
{
	int num;
	scanf("%d", &num);
	double root = sqroot(num);
	printf("%.15f", root);
}
