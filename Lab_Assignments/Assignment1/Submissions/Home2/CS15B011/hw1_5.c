												/*program to find square rot of a number by Akshay Kumar*/

#include<stdio.h>

void main()
{
	int a,i;											/*declaration of variables*/
	scanf("%d",&a);
	float x,k;
	float b[50];
	b[0]=1.0;
	for(i=1;i<50;i++)
	{
		b[i]=0.0;
	}
	for(i=1;i<50;i++)
	{
		b[i]=b[i-1]-(b[i-1]*b[i-1] - a)/(2*b[i-1]);
		k=b[i]-b[i-1];
		x=b[i];
		if(k<0.0001 && k>-0.0001) break;
	}
	printf("%.15f",x);
}

 

