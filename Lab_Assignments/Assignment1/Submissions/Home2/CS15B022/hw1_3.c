#include<stdio.h>
void main()
{
	int a;
	int b;
	scanf("%d",&a);
	scanf("%d",&b);
	int temp;
	if(b > a)
	{
		temp = a;
		a = b;
		b = temp;
	}
	int i;int temp1;
	for(i = 0;a%b != 0;i++)
	{	
		temp1 = a%b;
		a = b;
		b = temp1;
	}
	if(b%2 == 0)
		printf("2 ");
	int j;int k;
	for(j = 3;j < b;j++)
	{
		if(b%j == 0)
		{	
			k = 2;
			for(k = 2;k < j;k++)
			{
				if(j%k == 0)
				 break;
			}
			if(k == j)
			 printf("%d ",j);
		}
	}
}	

