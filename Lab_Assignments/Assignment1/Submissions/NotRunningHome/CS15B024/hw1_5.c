#include <stdio.h>
void main()
{
	long double a;
	long double b=0.0000000000000001;//the value of b is taken so small so that we can find value of a upto many decimal places
	int num;
	printf("enter a number");
	scanf("%d",&num);
	for(a=0;a<num;a=a+b)	//increments value of a until the square of a just exceeds num
	{
		if((a*a)>num)	//decrements that value of b from a as it exceeds the squareroot of num by b
		{
			a=a-b;
			break;
		}
	}
	printf("%.15lf",a);	//printing the squareroot of num upto 15 decimal places

}
	
