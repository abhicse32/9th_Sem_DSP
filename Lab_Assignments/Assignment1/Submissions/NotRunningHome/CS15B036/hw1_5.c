#include<stdio.h>
#include<math.h>
int main()
{
	int a;
	int i=0;
	scanf("%d",&a);
	double x;
	double y;
	x=((double)a)/2;
	y = (x + (((double)(a))/x))/2;
	
	while((x-y)>0.000000000000001)
	{
		    x=y;
			y = (x + (((double)(a))/x))/2;
			
			i++;
	}
	printf("%.15lf",y);
}
