#include<stdio.h>
//FINDING SQUARE ROOT
double mod(double k)
{
	if (k < 0)
        k = -k;
     	return k;
}

double root(float i)
{
   	double r = 1;

    	while(mod(r*r - i) > 0.00000000001 )
        r = ((i/r) + r) / 2;

    	return r;
}

int main()
{	
	float i;
	scanf("%f",&i);
    	printf("%.15lf\n", root(i));
    	return 0;
}


