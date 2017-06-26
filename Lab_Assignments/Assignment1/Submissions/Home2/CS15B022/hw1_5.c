#include<stdio.h>
void main()
{
	int n;
	scanf("%d",&n);
	double root = 50;
	int i = 0;
	for(i = 0;i<50;i++)
	{
		root = root - ((root*root-n)/(2*root));
		
			
	}
	printf("%.15lf",root);
}
