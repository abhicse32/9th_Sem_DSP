#include<stdio.h>
int main()
{
	int i,j,n,max,min;
	printf("enter value of n");
	scanf("%d",&n);
	int a[n],b[n/2],c[n/2];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	min=b[0],max=c[0];
	if(n%2==0)
	{ 
		for(i=0;i<n;i=i+2)
		{
			if(a[i]<a[i+1]);
			{
			b[i]=a[i];
			c[i]=a[i+1];
			}
			 if(a[i]>a[i+1]);
			 {
			b[i]=a[i+1];
			c[i]=a[i];
			}	
		}
		for(i=0;i<n/2;i++)
		{
			if(min>b[i])
			{
				min=b[i];
			}
		}
		for(j=0;j<n/2;j++)
		{
			if(max<c[i])
			{
				max= c[i];	
			}
		}
	}
	if(n%2==1)
	{
	
		for(i=0;i<n-1;i=i+2)
		{
			if(a[i]<a[i+1]);
			{
			b[i]=a[i];
			c[i]=a[i+1];
			}
			if(a[i]>a[i+1]);
			{
			b[i]=a[i+1];
			c[i]=a[i];
			}
		}
		for(i=0;i<n/2;i++)
		{
			if(min>b[i])
			{
				min=b[i];
			}
		}
		for(i=0;i<n/2;i++)
		{
			if(max<c[i])
			{
				max= c[i];	
			}
		}
		if(max<a[n-1])
		{
			max=a[n-1];
		}
		 if(min>a[n-1]);
		{
			min=a[n-1];
		}
	}
	printf("%d%d",min,max);
}
		
	
			
		

