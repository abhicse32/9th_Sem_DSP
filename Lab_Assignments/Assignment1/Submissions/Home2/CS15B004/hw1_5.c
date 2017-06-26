#include<stdio.h>

int main()
{
										//f(x)=x^2-n
	int i=0,n;
	long double x0,x1;
	scanf("%d",&n);

	x0=1.0*(n+1)/2;
	while(i<30)
	{
		x1= 1.0*(x0*x0 + n) / (2*x0);    // newton ralphson method
		x0=x1;
		i++;
	}

	printf("%.15Lf",x1);
	return 0;
}