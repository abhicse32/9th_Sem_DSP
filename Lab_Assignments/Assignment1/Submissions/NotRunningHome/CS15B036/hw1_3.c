#include<stdio.h>
#include<math.h>
int prime(int);
int main()
{
	int x;
	int y;
	int m;
	int i;
	scanf("%d%d",&x,&y);
	if(x<y)
	{
		m=y/2;
	}
	else
	{
	
	m=x/2;}
	for( i=2; i<=m;i++)
	{
		if((x%i==0)&&(y%i==0))
		{
			prime(i);
		}
	}
	return 0;
}
int prime(int n)
{
	int count=0;
	int i;
	for(i=1;i<n;i++)
	{
		if(n%i!=0)
		{
			count++;
		}
	}
	if(count==(n-2))
	{
		printf("%d ",n);
	}
}
