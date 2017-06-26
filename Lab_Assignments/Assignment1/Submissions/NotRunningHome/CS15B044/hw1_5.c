#include<stdio.h>
 double root(int n, double x1)
{
	 double x2;
	x2=(n+x1*x1)/(2*x1);
	if(x2-x1 >= 0.00000000000001 || x2-x1<=-0.00000000000001)
	return root(n,x2);
	else 
	return x2;
}
int main()
{
	int n;
	 double x1;
	scanf("%d",&n);
	x1=(float) n;
	x1=root(n,x1);
	printf("%.15f\n",x1);
	return 0;
}
