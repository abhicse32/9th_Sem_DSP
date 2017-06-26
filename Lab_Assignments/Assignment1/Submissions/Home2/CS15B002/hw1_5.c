#include<stdio.h>
int main()
{
	double a,b;
	scanf("%lf",&a);
	b=(1+a)/2;	
	for(;((b*b-a)>0.00000000001)||((a-b*b)>0.00000000001);)
	{
		b=(b+(a/b))/2 ;
	}
	printf("%.15lf",b);
	return 0;
}
