#include <stdio.h>
void main()
{
	long double a;
	long double b=0.0000000000000001;
	int num;
	scanf("%d",&num);
	for(a=0;a<num;a=a+b)	//Increments the value
	{
		if((a*a)>num)	//decrements the value
		{
			a=a-b;
			break;
		}
	}

	printf("%.15lf",a);
}
	
